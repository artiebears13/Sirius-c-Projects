cmake_minimum_required(VERSION 3.23)
project(optimal_path)

set(CMAKE_CXX_STANDARD 17)

add_executable(optimal_path main.cpp
        plotting.h
        plotting.cpp
        )
