cmake_minimum_required(VERSION 3.20)
project(Robot)

set(CMAKE_CXX_STANDARD 17)

add_executable(Robot src/main.cpp src/robot.cpp src/robot.h src/plotting.h src/plotting.cpp)


