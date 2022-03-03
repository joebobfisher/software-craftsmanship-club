cmake_minimum_required(VERSION 3.16)
project(tiny-maze)

set(CMAKE_CXX_STANDARD 11)

include_directories(Maze RouteFinder)

set(CLASS_FILES
        Maze/Maze.cpp
        Maze/Maze.h
        RouteFinder/RouteFinder.cpp
        RouteFinder/RouteFinder.h)

add_executable(tiny-maze main.cpp ${CLASS_FILES})
add_library(tiny-maze_lib ${CLASS_FILES})

add_subdirectory(google_tests)