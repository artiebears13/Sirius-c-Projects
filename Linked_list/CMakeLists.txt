cmake_minimum_required(VERSION 3.23)
project(Linked_list)

set(CMAKE_CXX_STANDARD 17)

add_executable(Linked_list src/main.cpp
        src/linked_list.cpp
        src/linked_list.h)
