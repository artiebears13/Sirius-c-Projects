cmake_minimum_required(VERSION 3.23)
project(hello)

set(CMAKE_CXX_STANDARD 14)

add_executable(hello main.cpp hello.h hello.cpp)

