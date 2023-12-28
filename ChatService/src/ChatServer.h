#pragma once

#include "ZooKeeperFow.h"
#include "Redis.h"
#include "./proto/LogServer.pb.h"
#include "./proto/ChatServer.pb.h"
#include "./proto/ProxyServer.pb.h"
#include "./proto/OfflineService.pb.h"

#include <google/protobuf/empty.pb.h>
#include "../lightrpc/net/rpc/rpc_channel.h"

#include <muduo/net/EventLoop.h>
#include <muduo/net/Buffer.h>
#include <muduo/net/TcpServer.h>
#include <muduo/base/Timestamp.h>
#include <muduo/net/TcpConnection.h>

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <unordered_map>
#include <functional>
#include <string>

using namespace std;
class ChatServer
{
public:
    ChatServer(string redis_ip, int redis_port);

    //开启服务
    void run(string ip, int port);

    //连接事件回调函数
    void on_message(const muduo::net::TcpConnectionPtr &conn, muduo::net::Buffer *buffer, muduo::Timestamp stamp);

    //连接事件回调函数
    void on_connect(const muduo::net::TcpConnectionPtr &conn);

    //根据host建立连接
    int establish_connection(string host);

private:
    ZKClient zk_client_;
    RedisCli redis_client_;

    muduo::net::EventLoop loop_;

    //存储抽象服务节点chatservice及与其连接对应的socket
    unordered_map<string, int> con_map_;

    std::shared_ptr<lightrpc::RpcChannel> channel_;
    std::shared_ptr<ik::LogServerRpc_Stub> stub_;
    std::shared_ptr<ik_OfflineService::OfflineServiceRpc_Stub> offline_stub_;
};