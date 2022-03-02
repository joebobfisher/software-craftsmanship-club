#ifndef TINY_MAZE_MAZE_H
#define TINY_MAZE_MAZE_H

#include <vector>
#include <map>

class Maze {
public:
    explicit Maze(std::vector<std::vector<char>>  maze);
    auto GetMazeWithRoute() -> std::vector<std::vector<char>>;
    auto GetMazeVector() -> std::vector<std::vector<char>>;
    auto GetMazeMap() -> std::map<std::pair<int, int>, std::vector<std::pair<int, int>>>;

private:
    std::vector<std::vector<char>> MazeVector;
    std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> MazeMap;
    std::vector<std::vector<char>> MarkedMazeVector;

    static auto MakeMazeMap(const std::vector<std::vector<char>>& maze) -> std::map<std::pair<int, int>, std::vector<std::pair<int, int>>>;
    void FindRoute();
    void MarkMazeWithRoute();
};


#endif //TINY_MAZE_MAZE_H
