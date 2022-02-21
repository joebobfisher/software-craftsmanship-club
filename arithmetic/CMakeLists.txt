cmake_minimum_required(VERSION 3.16)
project(arithmetic)

set(CMAKE_CXX_STANDARD 11)

# cmake 3.16 doesn't support setting the toolchain via VS Code's extension. ¯\_(ツ)_/¯
# use these options for cross-compiling to Windows from WSL
# set(CMAKE_SYSTEM_NAME Windows)
# set(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
# set(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
# set(CMAKE_RC_COMPILER x86_64-w64-mingw32-windres)
# set(CMAKE_RANLIB x86_64-w64-mingw32-ranlib)

include_directories(Arithmetic)

set(CLASS_FILES
        Arithmetic/Arithmetic.h
        Arithmetic/Arithmetic.cpp)

add_executable(arithmetic main.cpp ${CLASS_FILES})