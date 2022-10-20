cmake_minimum_required(VERSION 3.23)
project(prime_check)

set(CMAKE_CXX_STANDARD 14)

add_executable(prime_check main.cpp is_prime.cpp is_prime.h)
