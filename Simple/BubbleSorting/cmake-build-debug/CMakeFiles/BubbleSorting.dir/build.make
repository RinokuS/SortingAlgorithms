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
CMAKE_COMMAND = "/Users/rinokus/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.6948.80/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/rinokus/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.6948.80/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/rinokus/Documents/Projects/SortingAlgorithms/Simple/BubbleSorting

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/rinokus/Documents/Projects/SortingAlgorithms/Simple/BubbleSorting/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BubbleSorting.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BubbleSorting.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BubbleSorting.dir/flags.make

CMakeFiles/BubbleSorting.dir/main.cpp.o: CMakeFiles/BubbleSorting.dir/flags.make
CMakeFiles/BubbleSorting.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/rinokus/Documents/Projects/SortingAlgorithms/Simple/BubbleSorting/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BubbleSorting.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BubbleSorting.dir/main.cpp.o -c /Users/rinokus/Documents/Projects/SortingAlgorithms/Simple/BubbleSorting/main.cpp

CMakeFiles/BubbleSorting.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BubbleSorting.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/rinokus/Documents/Projects/SortingAlgorithms/Simple/BubbleSorting/main.cpp > CMakeFiles/BubbleSorting.dir/main.cpp.i

CMakeFiles/BubbleSorting.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BubbleSorting.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/rinokus/Documents/Projects/SortingAlgorithms/Simple/BubbleSorting/main.cpp -o CMakeFiles/BubbleSorting.dir/main.cpp.s

# Object files for target BubbleSorting
BubbleSorting_OBJECTS = \
"CMakeFiles/BubbleSorting.dir/main.cpp.o"

# External object files for target BubbleSorting
BubbleSorting_EXTERNAL_OBJECTS =

BubbleSorting: CMakeFiles/BubbleSorting.dir/main.cpp.o
BubbleSorting: CMakeFiles/BubbleSorting.dir/build.make
BubbleSorting: CMakeFiles/BubbleSorting.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/rinokus/Documents/Projects/SortingAlgorithms/Simple/BubbleSorting/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BubbleSorting"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BubbleSorting.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BubbleSorting.dir/build: BubbleSorting

.PHONY : CMakeFiles/BubbleSorting.dir/build

CMakeFiles/BubbleSorting.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BubbleSorting.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BubbleSorting.dir/clean

CMakeFiles/BubbleSorting.dir/depend:
	cd /Users/rinokus/Documents/Projects/SortingAlgorithms/Simple/BubbleSorting/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/rinokus/Documents/Projects/SortingAlgorithms/Simple/BubbleSorting /Users/rinokus/Documents/Projects/SortingAlgorithms/Simple/BubbleSorting /Users/rinokus/Documents/Projects/SortingAlgorithms/Simple/BubbleSorting/cmake-build-debug /Users/rinokus/Documents/Projects/SortingAlgorithms/Simple/BubbleSorting/cmake-build-debug /Users/rinokus/Documents/Projects/SortingAlgorithms/Simple/BubbleSorting/cmake-build-debug/CMakeFiles/BubbleSorting.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BubbleSorting.dir/depend

