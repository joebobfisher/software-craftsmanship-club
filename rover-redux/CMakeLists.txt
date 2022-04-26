cmake_minimum_required(VERSION 3.16)
project(rover-redux)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        Rover
        RoverPosition)

set(CLASS_FILES
        Rover/Rover.cpp)

add_executable(rover-redux main.cpp ${CLASS_FILES})
add_library(rover-redux-lib ${CLASS_FILES})

add_subdirectory(google_tests)
