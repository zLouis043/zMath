# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = D:\CMAKE\bin\cmake.exe

# The command to remove a file.
RM = D:\CMAKE\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\zMath\zMath

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\zMath\zMath\bin

# Include any dependencies generated for this target.
include CMakeFiles/zmath.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/zmath.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/zmath.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/zmath.dir/flags.make

CMakeFiles/zmath.dir/main.c.obj: CMakeFiles/zmath.dir/flags.make
CMakeFiles/zmath.dir/main.c.obj: D:/zMath/zMath/main.c
CMakeFiles/zmath.dir/main.c.obj: CMakeFiles/zmath.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=D:\zMath\zMath\bin\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/zmath.dir/main.c.obj"
	C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/zmath.dir/main.c.obj -MF CMakeFiles\zmath.dir\main.c.obj.d -o CMakeFiles\zmath.dir\main.c.obj -c D:\zMath\zMath\main.c

CMakeFiles/zmath.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/zmath.dir/main.c.i"
	C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\zMath\zMath\main.c > CMakeFiles\zmath.dir\main.c.i

CMakeFiles/zmath.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/zmath.dir/main.c.s"
	C:\msys64\mingw64\bin\cc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\zMath\zMath\main.c -o CMakeFiles\zmath.dir\main.c.s

# Object files for target zmath
zmath_OBJECTS = \
"CMakeFiles/zmath.dir/main.c.obj"

# External object files for target zmath
zmath_EXTERNAL_OBJECTS =

zmath.exe: CMakeFiles/zmath.dir/main.c.obj
zmath.exe: CMakeFiles/zmath.dir/build.make
zmath.exe: CMakeFiles/zmath.dir/linkLibs.rsp
zmath.exe: CMakeFiles/zmath.dir/objects1.rsp
zmath.exe: CMakeFiles/zmath.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=D:\zMath\zMath\bin\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable zmath.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\zmath.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/zmath.dir/build: zmath.exe
.PHONY : CMakeFiles/zmath.dir/build

CMakeFiles/zmath.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\zmath.dir\cmake_clean.cmake
.PHONY : CMakeFiles/zmath.dir/clean

CMakeFiles/zmath.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\zMath\zMath D:\zMath\zMath D:\zMath\zMath\bin D:\zMath\zMath\bin D:\zMath\zMath\bin\CMakeFiles\zmath.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/zmath.dir/depend

