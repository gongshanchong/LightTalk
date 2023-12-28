#include "../proto/LogServer.pb.h"
#include "../proto/GroupServer.pb.h"
#include "../proto/GroupService.pb.h"

#include "../interface/add_group.h"
#include "../interface/create_group.h"
#include "../interface/get_group_users.h"
#include "../interface/quit_group.h"
#include "ZooKeeperMaster.h"

#include <google/protobuf/service.h>
#include "../lightrpc/net/rpc/rpc_channel.h"

#include <string>

using namespace std;

class GroupService : public ik_ChatService::GroupServiceRpc
{
public:
    GroupService(){
        ZKMatser::getInstance()->init("/GroupService");
        ZKMatser::getInstance()->start();
    }

public:
    void AddGroup(::google::protobuf::RpcController *controller,
                  const ::ik_ChatService::AddGroupRequest *request,
                  ::google::protobuf::Empty *response,
                  ::google::protobuf::Closure *done){
                    std::shared_ptr<AddGroupImpl> impl = std::make_shared<AddGroupImpl>(request, response, controller, done);
                    impl->Run();
                  }
    void CreateGroup(::google::protobuf::RpcController *controller,
                     const ::ik_ChatService::CreateGroupRequest *request,
                     ::ik_ChatService::CreateGroupResponse *response,
                     ::google::protobuf::Closure *done){
                        std::shared_ptr<CreateGroupImpl> impl = std::make_shared<CreateGroupImpl>(request, response, controller, done);
                        impl->Run();
                    }
    void QuitGroup(::google::protobuf::RpcController *controller,
                   const ::ik_ChatService::QuitGroupRequest *request,
                   ::google::protobuf::Empty *response,
                   ::google::protobuf::Closure *done){
                        std::shared_ptr<GetGroupUsersImpl> impl = std::make_shared<GetGroupUsersImpl>(request, response, controller, done);
                        impl->Run();
                   }
    void GetGroupUsers(::google::protobuf::RpcController *controller,
                       const ::ik_ChatService::GetGroupUsersRequest *request,
                       ::ik_ChatService::GetGroupUsersResponse *response,
                       ::google::protobuf::Closure *done){
                        std::shared_ptr<QuitGroupImpl> impl = std::make_shared<QuitGroupImpl>(request, response, controller, done);
                        impl->Run();
                    }

};