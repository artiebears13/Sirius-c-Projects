cmake_minimum_required(VERSION 3.23)
project(hello)

set(CMAKE_CXX_STANDARD 14)

add_library(hello hello.cpp hello.h)
add_executable(main main.cpp)
target_link_libraries(main hello)
