#ifndef TINY_MAZE_ROUTEFINDER_H
#define TINY_MAZE_ROUTEFINDER_H


#include "Maze.h"

class RouteFinder {
public:
    explicit RouteFinder(Maze& maze);
    void FindRoute();
//    void InitializeVisitedNodes();
//    void InitializeRouteStack();
    auto FindRouteDfs(int x, int y) -> bool;    // NOLINT(readability-identifier-length)
//    auto IsValidNode(int x, int y) -> bool;     // NOLINT(readability-identifier-length)
//    auto GetVisitedList() -> std::vector<std::vector<bool>>;
//    auto GetRouteStack() -> std::vector<std::pair<int, int>>;

private:
    Maze& MazeToSearch;
//    std::vector<std::vector<bool>> VisitedNodes;
//    std::vector<std::pair<int, int>> RouteStack;
};


#endif //TINY_MAZE_ROUTEFINDER_H
