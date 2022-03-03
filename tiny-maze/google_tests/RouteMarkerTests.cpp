#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma ide diagnostic ignored "cppcoreguidelines-avoid-non-const-global-variables"
#pragma ide diagnostic ignored "cppcoreguidelines-owning-memory"
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "cppcoreguidelines-avoid-goto"
#pragma ide diagnostic ignored "cppcoreguidelines-non-private-member-variables-in-classes"

#include "gtest/gtest.h"
#include "gmock/gmock-matchers.h"
#include "RouteMarker.h"

class RouteMarkerTest : public ::testing::Test {
protected:
    void SetUp() override;

    std::vector<std::vector<char>> givenMaze;
    std::vector<std::vector<bool>> givenVisitedNodes;
    std::vector<std::pair<int, int>> givenRouteStack;

    RouteMarker target;
};

void RouteMarkerTest::SetUp() {
    givenMaze = { { 'S', '0' }, { '1', 'E' } };
    givenVisitedNodes = { { true, true }, { false, true } };
    givenRouteStack = { { 0, 0 }, { 0, 1 }, { 1, 1 } };
}

TEST_F(RouteMarkerTest, MarkRouteMarksFoundRoute) {
    std::vector<std::vector<char>> expected = { { 'x', 'x' }, { '1', 'x' } };

    auto actual = target.MarkRoute(givenMaze, givenVisitedNodes, givenRouteStack);

    EXPECT_THAT(actual, testing::ElementsAreArray(expected));
}

TEST_F(RouteMarkerTest, MarkRouteMarksAllVisitedIfNoRouteFound) {
    givenMaze = { { 'S', '1' }, { '1', 'E' } };
    givenVisitedNodes = { { true, false }, { false, false } };
    givenRouteStack = {};
    std::vector<std::vector<char>> expected = { { 'x', '1' }, { '1', 'E' } };

    auto actual = target.MarkRoute(givenMaze, givenVisitedNodes, givenRouteStack);

    EXPECT_THAT(actual, testing::ElementsAreArray(expected));
}

#pragma clang diagnostic pop