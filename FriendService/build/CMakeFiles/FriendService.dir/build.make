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
include CMakeFiles/FriendService.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/FriendService.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/FriendService.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FriendService.dir/flags.make

CMakeFiles/FriendService.dir/src/proto/FriendServer.pb.cc.o: CMakeFiles/FriendService.dir/flags.make
CMakeFiles/FriendService.dir/src/proto/FriendServer.pb.cc.o: ../src/proto/FriendServer.pb.cc
CMakeFiles/FriendService.dir/src/proto/FriendServer.pb.cc.o: CMakeFiles/FriendService.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/code/LightTalk/FriendService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FriendService.dir/src/proto/FriendServer.pb.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FriendService.dir/src/proto/FriendServer.pb.cc.o -MF CMakeFiles/FriendService.dir/src/proto/FriendServer.pb.cc.o.d -o CMakeFiles/FriendService.dir/src/proto/FriendServer.pb.cc.o -c /home/ubuntu/code/LightTalk/FriendService/src/proto/FriendServer.pb.cc

CMakeFiles/FriendService.dir/src/proto/FriendServer.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendService.dir/src/proto/FriendServer.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/code/LightTalk/FriendService/src/proto/FriendServer.pb.cc > CMakeFiles/FriendService.dir/src/proto/FriendServer.pb.cc.i

CMakeFiles/FriendService.dir/src/proto/FriendServer.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendService.dir/src/proto/FriendServer.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/code/LightTalk/FriendService/src/proto/FriendServer.pb.cc -o CMakeFiles/FriendService.dir/src/proto/FriendServer.pb.cc.s

CMakeFiles/FriendService.dir/src/proto/FriendService.pb.cc.o: CMakeFiles/FriendService.dir/flags.make
CMakeFiles/FriendService.dir/src/proto/FriendService.pb.cc.o: ../src/proto/FriendService.pb.cc
CMakeFiles/FriendService.dir/src/proto/FriendService.pb.cc.o: CMakeFiles/FriendService.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/code/LightTalk/FriendService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FriendService.dir/src/proto/FriendService.pb.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FriendService.dir/src/proto/FriendService.pb.cc.o -MF CMakeFiles/FriendService.dir/src/proto/FriendService.pb.cc.o.d -o CMakeFiles/FriendService.dir/src/proto/FriendService.pb.cc.o -c /home/ubuntu/code/LightTalk/FriendService/src/proto/FriendService.pb.cc

CMakeFiles/FriendService.dir/src/proto/FriendService.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendService.dir/src/proto/FriendService.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/code/LightTalk/FriendService/src/proto/FriendService.pb.cc > CMakeFiles/FriendService.dir/src/proto/FriendService.pb.cc.i

CMakeFiles/FriendService.dir/src/proto/FriendService.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendService.dir/src/proto/FriendService.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/code/LightTalk/FriendService/src/proto/FriendService.pb.cc -o CMakeFiles/FriendService.dir/src/proto/FriendService.pb.cc.s

CMakeFiles/FriendService.dir/src/proto/LogServer.pb.cc.o: CMakeFiles/FriendService.dir/flags.make
CMakeFiles/FriendService.dir/src/proto/LogServer.pb.cc.o: ../src/proto/LogServer.pb.cc
CMakeFiles/FriendService.dir/src/proto/LogServer.pb.cc.o: CMakeFiles/FriendService.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/code/LightTalk/FriendService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/FriendService.dir/src/proto/LogServer.pb.cc.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FriendService.dir/src/proto/LogServer.pb.cc.o -MF CMakeFiles/FriendService.dir/src/proto/LogServer.pb.cc.o.d -o CMakeFiles/FriendService.dir/src/proto/LogServer.pb.cc.o -c /home/ubuntu/code/LightTalk/FriendService/src/proto/LogServer.pb.cc

CMakeFiles/FriendService.dir/src/proto/LogServer.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendService.dir/src/proto/LogServer.pb.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/code/LightTalk/FriendService/src/proto/LogServer.pb.cc > CMakeFiles/FriendService.dir/src/proto/LogServer.pb.cc.i

CMakeFiles/FriendService.dir/src/proto/LogServer.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendService.dir/src/proto/LogServer.pb.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/code/LightTalk/FriendService/src/proto/LogServer.pb.cc -o CMakeFiles/FriendService.dir/src/proto/LogServer.pb.cc.s

CMakeFiles/FriendService.dir/src/service/ZooKeeperMatser.cpp.o: CMakeFiles/FriendService.dir/flags.make
CMakeFiles/FriendService.dir/src/service/ZooKeeperMatser.cpp.o: ../src/service/ZooKeeperMatser.cpp
CMakeFiles/FriendService.dir/src/service/ZooKeeperMatser.cpp.o: CMakeFiles/FriendService.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/code/LightTalk/FriendService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/FriendService.dir/src/service/ZooKeeperMatser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FriendService.dir/src/service/ZooKeeperMatser.cpp.o -MF CMakeFiles/FriendService.dir/src/service/ZooKeeperMatser.cpp.o.d -o CMakeFiles/FriendService.dir/src/service/ZooKeeperMatser.cpp.o -c /home/ubuntu/code/LightTalk/FriendService/src/service/ZooKeeperMatser.cpp

CMakeFiles/FriendService.dir/src/service/ZooKeeperMatser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendService.dir/src/service/ZooKeeperMatser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/code/LightTalk/FriendService/src/service/ZooKeeperMatser.cpp > CMakeFiles/FriendService.dir/src/service/ZooKeeperMatser.cpp.i

CMakeFiles/FriendService.dir/src/service/ZooKeeperMatser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendService.dir/src/service/ZooKeeperMatser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/code/LightTalk/FriendService/src/service/ZooKeeperMatser.cpp -o CMakeFiles/FriendService.dir/src/service/ZooKeeperMatser.cpp.s

CMakeFiles/FriendService.dir/src/service/mian.cpp.o: CMakeFiles/FriendService.dir/flags.make
CMakeFiles/FriendService.dir/src/service/mian.cpp.o: ../src/service/mian.cpp
CMakeFiles/FriendService.dir/src/service/mian.cpp.o: CMakeFiles/FriendService.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/code/LightTalk/FriendService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/FriendService.dir/src/service/mian.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FriendService.dir/src/service/mian.cpp.o -MF CMakeFiles/FriendService.dir/src/service/mian.cpp.o.d -o CMakeFiles/FriendService.dir/src/service/mian.cpp.o -c /home/ubuntu/code/LightTalk/FriendService/src/service/mian.cpp

CMakeFiles/FriendService.dir/src/service/mian.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FriendService.dir/src/service/mian.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/code/LightTalk/FriendService/src/service/mian.cpp > CMakeFiles/FriendService.dir/src/service/mian.cpp.i

CMakeFiles/FriendService.dir/src/service/mian.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FriendService.dir/src/service/mian.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/code/LightTalk/FriendService/src/service/mian.cpp -o CMakeFiles/FriendService.dir/src/service/mian.cpp.s

# Object files for target FriendService
FriendService_OBJECTS = \
"CMakeFiles/FriendService.dir/src/proto/FriendServer.pb.cc.o" \
"CMakeFiles/FriendService.dir/src/proto/FriendService.pb.cc.o" \
"CMakeFiles/FriendService.dir/src/proto/LogServer.pb.cc.o" \
"CMakeFiles/FriendService.dir/src/service/ZooKeeperMatser.cpp.o" \
"CMakeFiles/FriendService.dir/src/service/mian.cpp.o"

# External object files for target FriendService
FriendService_EXTERNAL_OBJECTS =

../bin/FriendService: CMakeFiles/FriendService.dir/src/proto/FriendServer.pb.cc.o
../bin/FriendService: CMakeFiles/FriendService.dir/src/proto/FriendService.pb.cc.o
../bin/FriendService: CMakeFiles/FriendService.dir/src/proto/LogServer.pb.cc.o
../bin/FriendService: CMakeFiles/FriendService.dir/src/service/ZooKeeperMatser.cpp.o
../bin/FriendService: CMakeFiles/FriendService.dir/src/service/mian.cpp.o
../bin/FriendService: CMakeFiles/FriendService.dir/build.make
../bin/FriendService: CMakeFiles/FriendService.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/code/LightTalk/FriendService/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable ../bin/FriendService"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FriendService.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FriendService.dir/build: ../bin/FriendService
.PHONY : CMakeFiles/FriendService.dir/build

CMakeFiles/FriendService.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FriendService.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FriendService.dir/clean

CMakeFiles/FriendService.dir/depend:
	cd /home/ubuntu/code/LightTalk/FriendService/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/code/LightTalk/FriendService /home/ubuntu/code/LightTalk/FriendService /home/ubuntu/code/LightTalk/FriendService/build /home/ubuntu/code/LightTalk/FriendService/build /home/ubuntu/code/LightTalk/FriendService/build/CMakeFiles/FriendService.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FriendService.dir/depend

