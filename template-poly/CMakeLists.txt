cmake_minimum_required(VERSION 3.23)
project(template-poly)

set(CMAKE_CXX_STANDARD 17)

add_executable(template-poly main.cpp
        src/poly.hpp
        src/quat.hpp)


