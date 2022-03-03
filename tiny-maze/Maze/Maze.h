#ifndef TINY_MAZE_MAZE_H
#define TINY_MAZE_MAZE_H


#include "RouteFinder.h"

class Maze {
public:
    explicit Maze(std::vector<std::vector<char>> maze, RouteFinder routeFinder);
    auto SolveMaze() -> std::vector<std::vector<char>>;
    auto GetOriginalMaze() -> std::vector<std::vector<char>>;

private:
    std::vector<std::vector<char>> GivenMaze;
    std::vector<std::vector<char>> MarkedMaze;
    std::vector<std::vector<bool>> VisitedNodes;
    std::vector<std::pair<int, int>> RouteStack;
    RouteFinder _routeFinder;

    void MarkRoute();
    void MarkRouteFound();
    void MarkRouteNotFound();
};


#endif //TINY_MAZE_MAZE_H
