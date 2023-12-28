#include "LogSend.h"
#include "../lightrpc/common/config.h"
#include "../lightrpc/common/log.h"
#include <cstdlib>

int main(int argc, char **argv)
{
   if (argc != 2) {
        printf("Start server_main error, argc not 2 \n");
        printf("Start like this: \n");
        printf("./main ../conf/lightrpc_client.xml \n");
        return 0;
    }

    // 初始化日志和配置文件
    lightrpc::Config::SetGlobalConfig(argv[1]);
    lightrpc::Logger::InitGlobalLogger();

    std::string logsend_addr = lightrpc::Config::GetGlobalConfig()->m_rpc_servers_["LogSend"].addr_->ToString();
    int split_pos = logsend_addr.find(":");
    string logsend_ip = logsend_addr.substr(0, split_pos);
    int logsend_port = atoi(logsend_addr.substr(split_pos+1, logsend_addr.size()).c_str());

    LogSend server;
    server.run(logsend_ip, logsend_port);
    return 0;
}