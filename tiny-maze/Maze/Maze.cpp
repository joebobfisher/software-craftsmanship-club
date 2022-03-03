#include "Maze.h"

Maze::Maze(std::vector<std::vector<char>> maze) : GivenMaze(std::move(maze)), MarkedMaze(GivenMaze) {}

auto Maze::GetOriginalMaze() -> std::vector<std::vector<char>> {
    return GivenMaze;
}

auto Maze::GetVisitedList() -> std::vector<std::vector<bool>> {
    return VisitedNodes;
}

auto Maze::GetRouteStack() -> std::vector<std::pair<int, int>> {
    return RouteStack;
}

auto Maze::SolveMaze() -> std::vector<std::vector<char>> {
    FindRoute();
    MarkRoute();
    return MarkedMaze;
}

void Maze::FindRoute() {
    InitializeVisitedNodes();
    InitializeRouteStack();

    FindRouteDfs(0, 0);
}

void Maze::InitializeRouteStack() { RouteStack = {}; }

void Maze::InitializeVisitedNodes() {
    VisitedNodes = {};

    for (auto & col : GivenMaze) {
        std::vector<bool> column;
        for (int j = 0; j < col.size(); j++) {
            column.push_back(false); // NOLINT not pre-allocating is fine
        }
        VisitedNodes.push_back(column);
    }
}

auto Maze::FindRouteDfs(int x, int y) -> bool { // NOLINT(misc-no-recursion, readability-identifier-length)
    if (!IsValidNode(x, y) || VisitedNodes[x][y]) {
        return false;
    }

    VisitedNodes[x][y] = true;
    RouteStack.emplace_back(x, y);

    if (MarkedMaze[x][y] == 'E') {
        return true;
    }

    const std::vector<std::pair<int, int>> possibleMoves = {{x, y+1}, {x+1, y}, {x-1, y}, {x, y-1}};
    for (std::pair<int, int> coord : possibleMoves) {
        if (FindRouteDfs(coord.first, coord.second)) {
            return true;
        }
    }

    RouteStack.pop_back();

    return false;
}

auto Maze::IsValidNode(int x, int y) -> bool { // NOLINT(readability-identifier-length)
    return x >= 0 && x < MarkedMaze.size() && y >= 0 && y < MarkedMaze[x].size() && MarkedMaze[x][y] != '1';
}

void Maze::MarkRoute() {
    if (!RouteStack.empty()) {
        MarkRouteFound();
    } else {
        MarkRouteNotFound();
    }
}

void Maze::MarkRouteFound() {
    while (!RouteStack.empty()) {
        auto coord = RouteStack.back();
        MarkedMaze[coord.first][coord.second] = 'x';
        RouteStack.pop_back();
    }
}

void Maze::MarkRouteNotFound() {
    for (int i = 0; i < VisitedNodes.size(); i++) {
        for (int j = 0; j < VisitedNodes[i].size(); j++) {
            if (VisitedNodes[i][j]) {
                MarkedMaze[i][j] = 'x';
            }
        }
    }
}
