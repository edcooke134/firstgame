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
CMAKE_SOURCE_DIR = /home/edc/dev/projects/cpp/games/firstgame

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/edc/dev/projects/cpp/games/firstgame/build

# Include any dependencies generated for this target.
include src/CMakeFiles/EntityLibrary.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/EntityLibrary.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/EntityLibrary.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/EntityLibrary.dir/flags.make

src/CMakeFiles/EntityLibrary.dir/Entity.cpp.o: src/CMakeFiles/EntityLibrary.dir/flags.make
src/CMakeFiles/EntityLibrary.dir/Entity.cpp.o: ../src/Entity.cpp
src/CMakeFiles/EntityLibrary.dir/Entity.cpp.o: src/CMakeFiles/EntityLibrary.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/edc/dev/projects/cpp/games/firstgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/EntityLibrary.dir/Entity.cpp.o"
	cd /home/edc/dev/projects/cpp/games/firstgame/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/EntityLibrary.dir/Entity.cpp.o -MF CMakeFiles/EntityLibrary.dir/Entity.cpp.o.d -o CMakeFiles/EntityLibrary.dir/Entity.cpp.o -c /home/edc/dev/projects/cpp/games/firstgame/src/Entity.cpp

src/CMakeFiles/EntityLibrary.dir/Entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EntityLibrary.dir/Entity.cpp.i"
	cd /home/edc/dev/projects/cpp/games/firstgame/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/edc/dev/projects/cpp/games/firstgame/src/Entity.cpp > CMakeFiles/EntityLibrary.dir/Entity.cpp.i

src/CMakeFiles/EntityLibrary.dir/Entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EntityLibrary.dir/Entity.cpp.s"
	cd /home/edc/dev/projects/cpp/games/firstgame/build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/edc/dev/projects/cpp/games/firstgame/src/Entity.cpp -o CMakeFiles/EntityLibrary.dir/Entity.cpp.s

# Object files for target EntityLibrary
EntityLibrary_OBJECTS = \
"CMakeFiles/EntityLibrary.dir/Entity.cpp.o"

# External object files for target EntityLibrary
EntityLibrary_EXTERNAL_OBJECTS =

src/libEntityLibrary.a: src/CMakeFiles/EntityLibrary.dir/Entity.cpp.o
src/libEntityLibrary.a: src/CMakeFiles/EntityLibrary.dir/build.make
src/libEntityLibrary.a: src/CMakeFiles/EntityLibrary.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/edc/dev/projects/cpp/games/firstgame/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libEntityLibrary.a"
	cd /home/edc/dev/projects/cpp/games/firstgame/build/src && $(CMAKE_COMMAND) -P CMakeFiles/EntityLibrary.dir/cmake_clean_target.cmake
	cd /home/edc/dev/projects/cpp/games/firstgame/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EntityLibrary.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/EntityLibrary.dir/build: src/libEntityLibrary.a
.PHONY : src/CMakeFiles/EntityLibrary.dir/build

src/CMakeFiles/EntityLibrary.dir/clean:
	cd /home/edc/dev/projects/cpp/games/firstgame/build/src && $(CMAKE_COMMAND) -P CMakeFiles/EntityLibrary.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/EntityLibrary.dir/clean

src/CMakeFiles/EntityLibrary.dir/depend:
	cd /home/edc/dev/projects/cpp/games/firstgame/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/edc/dev/projects/cpp/games/firstgame /home/edc/dev/projects/cpp/games/firstgame/src /home/edc/dev/projects/cpp/games/firstgame/build /home/edc/dev/projects/cpp/games/firstgame/build/src /home/edc/dev/projects/cpp/games/firstgame/build/src/CMakeFiles/EntityLibrary.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/EntityLibrary.dir/depend

