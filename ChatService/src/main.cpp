#include "ChatServer.h"
#include "../lightrpc/common/config.h"

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
    std::string redis_addr = lightrpc::Config::GetGlobalConfig()->m_rpc_servers_["redis"].addr_->ToString();
    int split_pos = redis_addr.find(":");
    string redis_ip = redis_addr.substr(0, split_pos);
    int redis_port = atoi(redis_addr.substr(split_pos+1, redis_addr.size()).c_str());

    std::string server_addr = lightrpc::Config::GetGlobalConfig()->m_rpc_servers_["server"].addr_->ToString();
    split_pos = server_addr.find(":");
    string server_ip = server_addr.substr(0, split_pos);
    int server_port = atoi(server_addr.substr(split_pos+1, server_addr.size()).c_str());

    ChatServer server(redis_ip, redis_port);
    server.run(server_ip, server_port);
}