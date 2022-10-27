# 'Google_test' is the subproject name
project(Google_Tests_run)
add_executable(Google_Tests_run test.cpp)

# 'lib' is the folder with Google Test sources

#include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
#target_link_libraries(Google_Tests_run gtest gtest_main)



add_test(NAME Google_Tests_run COMMAND Google_Tests_run)

target_link_libraries(Google_Tests_run PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)

