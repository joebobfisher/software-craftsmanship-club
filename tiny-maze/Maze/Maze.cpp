#include "Maze.h"

// take a 2d char array as maze
// 0,0 and vector.size(),vector.size() are always "0"
// find a path
// go over the path and mark each spot with an "x"

Maze::Maze(std::vector<std::vector<char>> maze) : MazeVector(std::move(maze)) {
    MazeMap = MakeMazeMap(MazeVector);
}

auto Maze::GetMazeVector() -> std::vector<std::vector<char>> {
    return MazeVector;
}

auto Maze::GetMazeMap() -> std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> {
    return MazeMap;
}

auto Maze::MakeMazeMap(const std::vector<std::vector<char>>& maze) -> std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> {
    std::map<std::pair<int, int>, std::vector<std::pair<int, int>>> adjacencyMap;

    for (int i = 0; i < maze.size(); i++) {
        for (int j = 0; j < maze[i].size(); j++) {
            auto key = std::make_pair(i, j);
            std::vector<std::pair<int, int>> adjacents;

            if (maze[i][j] == '1') {
                continue;
            }

            // add any adjacent spots to the adjacents vector
            if (j-1 >= 0 && (maze[i][j-1] == '0' || maze[i][j-1] == 'S' || maze[i][j-1] == 'E')) {
                adjacents.emplace_back(std::make_pair(i, j-1));
            }
            if (j+1 < maze[i].size() && (maze[i][j+1] == '0' || maze[i][j+1] == 'S' || maze[i][j+1] == 'E')) {
                adjacents.emplace_back(std::make_pair(i, j+1));
            }
            if (i-1 >= 0 && (maze[i-1][j] == '0' || maze[i-1][j] == 'S' || maze[i-1][j] == 'E')) {
                adjacents.emplace_back(std::make_pair(i-1, j));
            }
            if (i+1 < maze.size() && (maze[i+1][j] == '0' || maze[i+1][j] == 'S' || maze[i+1][j] == 'E')) {
                adjacents.emplace_back(std::make_pair(i+1, j));
            }

            adjacencyMap.insert({key, adjacents});
        }
    }


    return adjacencyMap;
}

auto Maze::GetMazeWithRoute() -> std::vector<std::vector<char>> {
    // find the route, then mark it, then return it
    return {};
}

void Maze::FindRoute() {
    // Find a route using DFS
    // initialize visited
}

void Maze::MarkMazeWithRoute() {
    // returns original maze with "x"s on nodes that were traversed to get to the end
    // returns all visited nodes with "x"s if no route exists
}
