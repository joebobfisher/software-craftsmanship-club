cmake_minimum_required(VERSION 3.16)
project(rover-redux)

set(CMAKE_CXX_STANDARD 11)

include_directories()

set(CLASS_FILES)

add_executable(rover-redux main.cpp ${CLASS_FILES})
