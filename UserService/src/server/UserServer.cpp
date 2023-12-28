#include "UserServer.h"

using namespace placeholders;

#define BUFF_SIZE 128

UserServer::UserServer(string ip, int port, std::string _url, std::string _user, std::string _passWord, std::string _databasename, int _port){
    ip_ = ip;
    port_ = port;
    channel_ = std::make_shared<lightrpc::RpcChannel>(lightrpc::Config::GetGlobalConfig()->m_rpc_servers_["zookeeper"].addr_);
    log_stub_ = std::make_shared<ik::LogServerRpc_Stub>(channel_.get());

    // 初始化http中要使用的数据库，数据库连接池(单例模式)
    MysqlConnPool::getInstance()->init(_url, _user, _passWord, _databasename, _port);
}

void UserServer::run()
{
    //初始化网络层
    muduo::net::InetAddress address(ip_.c_str(), port_);
    muduo::net::TcpServer server(&loop_, address, "UserServer");

    server.setMessageCallback(bind(&UserServer::msg_callback, this, _1, _2, _3));
    server.setConnectionCallback(bind(&UserServer::conn_callback, this, _1));

    //注册zookeeper节点
    ZKClient zk_client;
    zk_client.start();
    string server_path = "/UserService/server";
    char buffer[BUFF_SIZE] = {0};
    sprintf(buffer, "%s:%d", ip_.c_str(), port_);
    if (zk_client.create(server_path, buffer, strlen(buffer), ZOO_EPHEMERAL) == false)
    {
        NEWMESSAGE(ik::LogRequest, log_request);
        string name = "UserServer ";
        name += buffer;
        log_request->set_name(name);
        log_request->set_msg("zookeeper connect error!");
        google::protobuf::Empty em;
        // 相关辅助参数设置
        NEWRPCCONTROLLER(controller);
        controller->SetMsgId(lightrpc::MsgIDUtil::GenMsgID());
        controller->SetTimeout(10000);
        controller->SetProtocol(lightrpc::ProtocalType::TINYPB);
        // 远程调用，可以通过controller来进行相关的控制（如连接超时时间、错误、调用完成。。。）
        log_stub_->Log_ERROR(controller.get(), log_request.get(), &em, nullptr);
        // 执行业务逻辑
        if (controller->GetErrorCode() != 0){
            LOG_APPERROR("call rpc failed, request[%s], error code[%d], error info[%s]", log_request->ShortDebugString().c_str(), controller->GetErrorCode(), controller->GetInfo().c_str());
            return;
        }
        LOG_APPINFO("call rpc success, request[%s]", log_request->ShortDebugString().c_str());
    }
    else
    {
        NEWMESSAGE(ik::LogRequest, log_request);
        string name = "UserServer ";
        name += buffer;
        log_request->set_name(name);
        log_request->set_msg("zookeeper connect!");
        google::protobuf::Empty em;
        // 相关辅助参数设置
        NEWRPCCONTROLLER(controller);
        controller->SetMsgId(lightrpc::MsgIDUtil::GenMsgID());
        controller->SetTimeout(10000);
        controller->SetProtocol(lightrpc::ProtocalType::TINYPB);
        // 远程调用，可以通过controller来进行相关的控制（如连接超时时间、错误、调用完成。。。）
        log_stub_->Log_ERROR(controller.get(), log_request.get(), &em, nullptr);
        // 执行业务逻辑
        if (controller->GetErrorCode() != 0){
            LOG_APPERROR("call rpc failed, request[%s], error code[%d], error info[%s]", log_request->ShortDebugString().c_str(), controller->GetErrorCode(), controller->GetInfo().c_str());
            return;
        }
        LOG_APPINFO("call rpc success, request[%s]", log_request->ShortDebugString().c_str());
    }
    //开启事件循环
    server.setThreadNum(4);
    server.start();
    loop_.loop();
}

//连接事件回调函数
void UserServer::msg_callback(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp stamp)
{
    //反序列化由UserService传过来的序列化数据
    string message = buffer->retrieveAllAsString();
    ik_UserServer::Request request;
    request.ParseFromString(message);

    //登录业务
    if (request.type() == "Login")
    {
        // 反序列化数据得到 id、password
        ik_UserServer::LoginRequest login_request;
        login_request.ParseFromString(request.request());
        int id = login_request.id();
        string password = login_request.password();

        //执行具体的Login方法，执行成功is_success被设置为true
        ik_UserServer::LoginReponse login_response;
        if (Login(id, password) == true)
        {
            login_response.set_is_success(true);
        }
        else
        {
            login_response.set_is_success(false);
            ik_UserServer::ErrorMsg *msg = login_response.mutable_msg();
            msg->set_message("login error");
        }
        //序列化结果 并将结果返回
        string send = login_response.SerializeAsString();
        conn->send(send.c_str(), send.size());
    }
    else if (request.type() == "Register")  //注册业务
    {
        ik_UserServer::RegisterRequest register_request;
        register_request.ParseFromString(request.request());
        string name = register_request.name();
        string password = register_request.password();
        //cout<<name<<" "<<password<<endl;
        ik_UserServer::RegisterResponse register_response;
        int id = Register(name, password);
        if (id < 0)
        {
            register_response.set_is_success(false);
        }
        else
        {
            register_response.set_is_success(true);
            register_response.set_id(id);
        }
        string send = register_response.SerializeAsString();
        conn->send(send.c_str(), send.size());
    }
    else if (request.type() == "LoginOut")  //注销业务
    {
        ik_UserServer::LoginOutRequest out_request;
        out_request.ParseFromString(request.request());
        int id = out_request.id();

        LoginOut(id);
    }
    else //其他业务，这里是没有，所以向LogServer服务器打印一条日志信息
    {
        NEWMESSAGE(ik::LogRequest, log_request);
        log_request->set_name("UserServer");
        string message = "UserServer:";
        message += ip_.c_str();
        message += " not have this service!";
        log_request->set_msg(message);
        google::protobuf::Empty em;
        // 相关辅助参数设置
        NEWRPCCONTROLLER(controller);
        controller->SetMsgId(lightrpc::MsgIDUtil::GenMsgID());
        controller->SetTimeout(10000);
        controller->SetProtocol(lightrpc::ProtocalType::TINYPB);
        // 远程调用，可以通过controller来进行相关的控制（如连接超时时间、错误、调用完成。。。）
        log_stub_->Log_ERROR(controller.get(), log_request.get(), &em, nullptr);
        // 执行业务逻辑
        if (controller->GetErrorCode() != 0){
            LOG_APPERROR("call rpc failed, request[%s], error code[%d], error info[%s]", log_request->ShortDebugString().c_str(), controller->GetErrorCode(), controller->GetInfo().c_str());
            return;
        }
        LOG_APPINFO("call rpc success, request[%s]", log_request->ShortDebugString().c_str());
    }
}

//连接事件回调函数
void UserServer::conn_callback(const muduo::net::TcpConnectionPtr &conn)
{
    if (!conn->connected())
    {
        //和rpc client断开连接
        conn->shutdown();
    }
}

//登录
bool UserServer::Login(int id, string password)
{
    MYSQL *mysql = NULL;
    MysqlConn mysqlcon(&mysql, MysqlConnPool::getInstance());

    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "select * from User where id=%d and password='%s'", id, password.c_str());
    // 如果查询成功，返回0。如果出现错误，返回非0值
    int result = mysql_query(mysql, sql);
    //从表中检索完整的结果集
    MYSQL_RES *res = mysql_store_result(mysql);
    if (res == nullptr)
    {
        mysql_free_result(res);
        return false;
    }
    else
    {
        //释放结果，否则会失败
        mysql_free_result(res);
        //更新用户状态为在线
        memset(sql, 0, BUFF_SIZE);
        sprintf(sql, "update User set state='online' where id=%d;", id);
        // 如果查询成功，返回0。如果出现错误，返回非0值
        int result = mysql_query(mysql, sql);
        //从表中检索完整的结果集
        MYSQL_RES *res = mysql_store_result(mysql);
        if (res == nullptr)
        {
            NEWMESSAGE(ik::LogRequest, log_request);
            log_request->set_name("UserServer");
            log_request->set_msg(sql, strlen(sql));
            google::protobuf::Empty em;
            // 相关辅助参数设置
            NEWRPCCONTROLLER(controller);
            controller->SetMsgId(lightrpc::MsgIDUtil::GenMsgID());
            controller->SetTimeout(10000);
            controller->SetProtocol(lightrpc::ProtocalType::TINYPB);
            // 远程调用，可以通过controller来进行相关的控制（如连接超时时间、错误、调用完成。。。）
            log_stub_->Log_ERROR(controller.get(), log_request.get(), &em, nullptr);
            // 执行业务逻辑
            if (controller->GetErrorCode() != 0){
                LOG_APPERROR("call rpc failed, request[%s], error code[%d], error info[%s]", log_request->ShortDebugString().c_str(), controller->GetErrorCode(), controller->GetInfo().c_str());
            }
            LOG_APPINFO("call rpc success, request[%s]", log_request->ShortDebugString().c_str());

            return false;
        }
        return true;
    }
}

//注销
void UserServer::LoginOut(int id)
{
    //更新数据库User 状态为offline
    MYSQL *mysql = NULL;
    MysqlConn mysqlcon(&mysql, MysqlConnPool::getInstance());
    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "update User set state='offline' where id=%d", id);
    // 如果查询成功，返回0。如果出现错误，返回非0值
    int result = mysql_query(mysql, sql);
    //从表中检索完整的结果集
    MYSQL_RES *res = mysql_store_result(mysql);
}

//注册 成功返回注册的账户，失败返回-1
int UserServer::Register(string name, string password)
{
    MYSQL *mysql = NULL;
    MysqlConn mysqlcon(&mysql, MysqlConnPool::getInstance());
    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "insert into User(name,password) values('%s','%s')", name.c_str(), password.c_str());
    // 如果查询成功，返回0。如果出现错误，返回非0值
    int result = mysql_query(mysql, sql);
    //从表中检索完整的结果集
    MYSQL_RES *res = mysql_store_result(mysql);
    if (res == nullptr)
    {
        NEWMESSAGE(ik::LogRequest, log_request);
        log_request->set_name("UserServer");
        log_request->set_msg(sql, strlen(sql));
        google::protobuf::Empty em;
        // 相关辅助参数设置
        NEWRPCCONTROLLER(controller);
        controller->SetMsgId(lightrpc::MsgIDUtil::GenMsgID());
        controller->SetTimeout(10000);
        controller->SetProtocol(lightrpc::ProtocalType::TINYPB);
        // 远程调用，可以通过controller来进行相关的控制（如连接超时时间、错误、调用完成。。。）
        log_stub_->Log_ERROR(controller.get(), log_request.get(), &em, nullptr);
        // 执行业务逻辑
        if (controller->GetErrorCode() != 0){
            LOG_APPERROR("call rpc failed, request[%s], error code[%d], error info[%s]", log_request->ShortDebugString().c_str(), controller->GetErrorCode(), controller->GetInfo().c_str());
        }
        LOG_APPINFO("call rpc success, request[%s]", log_request->ShortDebugString().c_str());

        return false;
    }
    return mysql_insert_id(mysql);
}
