project(google_tests)

add_subdirectory(lib)
include_directories(
        ${gtest_SOURCE_DIR}
        ${gtest_SOURCE_DIR}/include
        ${gmock_SOURCE_DIR}
        ${gmock_SOURCE_DIR}/include)

set(TEST_FILES
        MazeTests.cpp
        MazeSolverTests.cpp
        RouteFinderTests.cpp
        RouteMarkerTests.cpp)
add_executable(google_tests_run ${TEST_FILES})

target_link_libraries(google_tests_run gtest gtest_main)
target_link_libraries(google_tests_run tiny-maze_lib)