# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_SOURCE_DIR = /root/C++

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/C++/build

# Include any dependencies generated for this target.
include CMakeFiles/binary_to_hex.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/binary_to_hex.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/binary_to_hex.dir/flags.make

CMakeFiles/binary_to_hex.dir/main.cpp.o: CMakeFiles/binary_to_hex.dir/flags.make
CMakeFiles/binary_to_hex.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/binary_to_hex.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/binary_to_hex.dir/main.cpp.o -c /root/C++/main.cpp

CMakeFiles/binary_to_hex.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/binary_to_hex.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/C++/main.cpp > CMakeFiles/binary_to_hex.dir/main.cpp.i

CMakeFiles/binary_to_hex.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/binary_to_hex.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/C++/main.cpp -o CMakeFiles/binary_to_hex.dir/main.cpp.s

# Object files for target binary_to_hex
binary_to_hex_OBJECTS = \
"CMakeFiles/binary_to_hex.dir/main.cpp.o"

# External object files for target binary_to_hex
binary_to_hex_EXTERNAL_OBJECTS =

binary_to_hex: CMakeFiles/binary_to_hex.dir/main.cpp.o
binary_to_hex: CMakeFiles/binary_to_hex.dir/build.make
binary_to_hex: CMakeFiles/binary_to_hex.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/C++/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable binary_to_hex"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/binary_to_hex.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/binary_to_hex.dir/build: binary_to_hex

.PHONY : CMakeFiles/binary_to_hex.dir/build

CMakeFiles/binary_to_hex.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/binary_to_hex.dir/cmake_clean.cmake
.PHONY : CMakeFiles/binary_to_hex.dir/clean

CMakeFiles/binary_to_hex.dir/depend:
	cd /root/C++/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/C++ /root/C++ /root/C++/build /root/C++/build /root/C++/build/CMakeFiles/binary_to_hex.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/binary_to_hex.dir/depend

