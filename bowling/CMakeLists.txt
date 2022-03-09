cmake_minimum_required(VERSION 3.16)
project(bowling)

set(CMAKE_CXX_STANDARD 11)

include_directories()

set(CLASS_FILES)

add_executable(bowling main.cpp ${CLASS_FILES})
