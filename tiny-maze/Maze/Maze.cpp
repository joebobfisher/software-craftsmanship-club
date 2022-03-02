#include "Maze.h"

// take a 2d char array as maze
// 0,0 and vector.size(),vector.size() are always passable
// find a path
// go over the path and mark each spot with an "x"

Maze::Maze(std::vector<std::vector<char>> maze) : GivenMaze(std::move(maze)), MarkedMaze(GivenMaze) {
    // TODO(joe): pass in a C array from main() instead of a vector of vectors (no need to resize once in this object)!
}

auto Maze::GetMazeVector() -> std::vector<std::vector<char>> {
    return GivenMaze;
}

auto Maze::GetMarkedMazeVector() -> std::vector<std::vector<char>> {
    return MarkedMaze;
}

auto Maze::GetVisitedList() -> std::vector<std::vector<bool>> {
    return VisitedNodes;
}

auto Maze::GetMazeWithRoute() -> std::vector<std::vector<char>> {
    // find the route, then mark it, then return it
    FindRoute();
    MarkRoute();
    return MarkedMaze;
}

void Maze::FindRoute() {
    InitializeVisitedNodes();
    InitializeRouteStack();

    FindRouteDfs(0, 0);
}

void Maze::InitializeRouteStack() { RouteStack = {}; }

void Maze::InitializeVisitedNodes() {
    VisitedNodes = {};
    for (auto & i : GivenMaze) {
        std::vector<bool> column;
        for (int j = 0; j < i.size(); j++) {
            column.push_back(false);
        }
        VisitedNodes.push_back(column);
    }
}

auto Maze::FindRouteDfs(int x, int y) -> bool { // NOLINT(misc-no-recursion, readability-identifier-length)
    // go back if this isn't a valid node or if we've already been here
    if (!IsValidNode(x, y) || VisitedNodes[x][y]) {
        return false;
    }

    VisitedNodes[x][y] = true;
    RouteStack.emplace_back(x, y);

    if (MarkedMaze[x][y] == 'E') {
        return true;
    }

    const std::vector<std::pair<int, int>> possibleMoves = {{x, y+1}, {x+1, y}, {x-1, y}, {x, y-1}};
    for (std::pair<int, int> coord : possibleMoves) {
        if (FindRouteDfs(coord.first, coord.second)) {
            return true;
        }
    }

    // This node that we're currently on is a dead-end -- go back
    RouteStack.pop_back();

    return false;
}

auto Maze::IsValidNode(int x, int y) -> bool { // NOLINT(readability-identifier-length)
    return x >= 0 && x < MarkedMaze.size() && y >= 0 && y < MarkedMaze[x].size() && MarkedMaze[x][y] != '1';
}

void Maze::MarkRoute() {
    // returns original maze with "x"s on nodes that were traversed to get to the end
    // returns all visited nodes with "x"s if no route exists (i.e. routestack is empty)
}
