# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/v3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/v3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/v3.dir/flags.make

CMakeFiles/v3.dir/Acceptor.cpp.o: CMakeFiles/v3.dir/flags.make
CMakeFiles/v3.dir/Acceptor.cpp.o: ../Acceptor.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/v3.dir/Acceptor.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/v3.dir/Acceptor.cpp.o -c "/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3/Acceptor.cpp"

CMakeFiles/v3.dir/Acceptor.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/v3.dir/Acceptor.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3/Acceptor.cpp" > CMakeFiles/v3.dir/Acceptor.cpp.i

CMakeFiles/v3.dir/Acceptor.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/v3.dir/Acceptor.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3/Acceptor.cpp" -o CMakeFiles/v3.dir/Acceptor.cpp.s

CMakeFiles/v3.dir/Acceptor.cpp.o.requires:

.PHONY : CMakeFiles/v3.dir/Acceptor.cpp.o.requires

CMakeFiles/v3.dir/Acceptor.cpp.o.provides: CMakeFiles/v3.dir/Acceptor.cpp.o.requires
	$(MAKE) -f CMakeFiles/v3.dir/build.make CMakeFiles/v3.dir/Acceptor.cpp.o.provides.build
.PHONY : CMakeFiles/v3.dir/Acceptor.cpp.o.provides

CMakeFiles/v3.dir/Acceptor.cpp.o.provides.build: CMakeFiles/v3.dir/Acceptor.cpp.o


CMakeFiles/v3.dir/TcpConnection.cpp.o: CMakeFiles/v3.dir/flags.make
CMakeFiles/v3.dir/TcpConnection.cpp.o: ../TcpConnection.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/v3.dir/TcpConnection.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/v3.dir/TcpConnection.cpp.o -c "/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3/TcpConnection.cpp"

CMakeFiles/v3.dir/TcpConnection.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/v3.dir/TcpConnection.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3/TcpConnection.cpp" > CMakeFiles/v3.dir/TcpConnection.cpp.i

CMakeFiles/v3.dir/TcpConnection.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/v3.dir/TcpConnection.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3/TcpConnection.cpp" -o CMakeFiles/v3.dir/TcpConnection.cpp.s

CMakeFiles/v3.dir/TcpConnection.cpp.o.requires:

.PHONY : CMakeFiles/v3.dir/TcpConnection.cpp.o.requires

CMakeFiles/v3.dir/TcpConnection.cpp.o.provides: CMakeFiles/v3.dir/TcpConnection.cpp.o.requires
	$(MAKE) -f CMakeFiles/v3.dir/build.make CMakeFiles/v3.dir/TcpConnection.cpp.o.provides.build
.PHONY : CMakeFiles/v3.dir/TcpConnection.cpp.o.provides

CMakeFiles/v3.dir/TcpConnection.cpp.o.provides.build: CMakeFiles/v3.dir/TcpConnection.cpp.o


CMakeFiles/v3.dir/Eventloop.cpp.o: CMakeFiles/v3.dir/flags.make
CMakeFiles/v3.dir/Eventloop.cpp.o: ../Eventloop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/v3.dir/Eventloop.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/v3.dir/Eventloop.cpp.o -c "/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3/Eventloop.cpp"

CMakeFiles/v3.dir/Eventloop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/v3.dir/Eventloop.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3/Eventloop.cpp" > CMakeFiles/v3.dir/Eventloop.cpp.i

CMakeFiles/v3.dir/Eventloop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/v3.dir/Eventloop.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3/Eventloop.cpp" -o CMakeFiles/v3.dir/Eventloop.cpp.s

CMakeFiles/v3.dir/Eventloop.cpp.o.requires:

.PHONY : CMakeFiles/v3.dir/Eventloop.cpp.o.requires

CMakeFiles/v3.dir/Eventloop.cpp.o.provides: CMakeFiles/v3.dir/Eventloop.cpp.o.requires
	$(MAKE) -f CMakeFiles/v3.dir/build.make CMakeFiles/v3.dir/Eventloop.cpp.o.provides.build
.PHONY : CMakeFiles/v3.dir/Eventloop.cpp.o.provides

CMakeFiles/v3.dir/Eventloop.cpp.o.provides.build: CMakeFiles/v3.dir/Eventloop.cpp.o


CMakeFiles/v3.dir/TestV2.cpp.o: CMakeFiles/v3.dir/flags.make
CMakeFiles/v3.dir/TestV2.cpp.o: ../TestV2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/v3.dir/TestV2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/v3.dir/TestV2.cpp.o -c "/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3/TestV2.cpp"

CMakeFiles/v3.dir/TestV2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/v3.dir/TestV2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3/TestV2.cpp" > CMakeFiles/v3.dir/TestV2.cpp.i

CMakeFiles/v3.dir/TestV2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/v3.dir/TestV2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3/TestV2.cpp" -o CMakeFiles/v3.dir/TestV2.cpp.s

CMakeFiles/v3.dir/TestV2.cpp.o.requires:

.PHONY : CMakeFiles/v3.dir/TestV2.cpp.o.requires

CMakeFiles/v3.dir/TestV2.cpp.o.provides: CMakeFiles/v3.dir/TestV2.cpp.o.requires
	$(MAKE) -f CMakeFiles/v3.dir/build.make CMakeFiles/v3.dir/TestV2.cpp.o.provides.build
.PHONY : CMakeFiles/v3.dir/TestV2.cpp.o.provides

CMakeFiles/v3.dir/TestV2.cpp.o.provides.build: CMakeFiles/v3.dir/TestV2.cpp.o


# Object files for target v3
v3_OBJECTS = \
"CMakeFiles/v3.dir/Acceptor.cpp.o" \
"CMakeFiles/v3.dir/TcpConnection.cpp.o" \
"CMakeFiles/v3.dir/Eventloop.cpp.o" \
"CMakeFiles/v3.dir/TestV2.cpp.o"

# External object files for target v3
v3_EXTERNAL_OBJECTS =

v3: CMakeFiles/v3.dir/Acceptor.cpp.o
v3: CMakeFiles/v3.dir/TcpConnection.cpp.o
v3: CMakeFiles/v3.dir/Eventloop.cpp.o
v3: CMakeFiles/v3.dir/TestV2.cpp.o
v3: CMakeFiles/v3.dir/build.make
v3: CMakeFiles/v3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable v3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/v3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/v3.dir/build: v3

.PHONY : CMakeFiles/v3.dir/build

CMakeFiles/v3.dir/requires: CMakeFiles/v3.dir/Acceptor.cpp.o.requires
CMakeFiles/v3.dir/requires: CMakeFiles/v3.dir/TcpConnection.cpp.o.requires
CMakeFiles/v3.dir/requires: CMakeFiles/v3.dir/Eventloop.cpp.o.requires
CMakeFiles/v3.dir/requires: CMakeFiles/v3.dir/TestV2.cpp.o.requires

.PHONY : CMakeFiles/v3.dir/requires

CMakeFiles/v3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/v3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/v3.dir/clean

CMakeFiles/v3.dir/depend:
	cd "/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3" "/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3" "/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3/cmake-build-debug" "/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3/cmake-build-debug" "/home/ubuntu/myWorkSpace/c++/Reactor/v2&v3/cmake-build-debug/CMakeFiles/v3.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/v3.dir/depend
