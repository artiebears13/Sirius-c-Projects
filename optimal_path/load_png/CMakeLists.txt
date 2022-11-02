cmake_minimum_required(VERSION 3.2)
project(lodepng)
set(CMAKE_CXX_STANDARD 17)
add_library(${PROJECT_NAME} lodepng.cpp lodepng.h)
