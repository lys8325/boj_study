# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/leehyeoksoo/Desktop/코딩공부/boj/01152_num_word

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/leehyeoksoo/Desktop/코딩공부/boj/01152_num_word/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/01152_num_word.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/01152_num_word.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/01152_num_word.dir/flags.make

CMakeFiles/01152_num_word.dir/main.cpp.o: CMakeFiles/01152_num_word.dir/flags.make
CMakeFiles/01152_num_word.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/leehyeoksoo/Desktop/코딩공부/boj/01152_num_word/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/01152_num_word.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/01152_num_word.dir/main.cpp.o -c /Users/leehyeoksoo/Desktop/코딩공부/boj/01152_num_word/main.cpp

CMakeFiles/01152_num_word.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/01152_num_word.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/leehyeoksoo/Desktop/코딩공부/boj/01152_num_word/main.cpp > CMakeFiles/01152_num_word.dir/main.cpp.i

CMakeFiles/01152_num_word.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/01152_num_word.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/leehyeoksoo/Desktop/코딩공부/boj/01152_num_word/main.cpp -o CMakeFiles/01152_num_word.dir/main.cpp.s

# Object files for target 01152_num_word
01152_num_word_OBJECTS = \
"CMakeFiles/01152_num_word.dir/main.cpp.o"

# External object files for target 01152_num_word
01152_num_word_EXTERNAL_OBJECTS =

01152_num_word: CMakeFiles/01152_num_word.dir/main.cpp.o
01152_num_word: CMakeFiles/01152_num_word.dir/build.make
01152_num_word: CMakeFiles/01152_num_word.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/leehyeoksoo/Desktop/코딩공부/boj/01152_num_word/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 01152_num_word"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/01152_num_word.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/01152_num_word.dir/build: 01152_num_word

.PHONY : CMakeFiles/01152_num_word.dir/build

CMakeFiles/01152_num_word.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/01152_num_word.dir/cmake_clean.cmake
.PHONY : CMakeFiles/01152_num_word.dir/clean

CMakeFiles/01152_num_word.dir/depend:
	cd /Users/leehyeoksoo/Desktop/코딩공부/boj/01152_num_word/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/leehyeoksoo/Desktop/코딩공부/boj/01152_num_word /Users/leehyeoksoo/Desktop/코딩공부/boj/01152_num_word /Users/leehyeoksoo/Desktop/코딩공부/boj/01152_num_word/cmake-build-debug /Users/leehyeoksoo/Desktop/코딩공부/boj/01152_num_word/cmake-build-debug /Users/leehyeoksoo/Desktop/코딩공부/boj/01152_num_word/cmake-build-debug/CMakeFiles/01152_num_word.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/01152_num_word.dir/depend

