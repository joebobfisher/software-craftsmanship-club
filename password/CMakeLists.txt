cmake_minimum_required(VERSION 3.16)
project(password)

set(CMAKE_CXX_STANDARD 11)

include_directories(
        PasswordKeeper
        PasswordObject
        Rules/PasswordRuleChecker
        Rules/PasswordRules
        Rules/UsernameRuleChecker
        Rules/Rule
        Exceptions)

set(CLASS_FILES
        PasswordKeeper/PasswordKeeper.cpp
        Rules/PasswordRuleChecker/PasswordRuleChecker.cpp
        Rules/UsernameRuleChecker/UsernameRuleChecker.cpp
        Rules/PasswordRules/PasswordMinLengthRule/PasswordMinLengthRule.cpp
        Rules/PasswordRules/PasswordMaxLengthRule/PasswordMaxLengthRule.cpp)

add_executable(password main.cpp ${CLASS_FILES})
