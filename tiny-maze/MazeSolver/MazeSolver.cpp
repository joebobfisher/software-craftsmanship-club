#include "MazeSolver.h"

MazeSolver::MazeSolver(std::vector<std::vector<char>> maze, RouteFinder routeFinder, RouteMarker routeMarker) :
        GivenMaze(std::move(maze)),
        SolvedMaze(GivenMaze),
        _routeFinder(std::move(routeFinder)),
        _routeMarker(std::move(routeMarker)) {}

auto MazeSolver::GetOriginalMaze() -> std::vector<std::vector<char>> {
    return GivenMaze;
}

auto MazeSolver::SolveMaze() -> std::vector<std::vector<char>> {
    _routeFinder.FindRoute();
    std::vector<std::vector<bool>> visitedNodes = _routeFinder.GetVisitedList();
    std::vector<std::pair<int, int>> routeStack = _routeFinder.GetRouteStack();
    SolvedMaze = _routeMarker.MarkRoute(SolvedMaze, visitedNodes, routeStack);
    return SolvedMaze;
}