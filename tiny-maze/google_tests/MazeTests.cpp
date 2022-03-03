#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma ide diagnostic ignored "cppcoreguidelines-avoid-non-const-global-variables"
#pragma ide diagnostic ignored "cppcoreguidelines-owning-memory"
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "cppcoreguidelines-avoid-goto"
#pragma ide diagnostic ignored "cppcoreguidelines-non-private-member-variables-in-classes"

#include "gtest/gtest.h"
#include "gmock/gmock-matchers.h"
#include "Maze.h"

class MazeTest : public ::testing::Test {
protected:
    void SetUp() override;

    std::vector<std::vector<char>> givenMaze;
};

void MazeTest::SetUp() {
     givenMaze = { { 'S', '0' }, { '1', 'E' } };
}

// TODO(joe): add vertical space to each of these tests (setup-run-test)
TEST_F(MazeTest, ConstructorCopiesGivenMaze) {
    Maze target = Maze(givenMaze);

    auto actual = target.GetOriginalMaze();

    EXPECT_THAT(actual, testing::ElementsAreArray(givenMaze));
}

TEST_F(MazeTest, FindRouteSetsVisitedList) {
    std::vector<std::vector<bool>> expected = { { true, true }, { false, true } };
    Maze target = Maze(givenMaze);

    target.FindRoute();

    auto actual = target.GetVisitedList();
    EXPECT_THAT(actual, testing::ElementsAreArray(expected));
}

TEST_F(MazeTest, FindRouteSetsRouteStackToFoundRoute) {
    std::vector<std::pair<int, int>> expected = { { 0, 0 }, { 0, 1 }, { 1, 1 } };
    Maze target = Maze(givenMaze);

    target.FindRoute();

    auto actual = target.GetRouteStack();
    EXPECT_THAT(actual, testing::ElementsAreArray(expected));
}

TEST_F(MazeTest, FindRouteEmptysRouteStackWhenNoRouteFound) {
    std::vector<std::pair<int, int>> expected = {};
    givenMaze = { { 'S', '1' }, { '1', 'E' } };
    Maze target = Maze(givenMaze);

    target.FindRoute();

    auto actual = target.GetRouteStack();
    EXPECT_THAT(actual, testing::ElementsAreArray(expected));
}

TEST_F(MazeTest, SolveMazeReturnsMazeWithFoundRoute) {
    std::vector<std::vector<char>> expected { { 'x', 'x' }, { '1', 'x' } };
    Maze target = Maze(givenMaze);

    auto actual = target.SolveMaze();

    EXPECT_THAT(actual, testing::ElementsAreArray(expected));
}

TEST_F(MazeTest, SolveMazeReturnsMazeWithAllVisitedMarkedWhenNoRouteFound) {
    std::vector<std::vector<char>> expected = { { 'x', '1' }, { '1', 'E' } };
    givenMaze = { { 'S', '1' }, { '1', 'E' } };
    Maze target = Maze(givenMaze);

    auto actual = target.SolveMaze();

    EXPECT_THAT(actual, testing::ElementsAreArray(expected));
}

#pragma clang diagnostic pop
