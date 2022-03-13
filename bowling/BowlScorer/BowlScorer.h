#ifndef BOWLING_BOWLSCORER_H
#define BOWLING_BOWLSCORER_H


#include <string>
#include <vector>

class BowlScorer {
public:
    auto Score(std::string frameString) -> int;
    auto GetValueOfBowl(int indexOfBowl) -> int;

private:
    std::vector<char> bowls;
};


#endif //BOWLING_BOWLSCORER_H
