project(google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_FILES RoverTests.cpp ArgLoaderTests.cpp)
add_executable(google_tests_run ${TEST_FILES})

target_link_libraries(google_tests_run rover_lib)
target_link_libraries(google_tests_run gtest gtest_main)