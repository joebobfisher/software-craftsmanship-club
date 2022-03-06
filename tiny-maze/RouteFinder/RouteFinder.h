#ifndef TINY_MAZE_ROUTEFINDER_H
#define TINY_MAZE_ROUTEFINDER_H


#include <vector>

class RouteFinder {
public:
    explicit RouteFinder(std::vector<std::vector<char>>& maze);
    void FindRoute();
    void InitializeVisitedNodes();
    void InitializeRouteStack();
    auto FindRouteDfs(int x, int y) -> bool;    // NOLINT(readability-identifier-length)
    auto IsValidNode(int x, int y) -> bool;     // NOLINT(readability-identifier-length)
    auto GetVisitedList() -> std::vector<std::vector<bool>>;
    auto GetRouteStack() -> std::vector<std::pair<int, int>>;

private:
    std::vector<std::vector<char>> Maze;
    std::vector<std::vector<bool>> VisitedNodes;
    std::vector<std::pair<int, int>> RouteStack;
};


#endif //TINY_MAZE_ROUTEFINDER_H
