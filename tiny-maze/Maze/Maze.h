#ifndef TINY_MAZE_MAZE_H
#define TINY_MAZE_MAZE_H


#include "RouteFinder.h"
#include "RouteMarker.h"

class Maze {
public:
    explicit Maze(std::vector<std::vector<char>> maze, RouteFinder routeFinder, RouteMarker routeMarker);
    auto SolveMaze() -> std::vector<std::vector<char>>;
    auto GetOriginalMaze() -> std::vector<std::vector<char>>;

private:
    std::vector<std::vector<char>> GivenMaze;
    std::vector<std::vector<char>> MarkedMaze;
    RouteFinder _routeFinder;
    RouteMarker _routeMarker;
};


#endif //TINY_MAZE_MAZE_H
