cmake_minimum_required(VERSION 3.23)
project(dot_in_figure)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(lib/gtest)
add_subdirectory(test)
add_executable(dot_in_figure src/main.cpp src/Line.cpp src/Line.h src/solver.cpp src/solver.h test/test.cpp)
