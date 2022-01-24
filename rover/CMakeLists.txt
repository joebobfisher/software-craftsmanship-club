cmake_minimum_required(VERSION 3.0.0)
project(rover VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

include_directories(Rover ArgLoader)
set(CLASS_FILES Rover/Rover.cpp Rover/Rover.h ArgLoader/ArgLoader.cpp ArgLoader/ArgLoader.h)

add_executable(rover main.cpp ${CLASS_FILES})
add_library(rover_lib ${CLASS_FILES})

add_subdirectory(google_tests)
