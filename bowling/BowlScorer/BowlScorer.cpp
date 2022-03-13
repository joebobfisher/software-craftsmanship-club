#include "BowlScorer.h"
#include <regex>

const int StartFrame = 1;
const int LastFrame = 10;
const int ValueOfAllPins = 10;
const int ValueOfScratch = 0;
const int Base10 = 10;

auto BowlScorer::Score(std::string frameString) -> int {
    int score = 0;

    // split string by whitespace
    // TODO separate this out into a class you can use again
    // (this is going to come up again, and it's easier than using Boost)
    std::regex regex("\\s+");
    std::sregex_token_iterator iterator(frameString.begin(), frameString.end(), regex, -1);
    std::vector<std::string> frames{iterator, {}};

    // turn frames vector into vector of bowls (no spaces -- we don't need the frame info)
    bowls = {};
    for (const auto& frame : frames) {
        for (auto bowl : frame) {
            bowls.push_back(bowl);
        }
    }

    // score the game
    int frame = StartFrame;
    for (int i = 0; i < bowls.size(); i++) {
        auto bowl = bowls[i];

        // add the simple value to the score
        score += GetValueOfBowl(i);

        // add additional values to the score if necessary and adjust the frame
        if (frame != LastFrame) {
            if (bowl == 'X') {
                score += GetValueOfBowl(i + 1) + GetValueOfBowl(i + 2);
                frame++;
            } else if (bowl == '/') {
                score += GetValueOfBowl(i + 1);
                frame++;
            } else if (i % 2 != 0) {
                frame++;
            }
        }
    }

    return score;
}

auto BowlScorer::GetValueOfBowl(int indexOfBowl) -> int {     // NOLINT(misc-no-recursion)
    auto bowl = bowls[indexOfBowl];

    switch (bowl) {
        case 'X':
            return ValueOfAllPins;
        case '/':
            return ValueOfAllPins - GetValueOfBowl(indexOfBowl - 1);
        case '-':
            return ValueOfScratch;
        default:
            return static_cast<int>(strtol(&bowl, nullptr, Base10));
    }
}