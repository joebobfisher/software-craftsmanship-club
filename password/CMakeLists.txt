cmake_minimum_required(VERSION 3.16)
project(password)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        PasswordKeeper
        Password
        Exceptions)

set(CLASS_FILES
        PasswordKeeper/PasswordKeeper.cpp
        PasswordKeeper/PasswordKeeper.h
        Password/Password.h
        Exceptions/PasswordExceptions.h
        Exceptions/PasswordException.h
        Exceptions/PasswordTooShortException.h)

add_executable(password main.cpp ${CLASS_FILES})
