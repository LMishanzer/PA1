# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/mike/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.6817.32/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/mike/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/192.6817.32/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/mike/PA1/Domaci ukol 4"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/mike/PA1/Domaci ukol 4/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Domaci_ukol_4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Domaci_ukol_4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Domaci_ukol_4.dir/flags.make

CMakeFiles/Domaci_ukol_4.dir/main.c.o: CMakeFiles/Domaci_ukol_4.dir/flags.make
CMakeFiles/Domaci_ukol_4.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/mike/PA1/Domaci ukol 4/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Domaci_ukol_4.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Domaci_ukol_4.dir/main.c.o   -c "/home/mike/PA1/Domaci ukol 4/main.c"

CMakeFiles/Domaci_ukol_4.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Domaci_ukol_4.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/mike/PA1/Domaci ukol 4/main.c" > CMakeFiles/Domaci_ukol_4.dir/main.c.i

CMakeFiles/Domaci_ukol_4.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Domaci_ukol_4.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/mike/PA1/Domaci ukol 4/main.c" -o CMakeFiles/Domaci_ukol_4.dir/main.c.s

# Object files for target Domaci_ukol_4
Domaci_ukol_4_OBJECTS = \
"CMakeFiles/Domaci_ukol_4.dir/main.c.o"

# External object files for target Domaci_ukol_4
Domaci_ukol_4_EXTERNAL_OBJECTS =

Domaci_ukol_4: CMakeFiles/Domaci_ukol_4.dir/main.c.o
Domaci_ukol_4: CMakeFiles/Domaci_ukol_4.dir/build.make
Domaci_ukol_4: CMakeFiles/Domaci_ukol_4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/mike/PA1/Domaci ukol 4/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Domaci_ukol_4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Domaci_ukol_4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Domaci_ukol_4.dir/build: Domaci_ukol_4

.PHONY : CMakeFiles/Domaci_ukol_4.dir/build

CMakeFiles/Domaci_ukol_4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Domaci_ukol_4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Domaci_ukol_4.dir/clean

CMakeFiles/Domaci_ukol_4.dir/depend:
	cd "/home/mike/PA1/Domaci ukol 4/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/mike/PA1/Domaci ukol 4" "/home/mike/PA1/Domaci ukol 4" "/home/mike/PA1/Domaci ukol 4/cmake-build-debug" "/home/mike/PA1/Domaci ukol 4/cmake-build-debug" "/home/mike/PA1/Domaci ukol 4/cmake-build-debug/CMakeFiles/Domaci_ukol_4.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Domaci_ukol_4.dir/depend

