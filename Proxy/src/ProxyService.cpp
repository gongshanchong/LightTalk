#include "ProxyService.h"
#include <memory>

using namespace placeholders;

ProxyService::ProxyService(): master_("/ChatService"){
    msg_handler_map_.insert({"Login", bind(&ProxyService::Login, this, _1, _2, _3)});
    msg_handler_map_.insert({"Regist", bind(&ProxyService::Regist, this, _1, _2, _3)});
    msg_handler_map_.insert({"LoginOut", bind(&ProxyService::LoginOut, this, _1, _2, _3)});
    msg_handler_map_.insert({"OneChat", bind(&ProxyService::OneChat, this, _1, _2, _3)});
    msg_handler_map_.insert({"AddFriend", bind(&ProxyService::AddFriend, this, _1, _2, _3)});
    msg_handler_map_.insert({"DelteFriend", bind(&ProxyService::DeleteFriend, this, _1, _2, _3)});
    msg_handler_map_.insert({"GetUserInfo", bind(&ProxyService::GetUserInfo, this, _1, _2, _3)});
    msg_handler_map_.insert({"GetFriendList", bind(&ProxyService::GetFriendList, this, _1, _2, _3)});
    msg_handler_map_.insert({"ReadOfflineMsg", bind(&ProxyService::ReadOfflineMsg, this, _1, _2, _3)});
    msg_handler_map_.insert({"CreateGroup", bind(&ProxyService::CreateGroup, this, _1, _2, _3)});
    msg_handler_map_.insert({"QuitGroup", bind(&ProxyService::QuitGroup, this, _1, _2, _3)});
    msg_handler_map_.insert({"AddGroup", bind(&ProxyService::AddGroup, this, _1, _2, _3)});
    msg_handler_map_.insert({"ConveyMsg", bind(&ProxyService::ConveyMsg, this, _1, _2, _3)});
    msg_handler_map_.insert({"ChatMsg", bind(&ProxyService::ChatMsg, this, _1, _2, _3)});

    // 获取服务端通信
    channel_ = std::make_shared<lightrpc::RpcChannel>(lightrpc::Config::GetGlobalConfig()->m_rpc_servers_["zookeeper"].addr_);
    log_stub_ = std::make_shared<ik::LogServerRpc_Stub>(channel_.get());
    group_stub_ = std::make_shared<ik_GroupService::GroupServiceRpc_Stub>(channel_.get());
    user_stub_ = std::make_shared<ik_UserService::UserServiceRpc_Stub>(channel_.get());
    friend_stub_ = std::make_shared<ik_FriendService::FriendServiceRpc_Stub>(channel_.get());
    offline_stub_ = std::make_shared<ik_OfflineService::OfflineServiceRpc_Stub>(channel_.get());
}

// 登录
void ProxyService::Login(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    NEWMESSAGE(ik_UserService::LoginRequest, login_request);
    login_request->ParseFromString(recv_buf);

    //执行
    NEWMESSAGE(ik_UserService::LoginReponse, response);
    // 相关辅助参数设置
    NEWRPCCONTROLLER(controller);
    controller->SetMsgId(lightrpc::MsgIDUtil::GenMsgID());
    controller->SetTimeout(10000);
    controller->SetProtocol(lightrpc::ProtocalType::TINYPB);
    // 远程调用，可以通过controller来进行相关的控制（如连接超时时间、错误、调用完成。。。）
    user_stub_->Login(controller.get(), login_request.get(), response.get(), nullptr);
    // 执行业务逻辑
    if (controller->GetErrorCode() != 0){
        LOG_APPERROR("call rpc failed, request[%s], error code[%d], error info[%s]", login_request->ShortDebugString().c_str(), controller->GetErrorCode(), controller->GetInfo().c_str());
        conn->send(controller->GetInfo().c_str());
        return;
    }
    LOG_APPINFO("call rpc success, request[%s], response[%s]", login_request->ShortDebugString().c_str(), response->ShortDebugString().c_str());

    //在redis上记录此用户
    std::string redis_addr = lightrpc::Config::GetGlobalConfig()->m_rpc_servers_["redis"].addr_->ToString();
    int split_pos = redis_addr.find(":");
    string ip = redis_addr.substr(0, split_pos);
    int port = atoi(redis_addr.substr(split_pos+1, redis_addr.size()).c_str());
    redis_client_.set_host(login_request->id(), ip + ":" + to_string(port));

    //添加此用户到user map表中
    {
        lock_guard<mutex> lock(mutex_);
        use_connection_map_.insert({login_request->id(), conn});
    }

    //序列化并发送
    string send_str = response->SerializeAsString();
    conn->send(send_str);
}

//注册
void ProxyService::Regist(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    NEWMESSAGE(ik_UserService::RegisterRequest, regist_request);
    regist_request->ParseFromString(recv_buf);

    //执行
    NEWMESSAGE(ik_UserService::RegisterResponse, response);
    // 相关辅助参数设置
    NEWRPCCONTROLLER(controller);
    controller->SetMsgId(lightrpc::MsgIDUtil::GenMsgID());
    controller->SetTimeout(10000);
    controller->SetProtocol(lightrpc::ProtocalType::TINYPB);
    // 远程调用，可以通过controller来进行相关的控制（如连接超时时间、错误、调用完成。。。）
    user_stub_->Registe(controller.get(), regist_request.get(), response.get(), nullptr);
    // 执行业务逻辑
    if (controller->GetErrorCode() != 0){
        LOG_APPERROR("call rpc failed, request[%s], error code[%d], error info[%s]", regist_request->ShortDebugString().c_str(), controller->GetErrorCode(), controller->GetInfo().c_str());
        conn->send(controller->GetInfo().c_str());
        return;
    }
    LOG_APPINFO("call rpc success, request[%s], response[%s]", regist_request->ShortDebugString().c_str(), response->ShortDebugString().c_str());

    //序列化并发送
    string send_str = response->SerializeAsString();
    conn->send(send_str);
}

//注销业务
void ProxyService::LoginOut(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    NEWMESSAGE(ik_UserService::LoginOutRequest, request);
    request->ParseFromString(recv_buf);

    //执行
    // 相关辅助参数设置
    NEWRPCCONTROLLER(controller);
    controller->SetMsgId(lightrpc::MsgIDUtil::GenMsgID());
    controller->SetTimeout(10000);
    controller->SetProtocol(lightrpc::ProtocalType::TINYPB);
    // 远程调用，可以通过controller来进行相关的控制（如连接超时时间、错误、调用完成。。。）
    user_stub_->LoginOut(controller.get(), request.get(), nullptr, nullptr);
    // 执行业务逻辑
    if (controller->GetErrorCode() != 0){
        LOG_APPERROR("call rpc failed, request[%s], error code[%d], error info[%s]", request->ShortDebugString().c_str(), controller->GetErrorCode(), controller->GetInfo().c_str());
        conn->send(controller->GetInfo().c_str());
        return;
    }
    LOG_APPINFO("call rpc success, request[%s]", request->ShortDebugString().c_str());
}

//添加好友业务
void ProxyService::AddFriend(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    google::protobuf::Empty em;
    NEWMESSAGE(ik_FriendService::AddFriendRequest, request);
    request->ParseFromString(recv_buf);

    //执行
    // 相关辅助参数设置
    NEWRPCCONTROLLER(controller);
    controller->SetMsgId(lightrpc::MsgIDUtil::GenMsgID());
    controller->SetTimeout(10000);
    controller->SetProtocol(lightrpc::ProtocalType::TINYPB);
    // 远程调用，可以通过controller来进行相关的控制（如连接超时时间、错误、调用完成。。。）
    friend_stub_->AddFriend(controller.get(), request.get(), &em, nullptr);
    // 执行业务逻辑
    if (controller->GetErrorCode() != 0){
        LOG_APPERROR("call rpc failed, request[%s], error code[%d], error info[%s]", request->ShortDebugString().c_str(), controller->GetErrorCode(), controller->GetInfo().c_str());
        conn->send(controller->GetInfo().c_str());
        return;
    }
    LOG_APPINFO("call rpc success, request[%s]", request->ShortDebugString().c_str());
}

//删除好友
void ProxyService::DeleteFriend(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    google::protobuf::Empty em;
    NEWMESSAGE(ik_FriendService::DeleteFriendRequest, request);
    request->ParseFromString(recv_buf);

    //执行
    // 相关辅助参数设置
    NEWRPCCONTROLLER(controller);
    controller->SetMsgId(lightrpc::MsgIDUtil::GenMsgID());
    controller->SetTimeout(10000);
    controller->SetProtocol(lightrpc::ProtocalType::TINYPB);
    // 远程调用，可以通过controller来进行相关的控制（如连接超时时间、错误、调用完成。。。）
    friend_stub_->DeleteFriend(controller.get(), request.get(), &em, nullptr);
    // 执行业务逻辑
    if (controller->GetErrorCode() != 0){
        LOG_APPERROR("call rpc failed, request[%s], error code[%d], error info[%s]", request->ShortDebugString().c_str(), controller->GetErrorCode(), controller->GetInfo().c_str());
        conn->send(controller->GetInfo().c_str());
        return;
    }
    LOG_APPINFO("call rpc success, request[%s]", request->ShortDebugString().c_str());
}

//获取用户信息
void ProxyService::GetUserInfo(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    NEWMESSAGE(ik_FriendService::UserInfoRequest, request);
    request->ParseFromString(recv_buf);

    //执行
    NEWMESSAGE(ik_FriendService::UserInfoReponse, response);
    // 相关辅助参数设置
    NEWRPCCONTROLLER(controller);
    controller->SetMsgId(lightrpc::MsgIDUtil::GenMsgID());
    controller->SetTimeout(10000);
    controller->SetProtocol(lightrpc::ProtocalType::TINYPB);
    // 远程调用，可以通过controller来进行相关的控制（如连接超时时间、错误、调用完成。。。）
    friend_stub_->GetUserInfo(controller.get(), request.get(), response.get(), nullptr);
    // 执行业务逻辑
    if (controller->GetErrorCode() != 0){
        LOG_APPERROR("call rpc failed, request[%s], error code[%d], error info[%s]", request->ShortDebugString().c_str(), controller->GetErrorCode(), controller->GetInfo().c_str());
        conn->send(controller->GetInfo().c_str());
        return;
    }
    LOG_APPINFO("call rpc success, request[%s]", request->ShortDebugString().c_str());

    //序列化并返回结果
    string send_str = response->SerializeAsString();
    conn->send(send_str);
}

//获取好友列表
void ProxyService::GetFriendList(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    NEWMESSAGE(ik_FriendService::FriendListRequest, request);
    request->ParseFromString(recv_buf);

    //执行
    NEWMESSAGE(ik_FriendService::FriendListResponse, response);
    // 相关辅助参数设置
    NEWRPCCONTROLLER(controller);
    controller->SetMsgId(lightrpc::MsgIDUtil::GenMsgID());
    controller->SetTimeout(10000);
    controller->SetProtocol(lightrpc::ProtocalType::TINYPB);
    // 远程调用，可以通过controller来进行相关的控制（如连接超时时间、错误、调用完成。。。）
    friend_stub_->GetFriendList(controller.get(), request.get(), response.get(), nullptr);
    // 执行业务逻辑
    if (controller->GetErrorCode() != 0){
        LOG_APPERROR("call rpc failed, request[%s], error code[%d], error info[%s]", request->ShortDebugString().c_str(), controller->GetErrorCode(), controller->GetInfo().c_str());
        conn->send(controller->GetInfo().c_str());
        return;
    }
    LOG_APPINFO("call rpc success, request[%s]", request->ShortDebugString().c_str());

    //序列化并返回结果
    string send_str = response->SerializeAsString();
    conn->send(send_str);
}

//读取离线消息
void ProxyService::ReadOfflineMsg(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    NEWMESSAGE(ik_OfflineService::ReadOfflineRequest, request);
    request->ParseFromString(recv_buf);

    //执行
    NEWMESSAGE(ik_OfflineService::ReadOfflineResponse, response);
    // 相关辅助参数设置
    NEWRPCCONTROLLER(controller);
    controller->SetMsgId(lightrpc::MsgIDUtil::GenMsgID());
    controller->SetTimeout(10000);
    controller->SetProtocol(lightrpc::ProtocalType::TINYPB);
    // 远程调用，可以通过controller来进行相关的控制（如连接超时时间、错误、调用完成。。。）
    offline_stub_->ReadOffline(controller.get(), request.get(), response.get(), nullptr);
    // 执行业务逻辑
    if (controller->GetErrorCode() != 0){
        LOG_APPERROR("call rpc failed, request[%s], error code[%d], error info[%s]", request->ShortDebugString().c_str(), controller->GetErrorCode(), controller->GetInfo().c_str());
        conn->send(controller->GetInfo().c_str());
        return;
    }
    LOG_APPINFO("call rpc success, request[%s]", request->ShortDebugString().c_str());

    //序列化并返回结果
    string send_str = response->SerializeAsString();
    conn->send(send_str);
}

//创建 群组
void ProxyService::CreateGroup(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    NEWMESSAGE(ik_GroupService::CreateGroupRequest, request);
    request->ParseFromString(recv_buf);

    //执行
    NEWMESSAGE(ik_GroupService::CreateGroupResponse, response);
    // 相关辅助参数设置
    NEWRPCCONTROLLER(controller);
    controller->SetMsgId(lightrpc::MsgIDUtil::GenMsgID());
    controller->SetTimeout(10000);
    controller->SetProtocol(lightrpc::ProtocalType::TINYPB);
    // 远程调用，可以通过controller来进行相关的控制（如连接超时时间、错误、调用完成。。。）
    group_stub_->CreateGroup(controller.get(), request.get(), response.get(), nullptr);
    // 执行业务逻辑
    if (controller->GetErrorCode() != 0){
        LOG_APPERROR("call rpc failed, request[%s], error code[%d], error info[%s]", request->ShortDebugString().c_str(), controller->GetErrorCode(), controller->GetInfo().c_str());
        conn->send(controller->GetInfo().c_str());
        return;
    }
    LOG_APPINFO("call rpc success, request[%s]", request->ShortDebugString().c_str());

    //序列化并返回结果
    string send_str = response->SerializeAsString();
    conn->send(send_str);
}

//加入群组
void ProxyService::AddGroup(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    google::protobuf::Empty em;
    NEWMESSAGE(ik_GroupService::AddGroupRequest, request);
    request->ParseFromString(recv_buf);

    //执行
    // 相关辅助参数设置
    NEWRPCCONTROLLER(controller);
    controller->SetMsgId(lightrpc::MsgIDUtil::GenMsgID());
    controller->SetTimeout(10000);
    controller->SetProtocol(lightrpc::ProtocalType::TINYPB);
    // 远程调用，可以通过controller来进行相关的控制（如连接超时时间、错误、调用完成。。。）
    group_stub_->AddGroup(controller.get(), request.get(), &em, nullptr);
    // 执行业务逻辑
    if (controller->GetErrorCode() != 0){
        LOG_APPERROR("call rpc failed, request[%s], error code[%d], error info[%s]", request->ShortDebugString().c_str(), controller->GetErrorCode(), controller->GetInfo().c_str());
        conn->send(controller->GetInfo().c_str());
        return;
    }
    LOG_APPINFO("call rpc success, request[%s]", request->ShortDebugString().c_str());
}

//退出群
void ProxyService::QuitGroup(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    google::protobuf::Empty em;
    NEWMESSAGE(ik_GroupService::QuitGroupRequest, request);
    request->ParseFromString(recv_buf);

    //执行
    // 相关辅助参数设置
    NEWRPCCONTROLLER(controller);
    controller->SetMsgId(lightrpc::MsgIDUtil::GenMsgID());
    controller->SetTimeout(10000);
    controller->SetProtocol(lightrpc::ProtocalType::TINYPB);
    // 远程调用，可以通过controller来进行相关的控制（如连接超时时间、错误、调用完成。。。）
    group_stub_->QuitGroup(controller.get(), request.get(), &em, nullptr);
    // 执行业务逻辑
    if (controller->GetErrorCode() != 0){
        LOG_APPERROR("call rpc failed, request[%s], error code[%d], error info[%s]", request->ShortDebugString().c_str(), controller->GetErrorCode(), controller->GetInfo().c_str());
        conn->send(controller->GetInfo().c_str());
        return;
    }
    LOG_APPINFO("call rpc success, request[%s]", request->ShortDebugString().c_str());
}

//获得群用户信息
void ProxyService::GetGroupUsers(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    NEWMESSAGE(ik_GroupService::GetGroupUsersRequest, request);
    request->ParseFromString(recv_buf);

    //执行
    NEWMESSAGE(ik_GroupService::GetGroupUsersResponse, response);
    // 相关辅助参数设置
    NEWRPCCONTROLLER(controller);
    controller->SetMsgId(lightrpc::MsgIDUtil::GenMsgID());
    controller->SetTimeout(10000);
    controller->SetProtocol(lightrpc::ProtocalType::TINYPB);
    // 远程调用，可以通过controller来进行相关的控制（如连接超时时间、错误、调用完成。。。）
    group_stub_->GetGroupUsers(controller.get(), request.get(), response.get(), nullptr);
    // 执行业务逻辑
    if (controller->GetErrorCode() != 0){
        LOG_APPERROR("call rpc failed, request[%s], error code[%d], error info[%s]", request->ShortDebugString().c_str(), controller->GetErrorCode(), controller->GetInfo().c_str());
        conn->send(controller->GetInfo().c_str());
        return;
    }
    LOG_APPINFO("call rpc success, request[%s]", request->ShortDebugString().c_str());

    //序列化并返回结果
    string send_str = response->SerializeAsString();
    conn->send(send_str);
}

//转发而来的消息
void ProxyService::ConveyMsg(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    ik_ChatServer::MsgRequest request;
    request.ParseFromString(recv_buf);

    ik_Proxy::PoxryResponse response;
    response.set_type("ChatMsg");
    response.set_response_msg(request.msg());

    int id = request.id();
    {
        lock_guard<mutex> lock(mutex_);
        auto it = use_connection_map_.find(id);
        muduo::net::TcpConnectionPtr client_conn = it->second;
        client_conn->send(response.SerializeAsString());
    }
}

//聊天消息
void ProxyService::ChatMsg(const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time)
{
    //反序列化
    ik_ChatServer::MsgRequest request;
    request.ParseFromString(recv_buf);

    int id = request.id();
    auto it = use_connection_map_.find(id);
    //不在此服务器上
    if (it == use_connection_map_.end())
    {
        //刷新服务器连接
        master_.get_follow();
        //获取一个与转发服务器交互的可以连接
        int client_fd;
        while ((client_fd = master_.get_service()) == -1)
        {
            master_.get_follow();
            sleep(1);
        }

        send(client_fd, recv_buf.c_str(), recv_buf.size(), 0);
    }
    else
    {
        it->second->send(recv_buf);
    }
}

//获得消息对应的处理器
MsgHandler ProxyService::GetHandler(string msg_type)
{
    //记录错误日志，msgid没有对应的事件处理回调
    auto it = msg_handler_map_.find(msg_type);
    //如果没有对应的msgid
    if (it == msg_handler_map_.end())
    {
        //返回一个默认处理器，打印错误日志
        NEWMESSAGE(ik::LogRequest, request);
        request->set_name("ProxyService");
        request->set_msg("have this service: " + msg_type);
        google::protobuf::Empty em;
        // 相关辅助参数设置
        NEWRPCCONTROLLER(controller);
        controller->SetMsgId(lightrpc::MsgIDUtil::GenMsgID());
        controller->SetTimeout(10000);
        controller->SetProtocol(lightrpc::ProtocalType::TINYPB);
        // 远程调用，可以通过controller来进行相关的控制（如连接超时时间、错误、调用完成。。。）
        log_stub_->Log_ERROR(controller.get(), request.get(), &em, nullptr);
        // 执行业务逻辑
        if (controller->GetErrorCode() != 0){
            LOG_APPERROR("call rpc failed, request[%s], error code[%d], error info[%s]", request->ShortDebugString().c_str(), controller->GetErrorCode(), controller->GetInfo().c_str());
        }
        LOG_APPINFO("call rpc success, request[%s]", request->ShortDebugString().c_str());

        return [=](const muduo::net::TcpConnectionPtr &conn, string &recv_buf, muduo::Timestamp time) {
        };
    }
    else
    {
        return msg_handler_map_[msg_type];
    }
}

//处理客户端异常退出
void ProxyService::ClientCloseException(const muduo::net::TcpConnectionPtr &conn)
{
    //1.删除user_map    2.用户改为offline   3.线程安全 4.删除redis上的信息
    {
        lock_guard<mutex> lock(mutex_);
        for (auto it = use_connection_map_.begin(); it != use_connection_map_.end(); it++)
        {
            if (it->second == conn)
            {
                redis_client_.del_host(it->first);
                it = use_connection_map_.erase(it);
                break;
            }
        }
    }
}

//服务器异常，业务重置
void ProxyService::Reset()
{
    //序列化客户端收到的语句
    NEWMESSAGE(ik_Proxy::PoxryResponse, response);    
    response->set_type("LoginOut");
    response->set_response_msg("server crash");
    string send_str = response->SerializeAsString();

    {
        lock_guard<mutex> lock(mutex_);
        //重置所有用户为下线状态
        NEWMESSAGE(ik_UserService::LoginOutRequest, request);    
        for (auto it = use_connection_map_.begin(); it != use_connection_map_.end(); it++)
        {
            request->set_id(it->first);

            //在redis上删除用户
            redis_client_.del_host(it->first);
            google::protobuf::Empty em;
            // 相关辅助参数设置
            NEWRPCCONTROLLER(controller);
            controller->SetMsgId(lightrpc::MsgIDUtil::GenMsgID());
            controller->SetTimeout(10000);
            controller->SetProtocol(lightrpc::ProtocalType::TINYPB);
            // 远程调用，可以通过controller来进行相关的控制（如连接超时时间、错误、调用完成。。。）
            user_stub_->LoginOut(controller.get(), request.get(), &em, nullptr);
            // 执行业务逻辑
            if (controller->GetErrorCode() != 0){
                LOG_APPERROR("call rpc failed, request[%s], error code[%d], error info[%s]", request->ShortDebugString().c_str(), controller->GetErrorCode(), controller->GetInfo().c_str());
            }
            LOG_APPINFO("call rpc success, request[%s]", request->ShortDebugString().c_str());

            it->second->send(send_str);
        }
    }
    //清空map
    use_connection_map_.clear();
}
