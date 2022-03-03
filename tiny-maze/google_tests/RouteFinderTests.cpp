#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma ide diagnostic ignored "cppcoreguidelines-avoid-non-const-global-variables"
#pragma ide diagnostic ignored "cppcoreguidelines-owning-memory"
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "cppcoreguidelines-avoid-goto"
#pragma ide diagnostic ignored "cppcoreguidelines-non-private-member-variables-in-classes"

#include "gtest/gtest.h"
#include "gmock/gmock-matchers.h"
#include "RouteFinder.h"

class RouteFinderTest : public ::testing::Test {
protected:
    void SetUp() override;

    std::vector<std::vector<char>> givenMaze;
    Maze maze;

    RouteFinder target;
};

void RouteFinderTest::SetUp() {
    givenMaze = { { 'S', '0' }, { '1', 'E' } };
    maze = Maze(givenMaze);

    // TODO get this working
    target = RouteFinder(maze);

    // TODO need to mock maze!
}

TEST_F(RouteFinderTest, FindRouteCallsInitializeMaze) {

}

//TEST_F(RouteFinderTest, FindRouteSetsVisitedList) {
//    std::vector<std::vector<bool>> expected = { { true, true }, { false, true } };
//    RouteFinder target = RouteFinder(givenMaze);
//
//    target.FindRoute();
//
//    auto actual = target.GetVisitedList();
//    EXPECT_THAT(actual, testing::ElementsAreArray(expected));
//}
//
//TEST_F(RouteFinderTest, FindRouteSetsRouteStackToFoundRoute) {
//    std::vector<std::pair<int, int>> expected = { { 0, 0 }, { 0, 1 }, { 1, 1 } };
//    RouteFinder target = RouteFinder(givenMaze);
//
//    target.FindRoute();
//
//    auto actual = target.GetRouteStack();
//    EXPECT_THAT(actual, testing::ElementsAreArray(expected));
//}
//
//TEST_F(RouteFinderTest, FindRouteEmptysRouteStackWhenNoRouteFound) {
//    std::vector<std::pair<int, int>> expected = {};
//    givenMaze = { { 'S', '1' }, { '1', 'E' } };
//    RouteFinder target = RouteFinder(givenMaze);
//
//    target.FindRoute();
//
//    auto actual = target.GetRouteStack();
//    EXPECT_THAT(actual, testing::ElementsAreArray(expected));
//}

#pragma clang diagnostic pop