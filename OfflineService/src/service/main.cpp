#include "OfflineService.h"
#include "lightrpc/net/tcp/tcp_server.h"
#include <string>
#include <unistd.h>
using namespace std;

int main(int argc, char **argv)
{
    if (argc != 2) {
        printf("Start server_main error, argc not 2 \n");
        printf("Start like this: \n");
        printf("./main ../conf/lightrpc_service.xml \n");
        return 0;
    }

    // 初始化日志和配置文件
    lightrpc::Config::SetGlobalConfig(argv[1]);
    lightrpc::Logger::InitGlobalLogger();

    // 绑定地址
    std::shared_ptr<OfflineService> user_service = std::shared_ptr<OfflineService>(new OfflineService());
    std::unique_ptr<lightrpc::TcpServer> server_ = std::make_unique<lightrpc::TcpServer>(lightrpc::Config::GetGlobalConfig()->m_rpc_stubs_["default"].addr_, 
    lightrpc::Config::GetGlobalConfig()->m_rpc_servers_["default"].addr_, 
    lightrpc::Config::GetGlobalConfig()->m_rpc_stubs_["default"].protocal_, 
    lightrpc::Config::GetGlobalConfig()->m_rpc_stubs_["default"].timeout_);
    // 注册服务
    lightrpc::RpcDispatcher::GetRpcDispatcher()->RegisterServlet("/OfflineService", user_service);
    // 构建服务端
    server_->Start();

    return 0;
}