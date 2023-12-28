#include "../proto/LogServer.pb.h"
#include "../proto/OfflineServer.pb.h"
#include "../proto/OfflineService.pb.h"

#include "../interface/write_offline.h"
#include "../interface/read_offline.h"
#include "ZooKeeperMaster.h"

#include <google/protobuf/service.h>
#include "../lightrpc/net/rpc/rpc_channel.h"

#include <string>

using namespace std;
class OfflineService : public ik_OfflineService::OfflineServiceRpc
{
public:
    OfflineService(){
        ZKMatser::getInstance()->init("/OfflineService");
        ZKMatser::getInstance()->start();
    }

public:
    void WriteOffline(::google::protobuf::RpcController *controller,
                      const ::ik_OfflineService::WriteOfflineRequest *request,
                      ::google::protobuf::Empty *response,
                      ::google::protobuf::Closure *done){
                        std::shared_ptr<WriteOfflineImpl> impl = std::make_shared<WriteOfflineImpl>(request, response, controller, done);
                        impl->Run();
                      }
    void ReadOffline(::google::protobuf::RpcController *controller,
                     const ::ik_OfflineService::ReadOfflineRequest *request,
                     ::ik_OfflineService::ReadOfflineResponse *response,
                     ::google::protobuf::Closure *done){
                        std::shared_ptr<ReadOfflineImpl> impl = std::make_shared<ReadOfflineImpl>(request, response, controller, done);
                        impl->Run();
                     }
};