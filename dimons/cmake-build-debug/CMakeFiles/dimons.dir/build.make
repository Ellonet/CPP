# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\ClionProjects\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\ClionProjects\CLion 2018.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\ClionProjects\CPP\dimons

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\ClionProjects\CPP\dimons\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/dimons.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/dimons.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/dimons.dir/flags.make

CMakeFiles/dimons.dir/main.cpp.obj: CMakeFiles/dimons.dir/flags.make
CMakeFiles/dimons.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ClionProjects\CPP\dimons\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/dimons.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\dimons.dir\main.cpp.obj -c D:\ClionProjects\CPP\dimons\main.cpp

CMakeFiles/dimons.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dimons.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ClionProjects\CPP\dimons\main.cpp > CMakeFiles\dimons.dir\main.cpp.i

CMakeFiles/dimons.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dimons.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ClionProjects\CPP\dimons\main.cpp -o CMakeFiles\dimons.dir\main.cpp.s

# Object files for target dimons
dimons_OBJECTS = \
"CMakeFiles/dimons.dir/main.cpp.obj"

# External object files for target dimons
dimons_EXTERNAL_OBJECTS =

dimons.exe: CMakeFiles/dimons.dir/main.cpp.obj
dimons.exe: CMakeFiles/dimons.dir/build.make
dimons.exe: CMakeFiles/dimons.dir/linklibs.rsp
dimons.exe: CMakeFiles/dimons.dir/objects1.rsp
dimons.exe: CMakeFiles/dimons.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\ClionProjects\CPP\dimons\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dimons.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\dimons.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/dimons.dir/build: dimons.exe

.PHONY : CMakeFiles/dimons.dir/build

CMakeFiles/dimons.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\dimons.dir\cmake_clean.cmake
.PHONY : CMakeFiles/dimons.dir/clean

CMakeFiles/dimons.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\ClionProjects\CPP\dimons D:\ClionProjects\CPP\dimons D:\ClionProjects\CPP\dimons\cmake-build-debug D:\ClionProjects\CPP\dimons\cmake-build-debug D:\ClionProjects\CPP\dimons\cmake-build-debug\CMakeFiles\dimons.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/dimons.dir/depend
