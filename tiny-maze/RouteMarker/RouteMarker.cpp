#include "RouteMarker.h"

// TODO consider passing all of these parameters as a single "Maze" object (rename current "Maze" to "MazeSolver")
auto RouteMarker::MarkRoute(std::vector<std::vector<char>> maze, std::vector<std::vector<bool>> visitedNodes, std::vector<std::pair<int, int>> routeStack) -> std::vector<std::vector<char>> {
    Maze = std::move(maze);
    VisitedNodes = std::move(visitedNodes);
    RouteStack = std::move(routeStack);

    if (!RouteStack.empty()) {
        MarkRouteFound();
    } else {
        MarkRouteNotFound();
    }

    return Maze;
}

void RouteMarker::MarkRouteFound() {
    while (!RouteStack.empty()) {
        auto coord = RouteStack.back();
        Maze[coord.first][coord.second] = 'x';
        RouteStack.pop_back();
    }
}

void RouteMarker::MarkRouteNotFound() {
    for (int i = 0; i < VisitedNodes.size(); i++) {
        for (int j = 0; j < VisitedNodes[i].size(); j++) {
            if (VisitedNodes[i][j]) {
                Maze[i][j] = 'x';
            }
        }
    }
}