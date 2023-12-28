#pragma once
#include "../proto/LogServer.pb.h"
#include "../proto/UserService.pb.h"
#include "../proto/UserServer.pb.h"
#include "ZooKeeperMaster.h"

#include "../interface/login.h"
#include "../interface/loginout.h"
#include "../interface/register.h"

#include <mysql/mysql.h>
#include "../lightrpc/net/rpc/rpc_channel.h"
#include <google/protobuf/service.h>
#include <string>

using namespace std;

class UserService : public ik_UserService::UserServiceRpc
{
public:
    UserService(){
        ZKMatser::getInstance()->init("/UserService");
        ZKMatser::getInstance()->start();
    }

public:
    void Login(::google::protobuf::RpcController *controller,
               const ::ik_UserService::LoginRequest *request,
               ::ik_UserService::LoginReponse *response,
               ::google::protobuf::Closure *done){
                    std::shared_ptr<LoginImpl> impl = std::make_shared<LoginImpl>(request, response, controller, done);
                    impl->Run();
               }
    void Registe(::google::protobuf::RpcController *controller,
                 const ::ik_UserService::RegisterRequest *request,
                 ::ik_UserService::RegisterResponse *response,
                 ::google::protobuf::Closure *done){
                    std::shared_ptr<LoginOutImpl> impl = std::make_shared<LoginOutImpl>(request, response, controller, done);
                    impl->Run();
                }
    void LoginOut(::google::protobuf::RpcController *controller,
                  const ::ik_UserService::LoginOutRequest *request,
                  ::google::protobuf::Empty *response,
                  ::google::protobuf::Closure *done){
                    std::shared_ptr<RegisterImpl> impl = std::make_shared<RegisterImpl>(request, response, controller, done);
                    impl->Run();
                  }
};