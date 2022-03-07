#ifndef TINY_MAZE_MAZE_H
#define TINY_MAZE_MAZE_H


#include <vector>

class Maze {
public:
    Maze();
    explicit Maze(std::vector<std::vector<char>> mazeVector);
    auto GetMaze() -> std::vector<std::vector<char>>;
    void InitializeMaze();
    void InitializeVisitedNodes();
    void InitializeRouteStack();
    auto IsVisitableNode(int x, int y) -> bool;                 // NOLINT(readability-identifier-length)
    void VisitNode(int x, int y);                               // NOLINT(readability-identifier-length)
    auto IsVisitedNode(int x, int y) -> bool;                   // NOLINT(readability-identifier-length)
    void AddNodeToRoute(int x, int y);                          // NOLINT(readability-identifier-length)
    void RemoveLastNodeFromRoute();
    auto GetVisitedList() -> std::vector<std::vector<bool>>;
    auto GetRouteStack() -> std::vector<std::pair<int, int>>;
    auto IsTheEnd(int x, int y) -> bool;                        // NOLINT(readability-identifier-length)
    void SetMaze(std::vector<std::vector<char>> newMaze);

private:
    std::vector<std::vector<char>> MazeVector;
    std::vector<std::vector<bool>> VisitedNodes;
    std::vector<std::pair<int, int>> RouteStack;
};


#endif //TINY_MAZE_MAZE_H
