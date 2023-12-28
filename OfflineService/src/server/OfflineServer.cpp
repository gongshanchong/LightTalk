#include "OfflineServer.h"

#define BUFF_SIZE 128

using namespace placeholders;

//初始化配置等信息
OfflineServer::OfflineServer(string ip, int port, std::string _url, std::string _user, std::string _passWord, std::string _databasename, int _port)
{
    ip_ = ip;
    port_ = port;

    // 初始化http中要使用的数据库，数据库连接池(单例模式)
    MysqlConnPool::getInstance()->init(_url, _user, _passWord, _databasename, _port);
}

//开始服务
void OfflineServer::run()
{
    muduo::net::InetAddress address(ip_, port_);
    muduo::net::TcpServer server(&loop_, address, "OfflineServer");

    // 注册zookeeper节点
    ZKClient client;
    client.start();
    string server_path = "/OfflineService/server";
    char data[BUFF_SIZE] = {0};
    sprintf(data, "%s:%d", ip_.c_str(), port_);
    client.create(server_path, data, strlen(data), ZOO_EPHEMERAL);

    //绑定回调函数
    server.setMessageCallback(bind(&OfflineServer::on_message, this, _1, _2, _3));
    server.setConnectionCallback(bind(&OfflineServer::on_connect, this, _1));

    server.setThreadNum(4);
    server.start();
    loop_.loop();
}

//读写事件回调函数
void OfflineServer::on_message(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp stamp)
{
    string recv = buffer->retrieveAllAsString();
    ik_OfflineServer::Request request;
    request.ParseFromString(recv);
    if (request.type() == "WriteOffline")
    {
        //反序列化
        ik_OfflineServer::WriteOfflineRequest write_request;
        write_request.ParseFromString(request.request_msg());
        int friend_id = write_request.friend_id();
        string msg = write_request.msg();
        //写入数据库
        write_offlineMsg(friend_id, msg);
    }
    else if (request.type() == "ReadOffline")
    {
        //反序列化
        ik_OfflineServer::WriteOfflineRequest write_request;
        write_request.ParseFromString(request.request_msg());
        int userid = write_request.friend_id();

        //执行业务
        vector<string> offline_msg = read_offlineMsg(userid);

        //序列化
        ik_OfflineServer::ReadOfflineResponse response;
        for (int i = 0; i < offline_msg.size(); i++)
        {
            response.add_msg(offline_msg[i]);
        }
        //信息发送
        string send = response.SerializeAsString();
        conn->send(send);
    }
}

//连接事件回调函数
void OfflineServer::on_connect(const muduo::net::TcpConnectionPtr &conn)
{
    //断开连接
    if (!conn->connected())
    {
        conn->shutdown();
    }
}

//写离线消息
bool OfflineServer::write_offlineMsg(int friend_id, string msg)
{
    //获取连接池连接
    MYSQL *mysql = NULL;
    MysqlConn mysqlcon(&mysql, MysqlConnPool::getInstance());

    //组织sql语句并执行
    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "insert into OfflineMessage values(%d,'%s')", friend_id, msg.c_str());
    return mysql_query(mysql, sql);
}
//读离线消息
vector<string> OfflineServer::read_offlineMsg(int myid)
{
    //获取连接池连接
    MYSQL *mysql = NULL;
    MysqlConn mysqlcon(&mysql, MysqlConnPool::getInstance());

    //组织sql语句并执行
    char sql[BUFF_SIZE] = {0};
    sprintf(sql, "select message from OfflineMessage where userid=%d", myid);
    // 如果查询成功，返回0。如果出现错误，返回非0值
    int result = mysql_query(mysql, sql);
    //从表中检索完整的结果集
    MYSQL_RES *res = mysql_store_result(mysql);
    MYSQL_ROW row;

    vector<string> ret;
    while ((row = mysql_fetch_row(res)))
    {
        ret.push_back(row[0]);
    }

    mysql_free_result(res);

    //删除原来的离线消息
    memset(sql, 0, BUFF_SIZE);
    sprintf(sql, "delete from OfflineMessage where userid=%d", myid);
    mysql_query(mysql, sql);
    return ret;
}
