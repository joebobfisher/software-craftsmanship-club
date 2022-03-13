#include <iostream>
#include "BowlScorer/BowlScorer.h"

auto main() -> int {
    BowlScorer bowlScorer;

    std::string frames = "12 34 54 63 72 81 X 1/ 27 5/9";
    auto score = bowlScorer.Score(frames);
    std::cout << score << std::endl;

    frames = "X X X X X X X X X XXX";
    score = bowlScorer.Score(frames);
    std::cout << score << std::endl;

    frames = "9- 9- 9- 9- 9- 9- 9- 9- 9- 9-";
    score = bowlScorer.Score(frames);
    std::cout << score << std::endl;

    frames = "5/ 5/ 5/ 5/ 5/ 5/ 5/ 5/ 5/ 5/5";
    score = bowlScorer.Score(frames);
    std::cout << score << std::endl;

    return 0;
}