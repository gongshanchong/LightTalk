#include <signal.h>

#include "../lightrpc/common/config.h"

#include "ProxyService.h"
using namespace std;

//处理服务器ctrl+c结束后，重置user的状态信息
void reset_handler(int)
{
    ProxyService::get_instance().Reset();
    exit(0);
}

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
    std::string server_addr = lightrpc::Config::GetGlobalConfig()->m_rpc_servers_["server"].addr_->ToString();
    int split_pos = server_addr.find(":");
    string ip = server_addr.substr(0, split_pos);
    int port = atoi(server_addr.substr(split_pos+1, server_addr.size()).c_str());

    signal(SIGINT, reset_handler);

    //初始化zookeeper的连接
    ProxyService::get_instance();
    
    muduo::net::EventLoop loop;
    muduo::net::InetAddress addr(ip, port);
    ProxyServer server(loop, addr, "ProxyServer");

    server.Start();
    loop.loop();

    return 0;
}