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
CMAKE_SOURCE_DIR = /Users/leehyeoksoo/Desktop/study/boj_study/15694

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/leehyeoksoo/Desktop/study/boj_study/15694/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/15694.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/15694.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/15694.dir/flags.make

CMakeFiles/15694.dir/main.cpp.o: CMakeFiles/15694.dir/flags.make
CMakeFiles/15694.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/leehyeoksoo/Desktop/study/boj_study/15694/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/15694.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/15694.dir/main.cpp.o -c /Users/leehyeoksoo/Desktop/study/boj_study/15694/main.cpp

CMakeFiles/15694.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/15694.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/leehyeoksoo/Desktop/study/boj_study/15694/main.cpp > CMakeFiles/15694.dir/main.cpp.i

CMakeFiles/15694.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/15694.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/leehyeoksoo/Desktop/study/boj_study/15694/main.cpp -o CMakeFiles/15694.dir/main.cpp.s

# Object files for target 15694
15694_OBJECTS = \
"CMakeFiles/15694.dir/main.cpp.o"

# External object files for target 15694
15694_EXTERNAL_OBJECTS =

15694: CMakeFiles/15694.dir/main.cpp.o
15694: CMakeFiles/15694.dir/build.make
15694: CMakeFiles/15694.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/leehyeoksoo/Desktop/study/boj_study/15694/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 15694"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/15694.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/15694.dir/build: 15694

.PHONY : CMakeFiles/15694.dir/build

CMakeFiles/15694.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/15694.dir/cmake_clean.cmake
.PHONY : CMakeFiles/15694.dir/clean

CMakeFiles/15694.dir/depend:
	cd /Users/leehyeoksoo/Desktop/study/boj_study/15694/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/leehyeoksoo/Desktop/study/boj_study/15694 /Users/leehyeoksoo/Desktop/study/boj_study/15694 /Users/leehyeoksoo/Desktop/study/boj_study/15694/cmake-build-debug /Users/leehyeoksoo/Desktop/study/boj_study/15694/cmake-build-debug /Users/leehyeoksoo/Desktop/study/boj_study/15694/cmake-build-debug/CMakeFiles/15694.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/15694.dir/depend
