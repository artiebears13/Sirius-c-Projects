cmake_minimum_required(VERSION 3.2)
project(src)
set(CMAKE_CXX_STANDARD 17)
add_library(${PROJECT_NAME}
        datas.h
        datas.cpp
        min_search.h
        min_search.cpp)