# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ubuntu/code/LightTalk/FriendService

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/code/LightTalk/FriendService/build

# Include any dependencies generated for this target.
include CMakeFiles/FriendServer.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/FriendServer.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/FriendServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FriendServer.dir/flags.make

CMakeFiles/FriendServer.dir/src/proto/FriendServer.pb.cc.o: CMakeFiles/FriendServer.dir/flags.make
CMakeFiles/FriendServer.dir/src/proto/FriendServer.pb.cc.o: ../src/proto/FriendServer.pb.cc
CMakeFiles/FriendServer.dir/src/proto/FriendServer.pb.cc.o: CMakeFiles/FriendServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/code/LightTalk/FriendService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FriendServer.dir/src/proto/FriendServer.pb.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FriendServer.dir/src/proto/FriendServer.pb.cc.o -MF CMakeFiles/FriendServer.dir/src/proto/FriendServer.pb.cc.o.d -o CMakeFiles/FriendServer.dir/src/proto/FriendServer.pb.cc.o -c /home/ubuntu/code/LightTalk/FriendService/src/proto/FriendServer.pb.cc

CMakeFiles/FriendServer.dir/src/proto/FriendServer.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendServer.dir/src/proto/FriendServer.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/code/LightTalk/FriendService/src/proto/FriendServer.pb.cc > CMakeFiles/FriendServer.dir/src/proto/FriendServer.pb.cc.i

CMakeFiles/FriendServer.dir/src/proto/FriendServer.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendServer.dir/src/proto/FriendServer.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/code/LightTalk/FriendService/src/proto/FriendServer.pb.cc -o CMakeFiles/FriendServer.dir/src/proto/FriendServer.pb.cc.s

CMakeFiles/FriendServer.dir/src/proto/FriendService.pb.cc.o: CMakeFiles/FriendServer.dir/flags.make
CMakeFiles/FriendServer.dir/src/proto/FriendService.pb.cc.o: ../src/proto/FriendService.pb.cc
CMakeFiles/FriendServer.dir/src/proto/FriendService.pb.cc.o: CMakeFiles/FriendServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/code/LightTalk/FriendService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FriendServer.dir/src/proto/FriendService.pb.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FriendServer.dir/src/proto/FriendService.pb.cc.o -MF CMakeFiles/FriendServer.dir/src/proto/FriendService.pb.cc.o.d -o CMakeFiles/FriendServer.dir/src/proto/FriendService.pb.cc.o -c /home/ubuntu/code/LightTalk/FriendService/src/proto/FriendService.pb.cc

CMakeFiles/FriendServer.dir/src/proto/FriendService.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendServer.dir/src/proto/FriendService.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/code/LightTalk/FriendService/src/proto/FriendService.pb.cc > CMakeFiles/FriendServer.dir/src/proto/FriendService.pb.cc.i

CMakeFiles/FriendServer.dir/src/proto/FriendService.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendServer.dir/src/proto/FriendService.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/code/LightTalk/FriendService/src/proto/FriendService.pb.cc -o CMakeFiles/FriendServer.dir/src/proto/FriendService.pb.cc.s

CMakeFiles/FriendServer.dir/src/proto/LogServer.pb.cc.o: CMakeFiles/FriendServer.dir/flags.make
CMakeFiles/FriendServer.dir/src/proto/LogServer.pb.cc.o: ../src/proto/LogServer.pb.cc
CMakeFiles/FriendServer.dir/src/proto/LogServer.pb.cc.o: CMakeFiles/FriendServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/code/LightTalk/FriendService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/FriendServer.dir/src/proto/LogServer.pb.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FriendServer.dir/src/proto/LogServer.pb.cc.o -MF CMakeFiles/FriendServer.dir/src/proto/LogServer.pb.cc.o.d -o CMakeFiles/FriendServer.dir/src/proto/LogServer.pb.cc.o -c /home/ubuntu/code/LightTalk/FriendService/src/proto/LogServer.pb.cc

CMakeFiles/FriendServer.dir/src/proto/LogServer.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendServer.dir/src/proto/LogServer.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/code/LightTalk/FriendService/src/proto/LogServer.pb.cc > CMakeFiles/FriendServer.dir/src/proto/LogServer.pb.cc.i

CMakeFiles/FriendServer.dir/src/proto/LogServer.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendServer.dir/src/proto/LogServer.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/code/LightTalk/FriendService/src/proto/LogServer.pb.cc -o CMakeFiles/FriendServer.dir/src/proto/LogServer.pb.cc.s

CMakeFiles/FriendServer.dir/src/server/FriendServer.cpp.o: CMakeFiles/FriendServer.dir/flags.make
CMakeFiles/FriendServer.dir/src/server/FriendServer.cpp.o: ../src/server/FriendServer.cpp
CMakeFiles/FriendServer.dir/src/server/FriendServer.cpp.o: CMakeFiles/FriendServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/code/LightTalk/FriendService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/FriendServer.dir/src/server/FriendServer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FriendServer.dir/src/server/FriendServer.cpp.o -MF CMakeFiles/FriendServer.dir/src/server/FriendServer.cpp.o.d -o CMakeFiles/FriendServer.dir/src/server/FriendServer.cpp.o -c /home/ubuntu/code/LightTalk/FriendService/src/server/FriendServer.cpp

CMakeFiles/FriendServer.dir/src/server/FriendServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendServer.dir/src/server/FriendServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/code/LightTalk/FriendService/src/server/FriendServer.cpp > CMakeFiles/FriendServer.dir/src/server/FriendServer.cpp.i

CMakeFiles/FriendServer.dir/src/server/FriendServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendServer.dir/src/server/FriendServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/code/LightTalk/FriendService/src/server/FriendServer.cpp -o CMakeFiles/FriendServer.dir/src/server/FriendServer.cpp.s

CMakeFiles/FriendServer.dir/src/server/MysqlConnPool.cpp.o: CMakeFiles/FriendServer.dir/flags.make
CMakeFiles/FriendServer.dir/src/server/MysqlConnPool.cpp.o: ../src/server/MysqlConnPool.cpp
CMakeFiles/FriendServer.dir/src/server/MysqlConnPool.cpp.o: CMakeFiles/FriendServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/code/LightTalk/FriendService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/FriendServer.dir/src/server/MysqlConnPool.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FriendServer.dir/src/server/MysqlConnPool.cpp.o -MF CMakeFiles/FriendServer.dir/src/server/MysqlConnPool.cpp.o.d -o CMakeFiles/FriendServer.dir/src/server/MysqlConnPool.cpp.o -c /home/ubuntu/code/LightTalk/FriendService/src/server/MysqlConnPool.cpp

CMakeFiles/FriendServer.dir/src/server/MysqlConnPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendServer.dir/src/server/MysqlConnPool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/code/LightTalk/FriendService/src/server/MysqlConnPool.cpp > CMakeFiles/FriendServer.dir/src/server/MysqlConnPool.cpp.i

CMakeFiles/FriendServer.dir/src/server/MysqlConnPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendServer.dir/src/server/MysqlConnPool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/code/LightTalk/FriendService/src/server/MysqlConnPool.cpp -o CMakeFiles/FriendServer.dir/src/server/MysqlConnPool.cpp.s

CMakeFiles/FriendServer.dir/src/server/ZooKeeperFow.cpp.o: CMakeFiles/FriendServer.dir/flags.make
CMakeFiles/FriendServer.dir/src/server/ZooKeeperFow.cpp.o: ../src/server/ZooKeeperFow.cpp
CMakeFiles/FriendServer.dir/src/server/ZooKeeperFow.cpp.o: CMakeFiles/FriendServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/code/LightTalk/FriendService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/FriendServer.dir/src/server/ZooKeeperFow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FriendServer.dir/src/server/ZooKeeperFow.cpp.o -MF CMakeFiles/FriendServer.dir/src/server/ZooKeeperFow.cpp.o.d -o CMakeFiles/FriendServer.dir/src/server/ZooKeeperFow.cpp.o -c /home/ubuntu/code/LightTalk/FriendService/src/server/ZooKeeperFow.cpp

CMakeFiles/FriendServer.dir/src/server/ZooKeeperFow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendServer.dir/src/server/ZooKeeperFow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/code/LightTalk/FriendService/src/server/ZooKeeperFow.cpp > CMakeFiles/FriendServer.dir/src/server/ZooKeeperFow.cpp.i

CMakeFiles/FriendServer.dir/src/server/ZooKeeperFow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendServer.dir/src/server/ZooKeeperFow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/code/LightTalk/FriendService/src/server/ZooKeeperFow.cpp -o CMakeFiles/FriendServer.dir/src/server/ZooKeeperFow.cpp.s

CMakeFiles/FriendServer.dir/src/server/run.cpp.o: CMakeFiles/FriendServer.dir/flags.make
CMakeFiles/FriendServer.dir/src/server/run.cpp.o: ../src/server/run.cpp
CMakeFiles/FriendServer.dir/src/server/run.cpp.o: CMakeFiles/FriendServer.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/code/LightTalk/FriendService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/FriendServer.dir/src/server/run.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FriendServer.dir/src/server/run.cpp.o -MF CMakeFiles/FriendServer.dir/src/server/run.cpp.o.d -o CMakeFiles/FriendServer.dir/src/server/run.cpp.o -c /home/ubuntu/code/LightTalk/FriendService/src/server/run.cpp

CMakeFiles/FriendServer.dir/src/server/run.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendServer.dir/src/server/run.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/code/LightTalk/FriendService/src/server/run.cpp > CMakeFiles/FriendServer.dir/src/server/run.cpp.i

CMakeFiles/FriendServer.dir/src/server/run.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendServer.dir/src/server/run.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/code/LightTalk/FriendService/src/server/run.cpp -o CMakeFiles/FriendServer.dir/src/server/run.cpp.s

# Object files for target FriendServer
FriendServer_OBJECTS = \
"CMakeFiles/FriendServer.dir/src/proto/FriendServer.pb.cc.o" \
"CMakeFiles/FriendServer.dir/src/proto/FriendService.pb.cc.o" \
"CMakeFiles/FriendServer.dir/src/proto/LogServer.pb.cc.o" \
"CMakeFiles/FriendServer.dir/src/server/FriendServer.cpp.o" \
"CMakeFiles/FriendServer.dir/src/server/MysqlConnPool.cpp.o" \
"CMakeFiles/FriendServer.dir/src/server/ZooKeeperFow.cpp.o" \
"CMakeFiles/FriendServer.dir/src/server/run.cpp.o"

# External object files for target FriendServer
FriendServer_EXTERNAL_OBJECTS =

../bin/FriendServer: CMakeFiles/FriendServer.dir/src/proto/FriendServer.pb.cc.o
../bin/FriendServer: CMakeFiles/FriendServer.dir/src/proto/FriendService.pb.cc.o
../bin/FriendServer: CMakeFiles/FriendServer.dir/src/proto/LogServer.pb.cc.o
../bin/FriendServer: CMakeFiles/FriendServer.dir/src/server/FriendServer.cpp.o
../bin/FriendServer: CMakeFiles/FriendServer.dir/src/server/MysqlConnPool.cpp.o
../bin/FriendServer: CMakeFiles/FriendServer.dir/src/server/ZooKeeperFow.cpp.o
../bin/FriendServer: CMakeFiles/FriendServer.dir/src/server/run.cpp.o
../bin/FriendServer: CMakeFiles/FriendServer.dir/build.make
../bin/FriendServer: CMakeFiles/FriendServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/code/LightTalk/FriendService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable ../bin/FriendServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FriendServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FriendServer.dir/build: ../bin/FriendServer
.PHONY : CMakeFiles/FriendServer.dir/build

CMakeFiles/FriendServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FriendServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FriendServer.dir/clean

CMakeFiles/FriendServer.dir/depend:
	cd /home/ubuntu/code/LightTalk/FriendService/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/code/LightTalk/FriendService /home/ubuntu/code/LightTalk/FriendService /home/ubuntu/code/LightTalk/FriendService/build /home/ubuntu/code/LightTalk/FriendService/build /home/ubuntu/code/LightTalk/FriendService/build/CMakeFiles/FriendServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FriendServer.dir/depend
