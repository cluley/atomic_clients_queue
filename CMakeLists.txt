cmake_minimum_required(VERSION 3.22.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(Atomic_CQ)

add_executable(Atomic_CQ main.cpp queue.h queue.cpp)