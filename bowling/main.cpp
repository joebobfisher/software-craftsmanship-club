#include <iostream>
#include "BowlScorer/BowlScorer.h"

auto main() -> int {
    std::string frames = "12 34 54 63 72 81 X 1/ 27 5/9";

    BowlScorer bowlScorer;
    auto score = bowlScorer.Score(frames);

    std::cout << score << std::endl;
    return 0;
}