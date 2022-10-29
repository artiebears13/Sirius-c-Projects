cmake_minimum_required(VERSION 3.13)
project(inside_poly)

set(CMAKE_CXX_STANDARD 14)

add_executable(inside_poly src/main.cpp src/poly.cpp tests/tests.cpp)

add_library(inside_poly_lib src/poly.cpp)
target_link_libraries(inside_poly inside_poly_lib)

#inside_poly_libenable_testing()
#add_test(
#        NAME mytest
#        COMMAND $<TARGET_FILE:mytest>
#)