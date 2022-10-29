cmake_minimum_required(VERSION 3.23)
project(dot_position)

set(CMAKE_CXX_STANDARD 20)

add_executable(dot_position main.cpp solver.h solver.cpp)
