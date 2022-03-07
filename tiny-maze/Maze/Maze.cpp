#include "Maze.h"

#include <utility>

Maze::Maze() :
        MazeVector({}),
        VisitedNodes({}),
        RouteStack({}) {}

Maze::Maze(std::vector<std::vector<char>> mazeVector) :
        MazeVector(std::move(mazeVector)),
        VisitedNodes({}),
        RouteStack({}) {}

auto Maze::GetMaze() -> std::vector<std::vector<char>> {
    return MazeVector;
}

auto Maze::GetVisitedList() -> std::vector<std::vector<bool>> {
    return VisitedNodes;
}

auto Maze::GetRouteStack() -> std::vector<std::pair<int, int>> {
    return RouteStack;
}

void Maze::InitializeMaze() {
    InitializeVisitedNodes();
    InitializeRouteStack();
}

void Maze::InitializeVisitedNodes() {
    VisitedNodes = {};

    for (auto & col : MazeVector) {
        std::vector<bool> column;
        for (int j = 0; j < col.size(); j++) {
            column.push_back(false); // NOLINT not pre-allocating is fine
        }
        VisitedNodes.push_back(column);
    }
}

void Maze::InitializeRouteStack() { RouteStack = {}; }

auto Maze::IsVisitableNode(int x, int y) -> bool {   // NOLINT(readability-identifier-length)
    return x >= 0 && x < MazeVector.size() && y >= 0 && y < MazeVector[x].size() && MazeVector[x][y] != '1';
}

void Maze::VisitNode(int x, int y) {    // NOLINT(readability-identifier-length)
    if (IsVisitableNode(x, y)) {
        VisitedNodes[x][y] = true;
    }
}

auto Maze::IsVisitedNode(int x, int y) -> bool {    // NOLINT(readability-identifier-length)
    if (IsVisitableNode(x, y)) {
        return VisitedNodes[x][y];
    }

    return false;
}

void Maze::AddNodeToRoute(int x, int y) {   // NOLINT(readability-identifier-length)
    RouteStack.emplace_back(x, y);
}

void Maze::RemoveLastNodeFromRoute() {  // NOLINT(readability-identifier-length)
    RouteStack.pop_back();
}

auto Maze::IsTheEnd(int x, int y) -> bool {     // NOLINT(readability-identifier-length)
    return IsVisitableNode(x, y) && MazeVector[x][y] == 'E';
}

void Maze::SetMaze(std::vector<std::vector<char>> newMaze) {
    MazeVector = std::move(newMaze);
}