#include "OfflineServer.h"
#include "../lightrpc/common/config.h"
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

    std::string server_addr = lightrpc::Config::GetGlobalConfig()->m_rpc_servers_["server"].addr_->ToString();
    int split_pos = server_addr.find(":");
    string server_ip = server_addr.substr(0, split_pos);
    int server_port = atoi(server_addr.substr(split_pos+1, server_addr.size()).c_str());

    // 数据库相关
    std::string mysqlUrl = "localhost";			        // 主机地址
    std::string mysqlUser = "root";		            // 登陆数据库用户名
    std::string mysqlPassWord = "1106";	            // 登陆数据库密码
    std::string databaseName = "login";               // 使用数据库名
    int mysqlPort = 3306;		                    // 数据库端口号

    OfflineServer server(server_ip, server_port, mysqlUrl, mysqlUser, mysqlPassWord, databaseName, mysqlPort);
    server.run();
}