cmake_minimum_required(VERSION 3.2)
project(src)
set(CMAKE_CXX_STANDARD 17)
add_library(${PROJECT_NAME}
        parsing.h
        parsing.cpp
        poly.h
        poly.cpp)