#ifndef TINY_MAZE_MAZE_H
#define TINY_MAZE_MAZE_H

#include <vector>
#include <map>

class Maze {
public:
    explicit Maze(std::vector<std::vector<char>>  maze);
    auto GetMazeWithRoute() -> std::vector<std::vector<char>>;
    auto GetMazeVector() -> std::vector<std::vector<char>>;
    auto GetVisitedList() -> std::vector<std::vector<bool>>;
    auto GetRouteStack() -> std::vector<std::pair<int, int>>;
    void FindRoute();
    void MarkRoute();
    auto FindRouteDfs(int x, int y) -> bool;
    auto IsValidNode(int x, int y) -> bool;

private:
    std::vector<std::vector<char>> GivenMaze;
    std::vector<std::vector<char>> MarkedMaze;
    std::vector<std::vector<bool>> VisitedNodes;
    std::vector<std::pair<int, int>> RouteStack;

    void InitializeVisitedNodes();
    void InitializeRouteStack();
};

#endif //TINY_MAZE_MAZE_H
