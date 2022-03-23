cmake_minimum_required(VERSION 3.16)
project(PasswordObject)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        PasswordKeeper
        PasswordObject
        Exceptions)

set(CLASS_FILES
        PasswordKeeper/PasswordKeeper.cpp
        PasswordKeeper/PasswordKeeper.h
        PasswordObject/PasswordObject.h
        Exceptions/PasswordExceptions.h
        Exceptions/PasswordException.h
        Exceptions/PasswordTooShortException.h)

add_executable(PasswordObject main.cpp ${CLASS_FILES})
