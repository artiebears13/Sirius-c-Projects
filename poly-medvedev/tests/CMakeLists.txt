cmake_minimum_required(VERSION 3.4)
project(mytest)

find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

add_executable(mytest tests.cpp ../src/poly.h ../src/poly.cpp)
target_link_libraries(mytest Threads::Threads ${GTEST_LIBRARIES})


# enable testing functionality
enable_testing()

# define tests
add_test(
        NAME mytest
        COMMAND mytest
)
