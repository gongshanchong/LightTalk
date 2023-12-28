#pragma once

#include "../proto/LogServer.pb.h"
#include "../proto/FriendServer.pb.h"
#include "../proto/FriendService.pb.h"
#include "ZooKeeperMaster.h"

#include "../interface/add_friend.h"
#include "../interface/delete_friend.h"
#include "../interface/get_friend_list.h"
#include "../interface/get_user_info.h"

#include <google/protobuf/empty.pb.h>
#include <google/protobuf/service.h>
#include "../lightrpc/net/rpc/rpc_channel.h"

#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <string>

using namespace std;

class FriendService : public ik_FriendService::FriendServiceRpc
{
public:
    FriendService(){
        ZKMatser::getInstance()->init("/FriendService");
        ZKMatser::getInstance()->start();
    }

public:
    //获取好友列表
    void GetFriendList(::google::protobuf::RpcController *controller,
                       const ::ik_FriendService::FriendListRequest *request,
                       ::ik_FriendService::FriendListResponse *response,
                       ::google::protobuf::Closure *done){
                        std::shared_ptr<GetFriendListImpl> impl = std::make_shared<GetFriendListImpl>(request, response, controller, done);
                        impl->Run();
                       }

    //获得用户信息
    void GetUserInfo(::google::protobuf::RpcController *controller,
                     const ::ik_FriendService::UserInfoRequest *request,
                     ::ik_FriendService::UserInfoReponse *response,
                     ::google::protobuf::Closure *done){
                        std::shared_ptr<GetUserInfoImpl> impl = std::make_shared<GetUserInfoImpl>(request, response, controller, done);
                        impl->Run();
                     }

    //添加好友
    void AddFriend(::google::protobuf::RpcController *controller,
                   const ::ik_FriendService::AddFriendRequest *request,
                   ::google::protobuf::Empty *response,
                   ::google::protobuf::Closure *done){
                        std::shared_ptr<AddFriendImpl> impl = std::make_shared<AddFriendImpl>(request, response, controller, done);
                        impl->Run();
                   }

    //删除好友
    void DeleteFriend(::google::protobuf::RpcController *controller,
                      const ::ik_FriendService::DeleteFriendRequest *request,
                      ::google::protobuf::Empty *response,
                      ::google::protobuf::Closure *done){
                        std::shared_ptr<DeleteFriendImpl> impl = std::make_shared<DeleteFriendImpl>(request, response, controller, done);
                        impl->Run();
                      }
};