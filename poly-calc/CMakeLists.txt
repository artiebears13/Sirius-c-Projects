cmake_minimum_required(VERSION 3.23)
project(poly_calc)

set(CMAKE_CXX_STANDARD 17)

add_executable(poly_calc main.cpp)

add_subdirectory(src)
target_link_libraries(poly_calc src)