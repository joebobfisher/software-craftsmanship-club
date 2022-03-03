#include "Maze.h"

Maze::Maze(std::vector<std::vector<char>> maze, RouteFinder routeFinder, RouteMarker routeMarker) :
    GivenMaze(std::move(maze)),
    MarkedMaze(GivenMaze),
    _routeFinder(std::move(routeFinder)),
    _routeMarker(std::move(routeMarker)) {}

auto Maze::GetOriginalMaze() -> std::vector<std::vector<char>> {
    return GivenMaze;
}

auto Maze::SolveMaze() -> std::vector<std::vector<char>> {
    _routeFinder.FindRoute();
    std::vector<std::vector<bool>> visitedNodes = _routeFinder.GetVisitedList();
    std::vector<std::pair<int, int>> routeStack = _routeFinder.GetRouteStack();
    MarkedMaze = _routeMarker.MarkRoute(MarkedMaze, visitedNodes, routeStack);
    return MarkedMaze;
}