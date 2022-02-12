project(google_tests)

add_subdirectory(lib)

set(TEST_FILES ArithmeticTests.cpp)
add_executable(google_tests_run ${TEST_FILES})

target_include_directories(google_tests_run PUBLIC ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

target_link_libraries(google_tests_run gtest gtest_main)
target_link_libraries(google_tests_run arithmetic_lib)