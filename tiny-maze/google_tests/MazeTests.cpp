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

    Maze target;
};

void MazeTest::SetUp() {
    givenMaze = { { 'S', '0' }, { '1', 'E' } };
    target = Maze(givenMaze);
    target.InitializeMaze();
}

TEST_F(MazeTest, ConstructorCreatesSeparateCopyOfMaze) {
    std::vector<std::vector<char>> original = { { 'S', '0' }, { '1', 'E' } };
    std::vector<std::vector<char>> expected = { { 'S', '0' }, { '1', 'A' } };

    givenMaze[1][1] = 'A';
    auto actual = target.GetMaze();

    EXPECT_THAT(givenMaze, testing::ElementsAreArray(expected));
    EXPECT_THAT(actual, testing::ElementsAreArray(original));
}

TEST_F(MazeTest, InitializeVisitedNodesSizesVisitedNodesVector) {
    int expected = 2;

    target.InitializeVisitedNodes();
    auto actual = target.GetVisitedList();

    EXPECT_EQ(actual.size(), expected);
    EXPECT_EQ(actual[0].size(), expected);
}

TEST_F(MazeTest, InitializeVisitedNodesSetsVisitedNodesToFalse) {
    std::vector<std::vector<bool>> expected = { { false, false }, { false, false } };

    target.InitializeVisitedNodes();
    auto actual = target.GetVisitedList();

    EXPECT_THAT(actual, testing::ElementsAreArray(expected));
}

TEST_F(MazeTest, InitialzeRouteStackClearsRouteStack) {
    bool expected = true;

    target.InitializeRouteStack();
    auto actual = target.GetRouteStack();

    EXPECT_EQ(actual.empty(), expected);
}

TEST_F(MazeTest, IsValidNodeReturnsTrueIfNodeIsValid) {
    bool expected = true;

    auto actual = target.IsVisitableNode(0, 1);

    EXPECT_EQ(actual, expected);
}

TEST_F(MazeTest, IsValidNodeReturnsFalseIfNodeIsOOR) {
    bool expected = false;

    auto actual = target.IsVisitableNode(2, 0);

    EXPECT_EQ(actual, expected);
}

TEST_F(MazeTest, IsValidNodeReturnsFalseIfNodeIs1) {
    bool expected = false;

    auto actual = target.IsVisitableNode(1, 0);

    EXPECT_EQ(actual, expected);
}

TEST_F(MazeTest, VisitNodeRecordsVisitedNode) {
    std::vector<std::vector<bool>> expected = { { false, true }, { false, false } };

    target.VisitNode(0, 1);
    auto actual = target.GetVisitedList();

    EXPECT_THAT(actual, testing::ElementsAreArray(expected));
}

TEST_F(MazeTest, VisitNodeDoesNotRecordInvalidNode) {
    std::vector<std::vector<bool>> expected = { { false, false }, { false, false } };

    target.VisitNode(3, 0);
    auto actual = target.GetVisitedList();

    EXPECT_THAT(actual, testing::ElementsAreArray(expected));
}

TEST_F(MazeTest, IsVisitedNodeReturnsTrueForVisitedNodes) {
    bool expected = true;

    target.VisitNode(0, 1);
    auto actual = target.IsVisitedNode(0, 1);

    EXPECT_EQ(actual, expected);
}

TEST_F(MazeTest, IsVisitedNodeReturnsFalseForUnvisitedNodes) {
    bool expected = false;

    auto actual = target.IsVisitedNode(0, 1);

    EXPECT_EQ(actual, expected);
}

TEST_F(MazeTest, IsVisitedNodeReturnsFalseForInvalidNodes) {
    bool expected = false;

    target.VisitNode(3, 0);
    auto actual = target.IsVisitedNode(3, 0);

    EXPECT_EQ(actual, expected);
}

TEST_F(MazeTest, AddNodeToRoutePushesNodeOntoRouteStack) {
    std::vector<std::pair<int, int>> expected = { { 0, 1 } };

    target.AddNodeToRoute(0, 1);
    auto actual = target.GetRouteStack();

    EXPECT_THAT(actual, testing::ElementsAreArray(expected));
}

TEST_F(MazeTest, RemoveNodeFromRoutePopsNodeOffOfRouteStack) {
    std::vector<std::pair<int, int>> expected = { { 0, 1 } };

    target.AddNodeToRoute(0, 1);
    target.AddNodeToRoute(1, 1);
    target.RemoveLastNodeFromRoute();
    auto actual = target.GetRouteStack();

    EXPECT_THAT(actual, testing::ElementsAreArray(expected));
}

TEST_F(MazeTest, IsTheEndReturnsTrueWhenNodeIsE) {
    auto actual = target.IsTheEnd(1, 1);

    EXPECT_EQ(actual, true);
}

TEST_F(MazeTest, IsTheEndReturnsFalseWhenNodeIsNotE) {
    auto actual = target.IsTheEnd(0, 1);

    EXPECT_EQ(actual, false);
}

TEST_F(MazeTest, IsTheEndReturnsFalseWhenNodeIsNotVisitable) {
    auto actual = target.IsTheEnd(2, 1);

    EXPECT_EQ(actual, false);
}

TEST_F(MazeTest, SetMazeSetsMazeVectorToGivenMaze) {
    std::vector<std::vector<char>> newMaze = { { 'S', '0', '0' }, { '1', '1', '1' }, { '0', '0', 'E' } };

    target.SetMaze(newMaze);
    auto actual = target.GetMaze();

    EXPECT_THAT(actual, testing::ElementsAreArray(newMaze));
}

#pragma clang diagnostic pop