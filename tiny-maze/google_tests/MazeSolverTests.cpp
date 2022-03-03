#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma ide diagnostic ignored "cppcoreguidelines-avoid-non-const-global-variables"
#pragma ide diagnostic ignored "cppcoreguidelines-owning-memory"
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "cppcoreguidelines-avoid-goto"
#pragma ide diagnostic ignored "cppcoreguidelines-non-private-member-variables-in-classes"

#include "gtest/gtest.h"
#include "gmock/gmock-matchers.h"
#include "MazeSolver.h"

class MazeSolverTest : public ::testing::Test {
protected:
    void SetUp() override;

    std::vector<std::vector<char>> givenMaze;

    // TODO mock routeFinder and routeMarker to test corner cases!
    RouteMarker routeMarker;
};

void MazeSolverTest::SetUp() {
     givenMaze = { { 'S', '0' }, { '1', 'E' } };
}

TEST_F(MazeSolverTest, ConstructorCopiesGivenMaze) {
    RouteFinder routeFinder(givenMaze);
    MazeSolver target = MazeSolver(givenMaze, routeFinder, routeMarker);

    auto actual = target.GetOriginalMaze();

    EXPECT_THAT(actual, testing::ElementsAreArray(givenMaze));
}

TEST_F(MazeSolverTest, SolveMazeReturnsMazeWithFoundRoute) {
    std::vector<std::vector<char>> expected { { 'x', 'x' }, { '1', 'x' } };
    RouteFinder routeFinder(givenMaze);
    MazeSolver target = MazeSolver(givenMaze, routeFinder, routeMarker);

    auto actual = target.SolveMaze();

    EXPECT_THAT(actual, testing::ElementsAreArray(expected));
}

TEST_F(MazeSolverTest, SolveMazeReturnsMazeWithAllVisitedMarkedWhenNoRouteFound) {
    std::vector<std::vector<char>> expected = { { 'x', '1' }, { '1', 'E' } };
    givenMaze = { { 'S', '1' }, { '1', 'E' } };
    RouteFinder routeFinder(givenMaze);
    MazeSolver target = MazeSolver(givenMaze, routeFinder, routeMarker);

    auto actual = target.SolveMaze();

    EXPECT_THAT(actual, testing::ElementsAreArray(expected));
}

#pragma clang diagnostic pop
