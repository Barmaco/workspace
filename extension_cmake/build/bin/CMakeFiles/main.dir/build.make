# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_SOURCE_DIR = /home/barmaco/workspace/extension

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/barmaco/workspace/extension/build

# Include any dependencies generated for this target.
include bin/CMakeFiles/main.dir/depend.make

# Include the progress variables for this target.
include bin/CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include bin/CMakeFiles/main.dir/flags.make

bin/CMakeFiles/main.dir/test.o: bin/CMakeFiles/main.dir/flags.make
bin/CMakeFiles/main.dir/test.o: ../examples/test.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/barmaco/workspace/extension/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object bin/CMakeFiles/main.dir/test.o"
	cd /home/barmaco/workspace/extension/build/bin && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/main.dir/test.o -c /home/barmaco/workspace/extension/examples/test.cpp

bin/CMakeFiles/main.dir/test.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/test.i"
	cd /home/barmaco/workspace/extension/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/barmaco/workspace/extension/examples/test.cpp > CMakeFiles/main.dir/test.i

bin/CMakeFiles/main.dir/test.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/test.s"
	cd /home/barmaco/workspace/extension/build/bin && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/barmaco/workspace/extension/examples/test.cpp -o CMakeFiles/main.dir/test.s

bin/CMakeFiles/main.dir/test.o.requires:
.PHONY : bin/CMakeFiles/main.dir/test.o.requires

bin/CMakeFiles/main.dir/test.o.provides: bin/CMakeFiles/main.dir/test.o.requires
	$(MAKE) -f bin/CMakeFiles/main.dir/build.make bin/CMakeFiles/main.dir/test.o.provides.build
.PHONY : bin/CMakeFiles/main.dir/test.o.provides

bin/CMakeFiles/main.dir/test.o.provides.build: bin/CMakeFiles/main.dir/test.o

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/test.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

bin/bin/main: bin/CMakeFiles/main.dir/test.o
bin/bin/main: bin/CMakeFiles/main.dir/build.make
bin/bin/main: bin/CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable bin/main"
	cd /home/barmaco/workspace/extension/build/bin && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
bin/CMakeFiles/main.dir/build: bin/bin/main
.PHONY : bin/CMakeFiles/main.dir/build

bin/CMakeFiles/main.dir/requires: bin/CMakeFiles/main.dir/test.o.requires
.PHONY : bin/CMakeFiles/main.dir/requires

bin/CMakeFiles/main.dir/clean:
	cd /home/barmaco/workspace/extension/build/bin && $(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : bin/CMakeFiles/main.dir/clean

bin/CMakeFiles/main.dir/depend:
	cd /home/barmaco/workspace/extension/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/barmaco/workspace/extension /home/barmaco/workspace/extension/examples /home/barmaco/workspace/extension/build /home/barmaco/workspace/extension/build/bin /home/barmaco/workspace/extension/build/bin/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : bin/CMakeFiles/main.dir/depend

