cmake_minimum_required(VERSION 3.23)
project(dot_position)

set(CMAKE_CXX_STANDARD 20)

add_executable(dot_position src/main.cpp src/solver.h src/solver.cpp src/parser.cpp src/parser.h src/errors_processing.h src/error_processing.cpp)
