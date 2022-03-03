#include "Maze.h"

#include <utility>

Maze::Maze(std::vector<std::vector<char>> maze, RouteFinder routeFinder) :
    GivenMaze(std::move(maze)),
    MarkedMaze(GivenMaze),
    _routeFinder(std::move(routeFinder)) {}

auto Maze::GetOriginalMaze() -> std::vector<std::vector<char>> {
    return GivenMaze;
}

auto Maze::SolveMaze() -> std::vector<std::vector<char>> {
    _routeFinder.FindRoute();
    VisitedNodes = _routeFinder.GetVisitedList();
    RouteStack = _routeFinder.GetRouteStack();
    MarkRoute();
    return MarkedMaze;
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
