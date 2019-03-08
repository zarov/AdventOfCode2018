cmake_minimum_required (VERSION 3.10.1)
project (AdventOfCode2018)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")

set (CMAKE_C_COMPILER "clang")
set (CMAKE_CXX_COMPILER "clang++")

add_executable (advent.out
  src/main.cpp
  src/day01.cpp
  src/day02.cpp
  src/day03.cpp
  src/day04.cpp
  src/day05.cpp)
