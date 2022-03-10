#include "BowlScorer.h"
#include <vector>
#include <regex>

// take list of whitespace-delimited pairs of rolls
// tokenize list of rolls
// last frame could have 3 rolls in it if an X or / is in it
// valid values: 0-9, x, or /

auto BowlScorer::Score(std::string frameString) -> int {
    // split string by whitespace
    // TODO separate this out into a class you can use again
    // (this is going to come up again, and it's easier than using Boost)
    std::regex regex("\\s+");
    std::sregex_token_iterator iterator(frameString.begin(), frameString.end(), regex, -1);
    std::vector<std::string> frames{iterator, {}};



    return 0;
}