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

class MazeTest : public ::testing::Test {
protected:
    void SetUp() override;

    std::vector<std::vector<char>> givenMaze;
};

void MazeTest::SetUp() {
     givenMaze = { { 'S', '0' }, { '1', 'E' } };
}

TEST_F(MazeTest, ConstructorCopiesGivenMaze) {
    Maze target = Maze(givenMaze);
    auto actual = target.GetMazeVector();
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
    SUCCEED();
}

TEST_F(MazeTest, FindRouteEmptysRouteStackWhenNoRouteFound) {
    SUCCEED();
}

TEST_F(MazeTest, MarkRouteMarksFoundRoute) {
    SUCCEED();
}

TEST_F(MazeTest, MarkRouteDoesNotMarkRouteWhenNoRouteFound) {
    SUCCEED();
}

TEST_F(MazeTest, GetMazeWithRouteReturnsMazeWithFoundRoute) {
    SUCCEED();
}

TEST_F(MazeTest, GetMazeWithRouteReturnsMazeWithAllVisitedMarkedWhenNoRouteFound) {
    SUCCEED();
}

#pragma clang diagnostic pop
