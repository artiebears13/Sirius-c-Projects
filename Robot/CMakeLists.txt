cmake_minimum_required(VERSION 3.20)
project(Robot)

set(CMAKE_CXX_STANDARD 14)

add_executable(Robot src/main.cpp src/robot.cpp src/robot.h src/import_data.cpp src/parser.h src/errors_processing.h src/parser.cpp src/error_processing.cpp)

add_library(robot_lib src/robot.cpp)
target_link_libraries(Robot robot_lib)

