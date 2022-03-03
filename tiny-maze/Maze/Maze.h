#ifndef TINY_MAZE_MAZE_H
#define TINY_MAZE_MAZE_H

#include <vector>
#include <map>

class Maze {
public:
    explicit Maze(std::vector<std::vector<char>>  maze);
    auto SolveMaze() -> std::vector<std::vector<char>>;
    auto GetOriginalMaze() -> std::vector<std::vector<char>>;
    auto GetVisitedList() -> std::vector<std::vector<bool>>;
    auto GetRouteStack() -> std::vector<std::pair<int, int>>;
    void FindRoute();

private:
    std::vector<std::vector<char>> GivenMaze;
    std::vector<std::vector<char>> MarkedMaze;
    std::vector<std::vector<bool>> VisitedNodes;
    std::vector<std::pair<int, int>> RouteStack;

    void InitializeVisitedNodes();
    void InitializeRouteStack();
    auto FindRouteDfs(int x, int y) -> bool;    // NOLINT(readability-identifier-length)
    auto IsValidNode(int x, int y) -> bool;     // NOLINT(readability-identifier-length)
    void MarkRoute();
    void MarkRouteFound();
    void MarkRouteNotFound();
};

#endif //TINY_MAZE_MAZE_H
