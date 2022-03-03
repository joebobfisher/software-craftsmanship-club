#include "RouteFinder.h"

RouteFinder::RouteFinder(Maze& maze) : MazeToSearch(maze) {}

void RouteFinder::FindRoute() {
//    InitializeVisitedNodes();
//    InitializeRouteStack();
    MazeToSearch.InitializeMaze();
    FindRouteDfs(0, 0);
}

//void RouteFinder::InitializeVisitedNodes() {
//    VisitedNodes = {};
//
//    for (auto & col : Maze) {
//        std::vector<bool> column;
//        for (int j = 0; j < col.size(); j++) {
//            column.push_back(false); // NOLINT not pre-allocating is fine
//        }
//        VisitedNodes.push_back(column);
//    }
//}
//
//void RouteFinder::InitializeRouteStack() { RouteStack = {}; }

auto RouteFinder::FindRouteDfs(int x, int y) -> bool { // NOLINT(misc-no-recursion, readability-identifier-length)
    //if (!IsValidNode(x, y) || VisitedNodes[x][y]) {
    if (!MazeToSearch.IsVisitableNode(x, y) || MazeToSearch.IsVisitedNode(x, y)) {
        return false;
    }

//    VisitedNodes[x][y] = true;
//    RouteStack.emplace_back(x, y);
    MazeToSearch.VisitNode(x, y);
    MazeToSearch.AddNodeToRoute(x, y);

    //if (Maze[x][y] == 'E') {
    if (MazeToSearch.IsTheEnd(x, y)) {
        return true;
    }

    const std::vector<std::pair<int, int>> possibleMoves = {{x, y+1}, {x+1, y}, {x-1, y}, {x, y-1}};
    for (std::pair<int, int> coord : possibleMoves) {
        if (FindRouteDfs(coord.first, coord.second)) {
            return true;
        }
    }

//    RouteStack.pop_back();
    MazeToSearch.RemoveLastNodeFromRoute();

    return false;
}

//auto RouteFinder::IsValidNode(int x, int y) -> bool {   // NOLINT(readability-identifier-length)
//    return x >= 0 && x < Maze.size() && y >= 0 && y < Maze[x].size() && Maze[x][y] != '1';
//}
//
//auto RouteFinder::GetVisitedList() -> std::vector<std::vector<bool>> {
//    return VisitedNodes;
//}
//
//auto RouteFinder::GetRouteStack() -> std::vector<std::pair<int, int>> {
//    return RouteStack;
//}

