#ifndef BOWLING_BOWLSCORER_H
#define BOWLING_BOWLSCORER_H


#include <string>
#include <vector>

class BowlScorer {
public:
    auto ScoreGame(std::string frameString) -> int;

private:
    std::string Frames;
    int Score = 0;
    int FrameNumber = 1;
    int CurrentIndex = 0;

    void CalculateScore();
    void AddBowlToScore();
    auto GetValueOfBowl(int index) -> int;
    void AddExtraStrikeOrSpareValuesToScore();
    void AddSubsequentBowlsToScore(int bowlsToAdd);
    void AdjustFrameNumber();
};


#endif //BOWLING_BOWLSCORER_H
