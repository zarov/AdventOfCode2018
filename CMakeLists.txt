cmake_minimum_required (VERSION 3.13.4)
project (AdventOfCode2018)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

set (CMAKE_C_COMPILER "clang")
set (CMAKE_CXX_COMPILER "clang++")

include_directories (${PROJECT_SOURCE_DIR}/src)

add_executable (day01.out src/day01.cpp)
add_executable (day02.out src/day02.cpp)
add_executable (day03.out src/day03.cpp)
