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
CMAKE_SOURCE_DIR = /home/georgi5481/eclipse-workspace/Buttons_and_timers

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/georgi5481/eclipse-workspace/Buttons_and_timers/build

# Include any dependencies generated for this target.
include utils/CMakeFiles/utils.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include utils/CMakeFiles/utils.dir/compiler_depend.make

# Include the progress variables for this target.
include utils/CMakeFiles/utils.dir/progress.make

# Include the compile flags for this target's objects.
include utils/CMakeFiles/utils.dir/flags.make

utils/CMakeFiles/utils.dir/src/drawings/DrawParams.cpp.o: utils/CMakeFiles/utils.dir/flags.make
utils/CMakeFiles/utils.dir/src/drawings/DrawParams.cpp.o: ../utils/src/drawings/DrawParams.cpp
utils/CMakeFiles/utils.dir/src/drawings/DrawParams.cpp.o: utils/CMakeFiles/utils.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/georgi5481/eclipse-workspace/Buttons_and_timers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object utils/CMakeFiles/utils.dir/src/drawings/DrawParams.cpp.o"
	cd /home/georgi5481/eclipse-workspace/Buttons_and_timers/build/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT utils/CMakeFiles/utils.dir/src/drawings/DrawParams.cpp.o -MF CMakeFiles/utils.dir/src/drawings/DrawParams.cpp.o.d -o CMakeFiles/utils.dir/src/drawings/DrawParams.cpp.o -c /home/georgi5481/eclipse-workspace/Buttons_and_timers/utils/src/drawings/DrawParams.cpp

utils/CMakeFiles/utils.dir/src/drawings/DrawParams.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utils.dir/src/drawings/DrawParams.cpp.i"
	cd /home/georgi5481/eclipse-workspace/Buttons_and_timers/build/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/georgi5481/eclipse-workspace/Buttons_and_timers/utils/src/drawings/DrawParams.cpp > CMakeFiles/utils.dir/src/drawings/DrawParams.cpp.i

utils/CMakeFiles/utils.dir/src/drawings/DrawParams.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utils.dir/src/drawings/DrawParams.cpp.s"
	cd /home/georgi5481/eclipse-workspace/Buttons_and_timers/build/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/georgi5481/eclipse-workspace/Buttons_and_timers/utils/src/drawings/DrawParams.cpp -o CMakeFiles/utils.dir/src/drawings/DrawParams.cpp.s

utils/CMakeFiles/utils.dir/src/drawings/Point.cpp.o: utils/CMakeFiles/utils.dir/flags.make
utils/CMakeFiles/utils.dir/src/drawings/Point.cpp.o: ../utils/src/drawings/Point.cpp
utils/CMakeFiles/utils.dir/src/drawings/Point.cpp.o: utils/CMakeFiles/utils.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/georgi5481/eclipse-workspace/Buttons_and_timers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object utils/CMakeFiles/utils.dir/src/drawings/Point.cpp.o"
	cd /home/georgi5481/eclipse-workspace/Buttons_and_timers/build/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT utils/CMakeFiles/utils.dir/src/drawings/Point.cpp.o -MF CMakeFiles/utils.dir/src/drawings/Point.cpp.o.d -o CMakeFiles/utils.dir/src/drawings/Point.cpp.o -c /home/georgi5481/eclipse-workspace/Buttons_and_timers/utils/src/drawings/Point.cpp

utils/CMakeFiles/utils.dir/src/drawings/Point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utils.dir/src/drawings/Point.cpp.i"
	cd /home/georgi5481/eclipse-workspace/Buttons_and_timers/build/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/georgi5481/eclipse-workspace/Buttons_and_timers/utils/src/drawings/Point.cpp > CMakeFiles/utils.dir/src/drawings/Point.cpp.i

utils/CMakeFiles/utils.dir/src/drawings/Point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utils.dir/src/drawings/Point.cpp.s"
	cd /home/georgi5481/eclipse-workspace/Buttons_and_timers/build/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/georgi5481/eclipse-workspace/Buttons_and_timers/utils/src/drawings/Point.cpp -o CMakeFiles/utils.dir/src/drawings/Point.cpp.s

utils/CMakeFiles/utils.dir/src/drawings/Color.cpp.o: utils/CMakeFiles/utils.dir/flags.make
utils/CMakeFiles/utils.dir/src/drawings/Color.cpp.o: ../utils/src/drawings/Color.cpp
utils/CMakeFiles/utils.dir/src/drawings/Color.cpp.o: utils/CMakeFiles/utils.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/georgi5481/eclipse-workspace/Buttons_and_timers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object utils/CMakeFiles/utils.dir/src/drawings/Color.cpp.o"
	cd /home/georgi5481/eclipse-workspace/Buttons_and_timers/build/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT utils/CMakeFiles/utils.dir/src/drawings/Color.cpp.o -MF CMakeFiles/utils.dir/src/drawings/Color.cpp.o.d -o CMakeFiles/utils.dir/src/drawings/Color.cpp.o -c /home/georgi5481/eclipse-workspace/Buttons_and_timers/utils/src/drawings/Color.cpp

utils/CMakeFiles/utils.dir/src/drawings/Color.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utils.dir/src/drawings/Color.cpp.i"
	cd /home/georgi5481/eclipse-workspace/Buttons_and_timers/build/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/georgi5481/eclipse-workspace/Buttons_and_timers/utils/src/drawings/Color.cpp > CMakeFiles/utils.dir/src/drawings/Color.cpp.i

utils/CMakeFiles/utils.dir/src/drawings/Color.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utils.dir/src/drawings/Color.cpp.s"
	cd /home/georgi5481/eclipse-workspace/Buttons_and_timers/build/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/georgi5481/eclipse-workspace/Buttons_and_timers/utils/src/drawings/Color.cpp -o CMakeFiles/utils.dir/src/drawings/Color.cpp.s

utils/CMakeFiles/utils.dir/src/drawings/Rectangle.cpp.o: utils/CMakeFiles/utils.dir/flags.make
utils/CMakeFiles/utils.dir/src/drawings/Rectangle.cpp.o: ../utils/src/drawings/Rectangle.cpp
utils/CMakeFiles/utils.dir/src/drawings/Rectangle.cpp.o: utils/CMakeFiles/utils.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/georgi5481/eclipse-workspace/Buttons_and_timers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object utils/CMakeFiles/utils.dir/src/drawings/Rectangle.cpp.o"
	cd /home/georgi5481/eclipse-workspace/Buttons_and_timers/build/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT utils/CMakeFiles/utils.dir/src/drawings/Rectangle.cpp.o -MF CMakeFiles/utils.dir/src/drawings/Rectangle.cpp.o.d -o CMakeFiles/utils.dir/src/drawings/Rectangle.cpp.o -c /home/georgi5481/eclipse-workspace/Buttons_and_timers/utils/src/drawings/Rectangle.cpp

utils/CMakeFiles/utils.dir/src/drawings/Rectangle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utils.dir/src/drawings/Rectangle.cpp.i"
	cd /home/georgi5481/eclipse-workspace/Buttons_and_timers/build/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/georgi5481/eclipse-workspace/Buttons_and_timers/utils/src/drawings/Rectangle.cpp > CMakeFiles/utils.dir/src/drawings/Rectangle.cpp.i

utils/CMakeFiles/utils.dir/src/drawings/Rectangle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utils.dir/src/drawings/Rectangle.cpp.s"
	cd /home/georgi5481/eclipse-workspace/Buttons_and_timers/build/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/georgi5481/eclipse-workspace/Buttons_and_timers/utils/src/drawings/Rectangle.cpp -o CMakeFiles/utils.dir/src/drawings/Rectangle.cpp.s

utils/CMakeFiles/utils.dir/src/thread/ThreadUtils.cpp.o: utils/CMakeFiles/utils.dir/flags.make
utils/CMakeFiles/utils.dir/src/thread/ThreadUtils.cpp.o: ../utils/src/thread/ThreadUtils.cpp
utils/CMakeFiles/utils.dir/src/thread/ThreadUtils.cpp.o: utils/CMakeFiles/utils.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/georgi5481/eclipse-workspace/Buttons_and_timers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object utils/CMakeFiles/utils.dir/src/thread/ThreadUtils.cpp.o"
	cd /home/georgi5481/eclipse-workspace/Buttons_and_timers/build/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT utils/CMakeFiles/utils.dir/src/thread/ThreadUtils.cpp.o -MF CMakeFiles/utils.dir/src/thread/ThreadUtils.cpp.o.d -o CMakeFiles/utils.dir/src/thread/ThreadUtils.cpp.o -c /home/georgi5481/eclipse-workspace/Buttons_and_timers/utils/src/thread/ThreadUtils.cpp

utils/CMakeFiles/utils.dir/src/thread/ThreadUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utils.dir/src/thread/ThreadUtils.cpp.i"
	cd /home/georgi5481/eclipse-workspace/Buttons_and_timers/build/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/georgi5481/eclipse-workspace/Buttons_and_timers/utils/src/thread/ThreadUtils.cpp > CMakeFiles/utils.dir/src/thread/ThreadUtils.cpp.i

utils/CMakeFiles/utils.dir/src/thread/ThreadUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utils.dir/src/thread/ThreadUtils.cpp.s"
	cd /home/georgi5481/eclipse-workspace/Buttons_and_timers/build/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/georgi5481/eclipse-workspace/Buttons_and_timers/utils/src/thread/ThreadUtils.cpp -o CMakeFiles/utils.dir/src/thread/ThreadUtils.cpp.s

utils/CMakeFiles/utils.dir/src/Time/Time.cpp.o: utils/CMakeFiles/utils.dir/flags.make
utils/CMakeFiles/utils.dir/src/Time/Time.cpp.o: ../utils/src/Time/Time.cpp
utils/CMakeFiles/utils.dir/src/Time/Time.cpp.o: utils/CMakeFiles/utils.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/georgi5481/eclipse-workspace/Buttons_and_timers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object utils/CMakeFiles/utils.dir/src/Time/Time.cpp.o"
	cd /home/georgi5481/eclipse-workspace/Buttons_and_timers/build/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT utils/CMakeFiles/utils.dir/src/Time/Time.cpp.o -MF CMakeFiles/utils.dir/src/Time/Time.cpp.o.d -o CMakeFiles/utils.dir/src/Time/Time.cpp.o -c /home/georgi5481/eclipse-workspace/Buttons_and_timers/utils/src/Time/Time.cpp

utils/CMakeFiles/utils.dir/src/Time/Time.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/utils.dir/src/Time/Time.cpp.i"
	cd /home/georgi5481/eclipse-workspace/Buttons_and_timers/build/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/georgi5481/eclipse-workspace/Buttons_and_timers/utils/src/Time/Time.cpp > CMakeFiles/utils.dir/src/Time/Time.cpp.i

utils/CMakeFiles/utils.dir/src/Time/Time.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/utils.dir/src/Time/Time.cpp.s"
	cd /home/georgi5481/eclipse-workspace/Buttons_and_timers/build/utils && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/georgi5481/eclipse-workspace/Buttons_and_timers/utils/src/Time/Time.cpp -o CMakeFiles/utils.dir/src/Time/Time.cpp.s

# Object files for target utils
utils_OBJECTS = \
"CMakeFiles/utils.dir/src/drawings/DrawParams.cpp.o" \
"CMakeFiles/utils.dir/src/drawings/Point.cpp.o" \
"CMakeFiles/utils.dir/src/drawings/Color.cpp.o" \
"CMakeFiles/utils.dir/src/drawings/Rectangle.cpp.o" \
"CMakeFiles/utils.dir/src/thread/ThreadUtils.cpp.o" \
"CMakeFiles/utils.dir/src/Time/Time.cpp.o"

# External object files for target utils
utils_EXTERNAL_OBJECTS =

utils/libutils.a: utils/CMakeFiles/utils.dir/src/drawings/DrawParams.cpp.o
utils/libutils.a: utils/CMakeFiles/utils.dir/src/drawings/Point.cpp.o
utils/libutils.a: utils/CMakeFiles/utils.dir/src/drawings/Color.cpp.o
utils/libutils.a: utils/CMakeFiles/utils.dir/src/drawings/Rectangle.cpp.o
utils/libutils.a: utils/CMakeFiles/utils.dir/src/thread/ThreadUtils.cpp.o
utils/libutils.a: utils/CMakeFiles/utils.dir/src/Time/Time.cpp.o
utils/libutils.a: utils/CMakeFiles/utils.dir/build.make
utils/libutils.a: utils/CMakeFiles/utils.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/georgi5481/eclipse-workspace/Buttons_and_timers/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libutils.a"
	cd /home/georgi5481/eclipse-workspace/Buttons_and_timers/build/utils && $(CMAKE_COMMAND) -P CMakeFiles/utils.dir/cmake_clean_target.cmake
	cd /home/georgi5481/eclipse-workspace/Buttons_and_timers/build/utils && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/utils.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
utils/CMakeFiles/utils.dir/build: utils/libutils.a
.PHONY : utils/CMakeFiles/utils.dir/build

utils/CMakeFiles/utils.dir/clean:
	cd /home/georgi5481/eclipse-workspace/Buttons_and_timers/build/utils && $(CMAKE_COMMAND) -P CMakeFiles/utils.dir/cmake_clean.cmake
.PHONY : utils/CMakeFiles/utils.dir/clean

utils/CMakeFiles/utils.dir/depend:
	cd /home/georgi5481/eclipse-workspace/Buttons_and_timers/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/georgi5481/eclipse-workspace/Buttons_and_timers /home/georgi5481/eclipse-workspace/Buttons_and_timers/utils /home/georgi5481/eclipse-workspace/Buttons_and_timers/build /home/georgi5481/eclipse-workspace/Buttons_and_timers/build/utils /home/georgi5481/eclipse-workspace/Buttons_and_timers/build/utils/CMakeFiles/utils.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : utils/CMakeFiles/utils.dir/depend

