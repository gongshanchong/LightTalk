#pragma once
#include "../proto/LogServer.pb.h"
#include "../proto/UserServer.pb.h"

#include "ZooKeeperFow.h"
#include "MysqlConnPool.h"

#include <google/protobuf/empty.pb.h>
#include "../lightrpc/net/rpc/rpc_channel.h"

#include <muduo/net/TcpConnection.h>
#include <muduo/net/TcpServer.h>
#include <muduo/net/Buffer.h>
#include <muduo/net/EventLoop.h>
#include <muduo/base/Timestamp.h>


#include <string>
#include <memory>
#include <functional>

using namespace std;
class UserServer
{
public:
    UserServer(string ip, int port, std::string _url, std::string _user, std::string _passWord, std::string _databasename, int _port);

    //服务启动
    void run();

    //读写事件回调函数
    void msg_callback(const muduo::net::TcpConnectionPtr& conn,muduo::net::Buffer* buffer,muduo::Timestamp stamp);

    //连接事件回调函数
    void conn_callback(const muduo::net::TcpConnectionPtr& conn);
public:
    //登录
    bool Login(int id, string password);

    //注销
    void LoginOut(int id);

    //注册 成功返回注册的账户，失败返回-1
    int Register(string name, string password);

public:
    string ip_;
    int port_;

    muduo::net::EventLoop loop_;
    std::shared_ptr<lightrpc::RpcChannel> channel_;
    std::shared_ptr<ik::LogServerRpc_Stub> log_stub_;
};
