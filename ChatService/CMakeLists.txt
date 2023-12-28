cmake_minimum_required(VERSION 3.0)
project(CharService)

# 设置编译选项
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -g)

# 设置头文件搜索路径
include_directories("${CMAKE_CURRENT_BINARY_DIR}")

# 设置可执行文件输出路径
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

# 添加当前路径下所有文件到SRC_LIST
aux_source_directory("${CMAKE_CURRENT_BINARY_DIR}/../src" SRC_LIST)
aux_source_directory("${CMAKE_CURRENT_BINARY_DIR}/../src/proto" SRC_LIST)
# 生成可执行文件
add_executable(ChatService ${SRC_LIST})

target_link_libraries(ChatService lightrpc tinyxml protobuf zookeeper_mt hiredis muduo_net muduo_base pthread mysqlclient)