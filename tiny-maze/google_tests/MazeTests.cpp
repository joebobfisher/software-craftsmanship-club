#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma ide diagnostic ignored "cppcoreguidelines-avoid-non-const-global-variables"
#pragma ide diagnostic ignored "cppcoreguidelines-owning-memory"
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "cppcoreguidelines-avoid-goto"
#pragma ide diagnostic ignored "cppcoreguidelines-non-private-member-variables-in-classes"

#include "gtest/gtest.h"
#include "gmock/gmock-matchers.h"
#include "../Maze/Maze.h"

TEST(MazeTests, ConstructorCopiesGivenMaze) {
    std::vector<std::vector<char>> expected = { { 'S', '0' }, { '1', 'E' } };
    Maze target = Maze(expected);
    auto actual = target.GetMazeVector();
    EXPECT_THAT(actual, testing::ElementsAreArray(expected));
}

TEST(MazeTests, ConstructorInitializesAdjacencyMap) {
    std::vector<std::vector<char>> maze = { { 'S', '0' }, { '1', 'E' } };
    std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> expected = {
            {{0,0}, {{0,1}}},
            {{0,1}, {{0,0}, {1,1}}},
            {{1,1}, {{0,1}}}
    };
    Maze target = Maze(maze);
    auto actual = target.GetMazeMap();
    EXPECT_THAT(actual, testing::ElementsAreArray(expected));
}

#pragma clang diagnostic pop
