# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "F:\Program Files\JetBrains\CLion 2022.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "F:\Program Files\JetBrains\CLion 2022.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\lxt\code\c++Code\test9.19

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\lxt\code\c++Code\test9.19\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/9_19test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/9_19test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/9_19test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/9_19test.dir/flags.make

CMakeFiles/9_19test.dir/main.cpp.obj: CMakeFiles/9_19test.dir/flags.make
CMakeFiles/9_19test.dir/main.cpp.obj: ../main.cpp
CMakeFiles/9_19test.dir/main.cpp.obj: CMakeFiles/9_19test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\lxt\code\c++Code\test9.19\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/9_19test.dir/main.cpp.obj"
	F:\PROGRA~1\mingw\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/9_19test.dir/main.cpp.obj -MF CMakeFiles\9_19test.dir\main.cpp.obj.d -o CMakeFiles\9_19test.dir\main.cpp.obj -c F:\lxt\code\c++Code\test9.19\main.cpp

CMakeFiles/9_19test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/9_19test.dir/main.cpp.i"
	F:\PROGRA~1\mingw\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\lxt\code\c++Code\test9.19\main.cpp > CMakeFiles\9_19test.dir\main.cpp.i

CMakeFiles/9_19test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/9_19test.dir/main.cpp.s"
	F:\PROGRA~1\mingw\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\lxt\code\c++Code\test9.19\main.cpp -o CMakeFiles\9_19test.dir\main.cpp.s

# Object files for target 9_19test
9_19test_OBJECTS = \
"CMakeFiles/9_19test.dir/main.cpp.obj"

# External object files for target 9_19test
9_19test_EXTERNAL_OBJECTS =

9_19test.exe: CMakeFiles/9_19test.dir/main.cpp.obj
9_19test.exe: CMakeFiles/9_19test.dir/build.make
9_19test.exe: CMakeFiles/9_19test.dir/linklibs.rsp
9_19test.exe: CMakeFiles/9_19test.dir/objects1.rsp
9_19test.exe: CMakeFiles/9_19test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\lxt\code\c++Code\test9.19\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 9_19test.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\9_19test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/9_19test.dir/build: 9_19test.exe
.PHONY : CMakeFiles/9_19test.dir/build

CMakeFiles/9_19test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\9_19test.dir\cmake_clean.cmake
.PHONY : CMakeFiles/9_19test.dir/clean

CMakeFiles/9_19test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\lxt\code\c++Code\test9.19 F:\lxt\code\c++Code\test9.19 F:\lxt\code\c++Code\test9.19\cmake-build-debug F:\lxt\code\c++Code\test9.19\cmake-build-debug F:\lxt\code\c++Code\test9.19\cmake-build-debug\CMakeFiles\9_19test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/9_19test.dir/depend

