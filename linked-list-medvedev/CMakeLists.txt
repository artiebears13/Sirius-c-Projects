cmake_minimum_required(VERSION 3.20)
project(linked_list)

set(CMAKE_CXX_STANDARD 17)

add_executable(linked_list src/main.cpp src/list.cpp src/list.h)
