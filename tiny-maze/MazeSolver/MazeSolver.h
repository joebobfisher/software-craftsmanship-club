#ifndef TINY_MAZE_MAZESOLVER_H
#define TINY_MAZE_MAZESOLVER_H


#include "RouteFinder.h"
#include "RouteMarker.h"

class MazeSolver {
public:
    explicit MazeSolver(std::vector<std::vector<char>> maze, RouteFinder routeFinder, RouteMarker routeMarker);
    auto SolveMaze() -> std::vector<std::vector<char>>;
    auto GetOriginalMaze() -> std::vector<std::vector<char>>;

private:
    std::vector<std::vector<char>> GivenMaze;
    std::vector<std::vector<char>> SolvedMaze;
    RouteFinder _routeFinder;
    RouteMarker _routeMarker;
};


#endif //TINY_MAZE_MAZESOLVER_H
