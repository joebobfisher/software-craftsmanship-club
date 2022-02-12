cmake_minimum_required(VERSION 3.16)
project(arithmetic)

set(CMAKE_CXX_STANDARD 11)

# cmake 3.16 doesn't support setting the toolchain via VS Code's extension. ¯\_(ツ)_/¯
# use these options for cross-compiling to Windows from WSL
set(CMAKE_SYSTEM_NAME Windows)
SET(CMAKE_C_COMPILER x86_64-w64-mingw32-gcc)
SET(CMAKE_CXX_COMPILER x86_64-w64-mingw32-g++)
SET(CMAKE_RC_COMPILER x86_64-w64-mingw32-windres)
set(CMAKE_RANLIB x86_64-w64-mingw32-ranlib)

set(CLASS_FILES)

add_executable(arithmetic.exe main.cpp ${CLASS_FILES})