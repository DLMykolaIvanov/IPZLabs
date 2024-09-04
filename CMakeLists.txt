cmake_minimum_required(VERSION 3.29)
project(IPZLabs)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(IPZLabs
    l1.cxx)
