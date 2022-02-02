cmake_minimum_required(VERSION 3.21)
project(alphabet_cipher)

set(CMAKE_CXX_STANDARD 11)

set(BOOST_DIR "C:\\Program Files\\boost\\boost_1_78_0")
include_directories("${BOOST_DIR}\\include\\boost-1_78")
link_libraries("${BOOST_DIR}\\lib\\libboost_program_options-mgw11-mt-sd-x64-1_78.a")

add_executable(alphabet_cipher main.cpp)