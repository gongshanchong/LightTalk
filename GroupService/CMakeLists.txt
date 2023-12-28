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
aux_source_directory("${CMAKE_CURRENT_BINARY_DIR}/../src/interface" SRC_INTERFACE_LIST)
aux_source_directory("${CMAKE_CURRENT_BINARY_DIR}/../src/service" SRC_SERVICE_LIST)
# 生成可执行文件
add_executable(GroupService ${SRC_PROTO_LIST} ${SRC_INTERFACE_LIST} ${SRC_SERVICE_LIST})
add_executable(GroupServer ${SRC_PROTO_LIST} ${SRC_SERVER_LIST})

target_link_libraries(GroupService lightrpc tinyxml protobuf zookeeper_mt hiredis muduo_net muduo_base pthread mysqlclient)
target_link_libraries(GroupServer lightrpc tinyxml protobuf zookeeper_mt hiredis muduo_net muduo_base pthread mysqlclient)