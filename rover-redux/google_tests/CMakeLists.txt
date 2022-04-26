project(google_tests)

add_subdirectory(lib)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

include_directories(../MyRandom)

set(TEST_FILES RoverTests.cpp)
set(SUPPORT_FILES ../MyRandom/MyRandom.cpp)
add_executable(google_tests_run ${TEST_FILES} ${SUPPORT_FILES})

target_link_libraries(google_tests_run rover-redux-lib)
target_link_libraries(google_tests_run gtest gtest_main)