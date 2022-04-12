cmake_minimum_required(VERSION 3.16)
project(password)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        PasswordKeeper
        PasswordObject
        Rules/RuleChecker
        Rules/PasswordRules
        Rules/Rule
        Exceptions)

set(CLASS_FILES
        PasswordKeeper/PasswordKeeper.cpp
        Rules/RuleChecker/RuleChecker.cpp)

add_executable(password main.cpp ${CLASS_FILES})
