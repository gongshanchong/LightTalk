#include "Redis.h"

#include <iostream>
#include <lightrpc/net/tcp/net_addr.h>

// 初始化redis连接信息
RedisCli::RedisCli()
{
    std::string redis_addr = lightrpc::Config::GetGlobalConfig()->m_rpc_servers_["redis"].addr_->ToString();
    int split_pos = redis_addr.find(":");
    ip_ = redis_addr.substr(0, split_pos);
    port_ = atoi(redis_addr.substr(split_pos+1, redis_addr.size()).c_str());
}

// 释放连接
RedisCli::~RedisCli()
{
    redisFree(get_channel_);
    redisFree(set_channel_);
}

// 初始化get_channel、set_channel连接
bool RedisCli::connect()
{
    get_channel_ = redisConnect(ip_.c_str(), port_);
    if (get_channel_ == nullptr)
    {
        return false;
    }

    set_channel_ = redisConnect(ip_.c_str(), port_);
    if (set_channel_ == nullptr)
    {
        return false;
    }

    return true;
}

// 判断某个账号是否在线
bool RedisCli::is_exist(int id)
{
    if (get_host(id) == "")
    {
        return false;
    }
    else
    {
        return true;
    }
}

// 根据账户得到它上线的服务器
string RedisCli::get_host(int id)
{
    redisReply *reply = (redisReply *)redisCommand(get_channel_, "get %d", id, sizeof(id));
    if (reply == nullptr)
    {
        return "";
    }
    string result = reply->str;
    freeReplyObject(reply);

    return result;
}

// 设置账户及其登录的服务器
bool RedisCli::set_host(int id, string host)
{
    redisReply *reply = (redisReply *)redisCommand(set_channel_, "set %d %s", id, host.c_str());
    if (reply == nullptr)
    {
        return false;
    }
    return true;
}

// 删除用户的信息
bool RedisCli::del_host(int id)
{
    redisReply *reply = (redisReply *)redisCommand(set_channel_, "del %d",id);
    if (reply == nullptr)
    {
        return false;
    }
    return true;
}
