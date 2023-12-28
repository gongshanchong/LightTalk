#pragma once

#include "./proto/LogServer.pb.h"
#include "./proto/ChatServer.pb.h"
#include "./proto/UserService.pb.h"
#include "./proto/FriendService.pb.h"
#include "./proto/GroupService.pb.h"
#include "./proto/OfflineService.pb.h"

#include "Redis.h"
#include "ProxyServer.h"
#include "ZooKeeperMaster.h"

#include "../lightrpc/net/rpc/rpc_channel.h"

#include <unordered_map>
#include <functional>
#include <string>
#include <mutex>

using namespace std;
using MsgHandler = function<void(const muduo::net::TcpConnectionPtr &conn, string &recv_str, muduo::Timestamp time)>;

//单例设计
class ProxyService
{
public:
    static ProxyService &get_instance()
    {
        static ProxyService service;
        return service;
    }

public:
    // 登录
    void Login(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    // 注册
    void Regist(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    // 注销业务
    void LoginOut(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    // 一对一聊天业务
    void OneChat(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    // 添加好友业务
    void AddFriend(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    // 删除好友
    void DeleteFriend(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    // 获取用户信息
    void GetUserInfo(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    // 获取好友列表
    void GetFriendList(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    // 读取离线消息
    void ReadOfflineMsg(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    // 创建群组
    void CreateGroup(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    // 加入群组
    void AddGroup(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    // 退出群
    void QuitGroup(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    // 获得群用户信息
    void GetGroupUsers(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    // 聊天消息
    void ChatMsg(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

    // 转发而来的消息
    void ConveyMsg(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time);

public:
    // 获得消息对应的处理器
    MsgHandler GetHandler(string msg_type);

    // 处理客户端异常退出
    void ClientCloseException(const muduo::net::TcpConnectionPtr &conn);

    // 服务器异常，业务重置
    void Reset();

private:
    ProxyService();

private:
    ProxyService(const ProxyService &) = delete;
    ProxyService &operator=(ProxyService &) = delete;

private:
    unordered_map<string, MsgHandler> msg_handler_map_; // 存储事件及事件对应的回调函数

    unordered_map<int, muduo::net::TcpConnectionPtr> use_connection_map_; // 存储登录用户，及对应tcpptr信息
    mutex mutex_;                                                         // 保护上一个的线程安全
private:
    RedisCli redis_client_; // 连接redis服务器

    ZKMatser master_; // 连接zookeeper服务器
private:
    std::shared_ptr<lightrpc::RpcChannel> channel_;
    std::shared_ptr<ik_GroupService::GroupServiceRpc_Stub> group_stub_;
    std::shared_ptr<ik_UserService::UserServiceRpc_Stub> user_stub_;
    std::shared_ptr<ik_FriendService::FriendServiceRpc_Stub> friend_stub_;
    std::shared_ptr<ik_OfflineService::OfflineServiceRpc_Stub> offline_stub_;
    std::shared_ptr<ik::LogServerRpc_Stub> log_stub_;
};