cmake_minimum_required(VERSION 2.8)
project(hello)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-std=c++17")

add_executable(hello main.cpp)