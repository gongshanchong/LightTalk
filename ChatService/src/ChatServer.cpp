#include "ChatServer.h"

#include <iostream>
using namespace placeholders;

#define BUFF_SIZE 128

ChatServer::ChatServer(string redis_ip, int redis_port) : redis_client_(redis_ip, redis_port)
{
    channel_ = std::make_shared<lightrpc::RpcChannel>(lightrpc::Config::GetGlobalConfig()->m_rpc_servers_["zookeeper"].addr_);
    stub_ = std::make_shared<ik::LogServerRpc_Stub>(channel_.get());
    offline_stub_ = std::make_shared<ik_OfflineService::OfflineServiceRpc_Stub>(channel_.get());
}

//开启服务
void ChatServer::run(string ip, int port)
{
    //初始化服务器信息
    muduo::net::InetAddress address(ip, port);
    muduo::net::TcpServer server(&loop_, address, "ChatServer");

    // 设置回调函数
    server.setMessageCallback(bind(&ChatServer::on_message, this, _1, _2, _3));
    server.setConnectionCallback(bind(&ChatServer::on_connect, this, _1));
    server.setThreadNum(4);

    //连接redis服务器
    redis_client_.connect();

    //初始化zookeeper配置中心并注册节点
    zk_client_.start();
    string zk_path = "/ChatService/server";
    string zk_data = ip + ":" + to_string(port);
    zk_client_.create(zk_path, zk_path.c_str(), zk_path.size(), ZOO_EPHEMERAL);

    //开启muduo服务
    server.start();
    loop_.loop();
}

//连接事件回调函数
void ChatServer::on_message(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp stamp)
{
    //反序列化
    string recv_str = buffer->retrieveAllAsString();
    ik_ChatServer::MsgRequest request;
    request.ParseFromString(recv_str);

    //得到用户登录的ip地址
    string host = redis_client_.get_host(request.id());
    //如果当前用户没登陆,写入离线消息
    if (host == "")
    {
        NEWMESSAGE(ik_OfflineService::WriteOfflineRequest, write_request);
        write_request->set_friend_id(request.id());
        write_request->set_msg(request.msg());
        google::protobuf::Empty em;
        // 相关辅助参数设置
        NEWRPCCONTROLLER(controller);
        controller->SetMsgId(lightrpc::MsgIDUtil::GenMsgID());
        controller->SetTimeout(10000);
        controller->SetProtocol(lightrpc::ProtocalType::TINYPB);
        // 远程调用，可以通过controller来进行相关的控制（如连接超时时间、错误、调用完成。。。）
        offline_stub_->WriteOffline(controller.get(), write_request.get(), &em, nullptr);
        // 执行业务逻辑
        if (controller->GetErrorCode() != 0){
            LOG_APPERROR("call rpc failed, request[%s], error code[%d], error info[%s]", write_request->ShortDebugString().c_str(), controller->GetErrorCode(), controller->GetInfo().c_str());
            return;
        }
        LOG_APPINFO("call rpc success, request[%s]", write_request->ShortDebugString().c_str());

        return;
    }

    auto it = con_map_.find(host);
    if (it == con_map_.end()) //记录里面没有这个链接
    {
        int cliend_fd = establish_connection(host);
        con_map_[host] = cliend_fd;
    }

    //序列化
    NEWMESSAGE(ik_Proxy::PoxryMessage, poxry_request);
    poxry_request->set_type("ConveyMsg");
    poxry_request->set_request_msg(recv_str);

    string send_str = poxry_request->SerializeAsString();
    //转发此信息
    auto channel = con_map_.find(host);
    int fd = channel->second;
    if (send(fd, send_str.c_str(), send_str.size(), 0) == -1)
    {
        //打印错误日志
        NEWMESSAGE(ik::LogRequest, log_request);
        log_request->set_name("ChatServer " + host);
        char error_buffer[BUFF_SIZE] = {0};
        sprintf(error_buffer, "send error ,errno:%d", errno);
        log_request->set_msg(error_buffer);
        google::protobuf::Empty em;
        // 相关辅助参数设置
        NEWRPCCONTROLLER(controller);
        controller->SetMsgId(lightrpc::MsgIDUtil::GenMsgID());
        controller->SetTimeout(10000);
        controller->SetProtocol(lightrpc::ProtocalType::TINYPB);
        // 远程调用，可以通过controller来进行相关的控制（如连接超时时间、错误、调用完成。。。）
        stub_->Log_ERROR(controller.get(), log_request.get(), &em, nullptr);
        // 执行业务逻辑
        if (controller->GetErrorCode() != 0){
            LOG_APPERROR("call rpc failed, request[%s], error code[%d], error info[%s]", log_request->ShortDebugString().c_str(), controller->GetErrorCode(), controller->GetInfo().c_str());
            return;
        }
        LOG_APPINFO("call rpc success, request[%s]", log_request->ShortDebugString().c_str());
    }
}

//连接事件回调函数
void ChatServer::on_connect(const muduo::net::TcpConnectionPtr &conn)
{
    //关闭连接
    if (!conn->connected())
    {
        conn->shutdown();
    }
}

//根据host建立连接
int ChatServer::establish_connection(string host)
{
    //解析ip和port
    int index = host.find(":");
    string ip = host.substr(0, index);
    int port = atoi(host.substr(index + 1, host.size() - index).c_str());

    //创建socket
    int client_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_fd == -1)
    {
        //打印错误日志
        NEWMESSAGE(ik::LogRequest, log_request);
        log_request->set_name("ChatServer " + host);
        log_request->set_msg("create client fd error");
        google::protobuf::Empty em;
        // 相关辅助参数设置
        NEWRPCCONTROLLER(controller);
        controller->SetMsgId(lightrpc::MsgIDUtil::GenMsgID());
        controller->SetTimeout(10000);
        controller->SetProtocol(lightrpc::ProtocalType::TINYPB);
        // 远程调用，可以通过controller来进行相关的控制（如连接超时时间、错误、调用完成。。。）
        stub_->Log_ERROR(controller.get(), log_request.get(), &em, nullptr);
        // 执行业务逻辑
        if (controller->GetErrorCode() != 0){
            LOG_APPERROR("call rpc failed, request[%s], error code[%d], error info[%s]", log_request->ShortDebugString().c_str(), controller->GetErrorCode(), controller->GetInfo().c_str());
        }
        LOG_APPINFO("call rpc success, request[%s]", log_request->ShortDebugString().c_str());

        close(client_fd);
        return -1;
    }

    //配置服务器信息
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip.c_str());

    //连接
    if (connect(client_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
    {
        //打印错误日志
        NEWMESSAGE(ik::LogRequest, log_request);
        log_request->set_name("ChatServer " + host);
        log_request->set_msg("establish connect error");
        google::protobuf::Empty em;
        // 相关辅助参数设置
        NEWRPCCONTROLLER(controller);
        controller->SetMsgId(lightrpc::MsgIDUtil::GenMsgID());
        controller->SetTimeout(10000);
        controller->SetProtocol(lightrpc::ProtocalType::TINYPB);
        // 远程调用，可以通过controller来进行相关的控制（如连接超时时间、错误、调用完成。。。）
        stub_->Log_ERROR(controller.get(), log_request.get(), &em, nullptr);
        // 执行业务逻辑
        if (controller->GetErrorCode() != 0){
            LOG_APPERROR("call rpc failed, request[%s], error code[%d], error info[%s]", log_request->ShortDebugString().c_str(), controller->GetErrorCode(), controller->GetInfo().c_str());
        }
        LOG_APPINFO("call rpc success, request[%s]", log_request->ShortDebugString().c_str());

        close(client_fd);
        return -1;
    }
    return client_fd;
}