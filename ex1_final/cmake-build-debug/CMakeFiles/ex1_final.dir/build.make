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
CMAKE_SOURCE_DIR = D:\ClionProjects\CPP\ex1_final

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\ClionProjects\CPP\ex1_final\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ex1_final.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ex1_final.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex1_final.dir/flags.make

CMakeFiles/ex1_final.dir/tester.cpp.obj: CMakeFiles/ex1_final.dir/flags.make
CMakeFiles/ex1_final.dir/tester.cpp.obj: ../tester.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ClionProjects\CPP\ex1_final\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ex1_final.dir/tester.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ex1_final.dir\tester.cpp.obj -c D:\ClionProjects\CPP\ex1_final\tester.cpp

CMakeFiles/ex1_final.dir/tester.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex1_final.dir/tester.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ClionProjects\CPP\ex1_final\tester.cpp > CMakeFiles\ex1_final.dir\tester.cpp.i

CMakeFiles/ex1_final.dir/tester.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex1_final.dir/tester.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ClionProjects\CPP\ex1_final\tester.cpp -o CMakeFiles\ex1_final.dir\tester.cpp.s

CMakeFiles/ex1_final.dir/Matrix3D.cpp.obj: CMakeFiles/ex1_final.dir/flags.make
CMakeFiles/ex1_final.dir/Matrix3D.cpp.obj: ../Matrix3D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ClionProjects\CPP\ex1_final\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/ex1_final.dir/Matrix3D.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ex1_final.dir\Matrix3D.cpp.obj -c D:\ClionProjects\CPP\ex1_final\Matrix3D.cpp

CMakeFiles/ex1_final.dir/Matrix3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex1_final.dir/Matrix3D.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ClionProjects\CPP\ex1_final\Matrix3D.cpp > CMakeFiles\ex1_final.dir\Matrix3D.cpp.i

CMakeFiles/ex1_final.dir/Matrix3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex1_final.dir/Matrix3D.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ClionProjects\CPP\ex1_final\Matrix3D.cpp -o CMakeFiles\ex1_final.dir\Matrix3D.cpp.s

CMakeFiles/ex1_final.dir/Vector3D.cpp.obj: CMakeFiles/ex1_final.dir/flags.make
CMakeFiles/ex1_final.dir/Vector3D.cpp.obj: ../Vector3D.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\ClionProjects\CPP\ex1_final\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/ex1_final.dir/Vector3D.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\ex1_final.dir\Vector3D.cpp.obj -c D:\ClionProjects\CPP\ex1_final\Vector3D.cpp

CMakeFiles/ex1_final.dir/Vector3D.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex1_final.dir/Vector3D.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\ClionProjects\CPP\ex1_final\Vector3D.cpp > CMakeFiles\ex1_final.dir\Vector3D.cpp.i

CMakeFiles/ex1_final.dir/Vector3D.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex1_final.dir/Vector3D.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\ClionProjects\CPP\ex1_final\Vector3D.cpp -o CMakeFiles\ex1_final.dir\Vector3D.cpp.s

# Object files for target ex1_final
ex1_final_OBJECTS = \
"CMakeFiles/ex1_final.dir/tester.cpp.obj" \
"CMakeFiles/ex1_final.dir/Matrix3D.cpp.obj" \
"CMakeFiles/ex1_final.dir/Vector3D.cpp.obj"

# External object files for target ex1_final
ex1_final_EXTERNAL_OBJECTS =

ex1_final.exe: CMakeFiles/ex1_final.dir/tester.cpp.obj
ex1_final.exe: CMakeFiles/ex1_final.dir/Matrix3D.cpp.obj
ex1_final.exe: CMakeFiles/ex1_final.dir/Vector3D.cpp.obj
ex1_final.exe: CMakeFiles/ex1_final.dir/build.make
ex1_final.exe: CMakeFiles/ex1_final.dir/linklibs.rsp
ex1_final.exe: CMakeFiles/ex1_final.dir/objects1.rsp
ex1_final.exe: CMakeFiles/ex1_final.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\ClionProjects\CPP\ex1_final\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable ex1_final.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ex1_final.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex1_final.dir/build: ex1_final.exe

.PHONY : CMakeFiles/ex1_final.dir/build

CMakeFiles/ex1_final.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ex1_final.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ex1_final.dir/clean

CMakeFiles/ex1_final.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\ClionProjects\CPP\ex1_final D:\ClionProjects\CPP\ex1_final D:\ClionProjects\CPP\ex1_final\cmake-build-debug D:\ClionProjects\CPP\ex1_final\cmake-build-debug D:\ClionProjects\CPP\ex1_final\cmake-build-debug\CMakeFiles\ex1_final.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ex1_final.dir/depend

