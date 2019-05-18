cmake_minimum_required(VERSION 3.2.1)
project (find_the_bug)

include(CMakeToolsHelpers OPTIONAL)
set(CMAKE_CXX_FLAGS "-O2 -Wall -Wextra -Wpedantic")
set(CMAKE_CXX_STANDARD 14)

add_subdirectory(tests)
add_subdirectory(src)

