cmake_minimum_required(VERSION 3.0)
project(CharService)

# 设置编译选项
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)

# 设置头文件搜索路径
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

# 设置可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 添加路径下所有文件到SRC_LIST
aux_source_directory("${CMAKE_CURRENT_BINARY_DIR}/../src/proto" SRC_PROTO_LIST)
aux_source_directory("${CMAKE_CURRENT_BINARY_DIR}/../src/server" SRC_SERVER_LIST)
# 生成可执行文件
add_executable(ProxyServer ${SRC_PROTO_LIST} ${SRC_SERVER_LIST})

target_link_libraries(ProxyServer lightrpc tinyxml protobuf zookeeper_mt hiredis muduo_net muduo_base pthread mysqlclient)