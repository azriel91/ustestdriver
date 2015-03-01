# This CMakeLists.txt file helps defining your block building and compiling
# Include the main biicode macros and functions
# To learn more about the CMake use with biicode, visit http://docs.biicode.com/c++/building.html
project(usTestDriver)

cmake_minimum_required(VERSION 2.8)

# Initializes block variables
INIT_BIICODE_BLOCK()

# Actually create targets: executables and libraries.
ADD_BIICODE_TARGETS()
