cmake_minimum_required(VERSION 3.16)
project(password)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        PasswordKeeper
        PasswordObject
        Exceptions)

set(CLASS_FILES
        PasswordKeeper/PasswordKeeper.cpp
        PasswordKeeper/PasswordKeeper.h
        PasswordObject/PasswordObject.h
        Exceptions/PasswordExceptions.h)

add_executable(password main.cpp ${CLASS_FILES})
