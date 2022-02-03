cmake_minimum_required(VERSION 3.21)
project(alphabet_cipher)

set(CMAKE_CXX_STANDARD 11)

set(BOOST_ROOT "C:/Program Files/boost/boost_1_78_0")
set(Boost_USE_STATIC_LIBS ON)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)
find_package(Boost REQUIRED COMPONENTS program_options)

add_executable(alphabet_cipher main.cpp)
target_include_directories(alphabet_cipher PUBLIC ${Boost_INCLUDE_DIRS})
target_link_libraries(alphabet_cipher ${Boost_LIBRARIES})