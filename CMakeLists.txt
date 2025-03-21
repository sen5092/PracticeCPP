cmake_minimum_required(VERSION 3.14)

set(CMAKE_POLICY_WARNING_CMP0074 OFF)

project(PracticeCPP VERSION 1.0)

# Default to Debug build type if not set
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add subdirectories
add_subdirectory(src)


enable_testing()
add_subdirectory(tests)