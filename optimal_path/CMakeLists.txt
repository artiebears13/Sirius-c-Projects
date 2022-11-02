cmake_minimum_required(VERSION 3.2)
project(main)
set(CMAKE_CXX_STANDARD 17)
add_executable(
${PROJECT_NAME} src/main.cpp
)
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/load_png PUBLIC ${PROJECT_SOURCE_DIR}/src)
add_subdirectory(load_png)
add_subdirectory(src)
target_link_libraries(${PROJECT_NAME} lodepng)
target_link_libraries(${PROJECT_NAME} src)