#ifndef TINY_MAZE_ROUTEMARKER_H
#define TINY_MAZE_ROUTEMARKER_H


#include <vector>

class RouteMarker {
public:
    RouteMarker() = default;
    auto MarkRoute(std::vector<std::vector<char>> maze, std::vector<std::vector<bool>> visitedNodes, std::vector<std::pair<int, int>> routeStack) -> std::vector<std::vector<char>>;
    void MarkRouteFound();
    void MarkRouteNotFound();

private:
    std::vector<std::vector<char>> Maze;
    std::vector<std::vector<bool>> VisitedNodes;
    std::vector<std::pair<int, int>> RouteStack;
};


#endif //TINY_MAZE_ROUTEMARKER_H
