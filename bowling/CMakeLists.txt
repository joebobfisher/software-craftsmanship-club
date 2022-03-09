cmake_minimum_required(VERSION 3.16)
project(bowling)

set(CMAKE_CXX_STANDARD 11)

include_directories(BowlScorer)

set(CLASS_FILES
        BowlScorer/BowlScorer.cpp
        BowlScorer/BowlScorer.h)

add_executable(bowling main.cpp ${CLASS_FILES})
