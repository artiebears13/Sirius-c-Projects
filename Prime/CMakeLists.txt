cmake_minimum_required(VERSION 3.23)
project(Prime)

set(CMAKE_CXX_STANDARD 17)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS_DEBUG "-Og -g -DDEBUG")
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -DNDEBUG -match=native")

add_executable(Prime main.cpp)
