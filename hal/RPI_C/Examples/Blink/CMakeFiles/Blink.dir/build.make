# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_SOURCE_DIR = /home/pi/jonathan/InterrogatorRaspi/hal/RPI_C/Examples/Blink/Source

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/jonathan/InterrogatorRaspi/hal/RPI_C/Examples/Blink

# Include any dependencies generated for this target.
include CMakeFiles/Blink.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Blink.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Blink.dir/flags.make

CMakeFiles/Blink.dir/main.c.o: CMakeFiles/Blink.dir/flags.make
CMakeFiles/Blink.dir/main.c.o: Source/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/jonathan/InterrogatorRaspi/hal/RPI_C/Examples/Blink/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Blink.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Blink.dir/main.c.o   -c /home/pi/jonathan/InterrogatorRaspi/hal/RPI_C/Examples/Blink/Source/main.c

CMakeFiles/Blink.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Blink.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/jonathan/InterrogatorRaspi/hal/RPI_C/Examples/Blink/Source/main.c > CMakeFiles/Blink.dir/main.c.i

CMakeFiles/Blink.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Blink.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/jonathan/InterrogatorRaspi/hal/RPI_C/Examples/Blink/Source/main.c -o CMakeFiles/Blink.dir/main.c.s

CMakeFiles/Blink.dir/main.c.o.requires:

.PHONY : CMakeFiles/Blink.dir/main.c.o.requires

CMakeFiles/Blink.dir/main.c.o.provides: CMakeFiles/Blink.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Blink.dir/build.make CMakeFiles/Blink.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Blink.dir/main.c.o.provides

CMakeFiles/Blink.dir/main.c.o.provides.build: CMakeFiles/Blink.dir/main.c.o


# Object files for target Blink
Blink_OBJECTS = \
"CMakeFiles/Blink.dir/main.c.o"

# External object files for target Blink
Blink_EXTERNAL_OBJECTS =

Blink: CMakeFiles/Blink.dir/main.c.o
Blink: CMakeFiles/Blink.dir/build.make
Blink: CMakeFiles/Blink.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/jonathan/InterrogatorRaspi/hal/RPI_C/Examples/Blink/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Blink"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Blink.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Blink.dir/build: Blink

.PHONY : CMakeFiles/Blink.dir/build

CMakeFiles/Blink.dir/requires: CMakeFiles/Blink.dir/main.c.o.requires

.PHONY : CMakeFiles/Blink.dir/requires

CMakeFiles/Blink.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Blink.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Blink.dir/clean

CMakeFiles/Blink.dir/depend:
	cd /home/pi/jonathan/InterrogatorRaspi/hal/RPI_C/Examples/Blink && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/jonathan/InterrogatorRaspi/hal/RPI_C/Examples/Blink/Source /home/pi/jonathan/InterrogatorRaspi/hal/RPI_C/Examples/Blink/Source /home/pi/jonathan/InterrogatorRaspi/hal/RPI_C/Examples/Blink /home/pi/jonathan/InterrogatorRaspi/hal/RPI_C/Examples/Blink /home/pi/jonathan/InterrogatorRaspi/hal/RPI_C/Examples/Blink/CMakeFiles/Blink.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Blink.dir/depend

