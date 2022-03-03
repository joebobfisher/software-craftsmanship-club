#include <iostream>
#include "Maze.h"

void printMaze(std::vector<std::vector<char>> maze);

auto main() -> int {
    std::vector<std::vector<char>> myMaze = {
            {'S', '0', '0', '0', '0'},
            {'1', '1', '1', '1', '0'},
            {'0', '0', '0', '1', '0'},
            {'0', '1', '0', '1', '0'},
            {'0', '1', '0', '0', '0'},
            {'0', '1', '0', '1', '0'},
            {'0', '1', '0', '0', '0'},
            {'0', '1', '1', '1', '1'},
            {'0', '0', '0', '0', '1'},
            {'0', '1', '0', '1', '1'},
            {'1', '1', '0', '0', 'E'},
    };

    printMaze(myMaze);
    std::cout << std::endl << std::endl;

    RouteFinder routeFinder(myMaze);
    Maze maze(myMaze, routeFinder);
    std::vector<std::vector<char>> solvedMaze = maze.SolveMaze();

    printMaze(solvedMaze);
    std::cout << std::endl;

    return 0;
}

void printMaze(std::vector<std::vector<char>> maze) {
    bool started = false;
    bool ending = false;

    std::cout << "[ ";

    for (int i = 0; i < maze.size(); i++) {
        if (started) { std::cout << "  "; }
        std::cout << "[ ";

        for (auto node : maze[i]) {
            std::cout << node << " ";
            started = true;
            if (i == maze.size()-1) { ending = true; }
        }

        std::cout << "]";
        if (!ending) { std::cout << std::endl; }
    }

    std::cout << " ]";
}
