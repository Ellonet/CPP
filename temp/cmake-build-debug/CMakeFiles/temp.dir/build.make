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
CMAKE_SOURCE_DIR = D:\ClionProjects\CPP\temp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\ClionProjects\CPP\temp\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/temp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/temp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/temp.dir/flags.make

CMakeFiles/temp.dir/main.cpp.obj: CMakeFiles/temp.dir/flags.make
CMakeFiles/temp.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ClionProjects\CPP\temp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/temp.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\temp.dir\main.cpp.obj -c D:\ClionProjects\CPP\temp\main.cpp

CMakeFiles/temp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/temp.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ClionProjects\CPP\temp\main.cpp > CMakeFiles\temp.dir\main.cpp.i

CMakeFiles/temp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/temp.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ClionProjects\CPP\temp\main.cpp -o CMakeFiles\temp.dir\main.cpp.s

# Object files for target temp
temp_OBJECTS = \
"CMakeFiles/temp.dir/main.cpp.obj"

# External object files for target temp
temp_EXTERNAL_OBJECTS =

temp.exe: CMakeFiles/temp.dir/main.cpp.obj
temp.exe: CMakeFiles/temp.dir/build.make
temp.exe: CMakeFiles/temp.dir/linklibs.rsp
temp.exe: CMakeFiles/temp.dir/objects1.rsp
temp.exe: CMakeFiles/temp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\ClionProjects\CPP\temp\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable temp.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\temp.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/temp.dir/build: temp.exe

.PHONY : CMakeFiles/temp.dir/build

CMakeFiles/temp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\temp.dir\cmake_clean.cmake
.PHONY : CMakeFiles/temp.dir/clean

CMakeFiles/temp.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\ClionProjects\CPP\temp D:\ClionProjects\CPP\temp D:\ClionProjects\CPP\temp\cmake-build-debug D:\ClionProjects\CPP\temp\cmake-build-debug D:\ClionProjects\CPP\temp\cmake-build-debug\CMakeFiles\temp.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/temp.dir/depend

