# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/leehyeoksoo/Desktop/코딩공부/boj/11047_coin

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/leehyeoksoo/Desktop/코딩공부/boj/11047_coin/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/11047_coin.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/11047_coin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/11047_coin.dir/flags.make

CMakeFiles/11047_coin.dir/main.cpp.o: CMakeFiles/11047_coin.dir/flags.make
CMakeFiles/11047_coin.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/leehyeoksoo/Desktop/코딩공부/boj/11047_coin/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/11047_coin.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/11047_coin.dir/main.cpp.o -c /Users/leehyeoksoo/Desktop/코딩공부/boj/11047_coin/main.cpp

CMakeFiles/11047_coin.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/11047_coin.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/leehyeoksoo/Desktop/코딩공부/boj/11047_coin/main.cpp > CMakeFiles/11047_coin.dir/main.cpp.i

CMakeFiles/11047_coin.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/11047_coin.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/leehyeoksoo/Desktop/코딩공부/boj/11047_coin/main.cpp -o CMakeFiles/11047_coin.dir/main.cpp.s

# Object files for target 11047_coin
11047_coin_OBJECTS = \
"CMakeFiles/11047_coin.dir/main.cpp.o"

# External object files for target 11047_coin
11047_coin_EXTERNAL_OBJECTS =

11047_coin: CMakeFiles/11047_coin.dir/main.cpp.o
11047_coin: CMakeFiles/11047_coin.dir/build.make
11047_coin: CMakeFiles/11047_coin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/leehyeoksoo/Desktop/코딩공부/boj/11047_coin/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 11047_coin"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/11047_coin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/11047_coin.dir/build: 11047_coin

.PHONY : CMakeFiles/11047_coin.dir/build

CMakeFiles/11047_coin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/11047_coin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/11047_coin.dir/clean

CMakeFiles/11047_coin.dir/depend:
	cd /Users/leehyeoksoo/Desktop/코딩공부/boj/11047_coin/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/leehyeoksoo/Desktop/코딩공부/boj/11047_coin /Users/leehyeoksoo/Desktop/코딩공부/boj/11047_coin /Users/leehyeoksoo/Desktop/코딩공부/boj/11047_coin/cmake-build-debug /Users/leehyeoksoo/Desktop/코딩공부/boj/11047_coin/cmake-build-debug /Users/leehyeoksoo/Desktop/코딩공부/boj/11047_coin/cmake-build-debug/CMakeFiles/11047_coin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/11047_coin.dir/depend

