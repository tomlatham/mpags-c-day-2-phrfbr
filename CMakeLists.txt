# - Main CMake buildscript for mpags cipher
# Comments in a CMake Script are lines beginning with a '#'

# Not going to write all comments yet, see slide 4


# - Set CMake requrements then declare project

cmake_minimum_required(VERSION 3.2)
project(MPAGSCipher VERSION 0.1.0)

# - When MakeFiles are generated, output all comman lines by default
# Do this to begin with so it's easy to see what compiler command/flags
# are used. This can also be done by removing the 'set' command and
# running make as a 'make VERBOSE=1'

set (CMAKE_VERBOSE_MAKEFILE ON)

#  Don't allow c++ Compiler Vendor Extensions
set (CMAKE_CXX_EXTENSIONS OFF)

# - Use our standard set of flags for the GNU/Clang compilers
set (CMAKE_CXX_FLAGS "-Wall -Werror -Wfatal-errors -Wshadow -pedantic") 

# - Declare the build of mpags-cipher main program

add_executable(mpags-cipher mpags-cipher.cpp MPAGSCipher/TransformChar.hpp MPAGSCipher/TransformChar.cpp  MPAGSCipher/processCommandLine.hpp MPAGSCipher/processCommandLine.cpp MPAGSCipher/runCaeserCipher.cpp MPAGSCipher/runCaeserCipher.hpp)

target_include_directories(mpags-cipher PRIVATE MPAGSCipher)

target_compile_features(mpags-cipher PRIVATE cxx_auto_type cxx_range_for cxx_uniform_initialization)




