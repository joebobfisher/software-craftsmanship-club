cmake_minimum_required(VERSION 3.21)
project(fizzbuzz)

set(CMAKE_CXX_STANDARD 11)

include_directories(FizzBuzz)

set(CLASS_FILES
        FizzBuzz/FizzBuzz.cpp
        FizzBuzz/FizzBuzz.h)
add_executable(fizzbuzz ${CLASS_FILES} main.cpp)
add_library(FizzBuzz_lib ${CLASS_FILES})

add_subdirectory(google_tests)