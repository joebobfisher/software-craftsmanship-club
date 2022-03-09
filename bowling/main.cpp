#include <iostream>
#include "BowlScorer/BowlScorer.h"

auto main() -> int {
    // take list of whitespace-delimited pairs of rolls
    // tokenize list of rolls
    // last frame could have 3 rolls in it if an X or / is in it
    // valid values: 0-9, x, or /
    std::string frames = "12 34 54 63 72 81 X 1/ 27 5/9";

    BowlScorer bowlScorer;
    auto score = bowlScorer.Score(frames);

    std::cout << score << std::endl;
    return 0;
}