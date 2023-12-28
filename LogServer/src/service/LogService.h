#pragma once
#include <string>
#include <google/protobuf/service.h>
#include "../lightrpc/net/rpc/rpc_closure.h"
#include "../lightrpc/net/rpc/rpc_channel.h"
#include "../proto/LogService.pb.h"

#include "../interface/log_error.h"
#include "../interface/log_info.h"
#include "../interface/log_fatal.h"

#define INPUT_SIZE 128
using namespace std;

class LogService : public ik::LogServiceRpc
{
public:
    void Log_INFO(::google::protobuf::RpcController *controller,
                  const ::ik::LogRequest *request,
                  ::google::protobuf::Empty *response,
                  ::google::protobuf::Closure *done){
                    std::shared_ptr<LogInfoImpl> impl = std::make_shared<LogInfoImpl>(request, response, controller, done);
                    impl->Run();
                  }
    void Log_ERROR(::google::protobuf::RpcController *controller,
                   const ::ik::LogRequest *request,
                   ::google::protobuf::Empty *response,
                   ::google::protobuf::Closure *done){
                    std::shared_ptr<LogErrorImpl> impl = std::make_shared<LogErrorImpl>(request, response, controller, done);
                    impl->Run();
                   }
    void Log_FATAL(::google::protobuf::RpcController *controller,
                   const ::ik::LogRequest *request,
                   ::google::protobuf::Empty *response,
                   ::google::protobuf::Closure *done){
                    std::shared_ptr<LogFatalImpl> impl = std::make_shared<LogFatalImpl>(request, response, controller, done);
                    impl->Run();
                   }
};