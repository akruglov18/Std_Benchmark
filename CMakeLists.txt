cmake_minimum_required(VERSION 3.15)
project(Benchmark)

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
set(CMAKE_CXX_FLAGS "-O3")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

add_executable(Benchmark main.cpp vector.h unordered_map.h map.h list.h deque.h set.h)
