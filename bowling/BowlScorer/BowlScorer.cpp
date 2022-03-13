#include "BowlScorer.h"

#include <utility>

const int StartFrame = 1;
const int LastFrame = 10;
const int ValueOfAllPins = 10;
const int ValueOfScratch = 0;
const int Base10 = 10;

auto BowlScorer::ScoreGame(std::string frameString) -> int {
    Frames = std::move(frameString);
    CalculateScore();
    return Score;
}

void BowlScorer::CalculateScore() {
    Score = 0;
    FrameNumber = StartFrame;
    for (CurrentIndex = 0; CurrentIndex < Frames.size(); CurrentIndex++) {
        AddBowlToScore();
        AddExtraStrikeOrSpareValuesToScore();
        AdjustFrameNumber();
    }
}

void BowlScorer::AddBowlToScore() {
    Score += GetValueOfBowl(CurrentIndex);
}

auto BowlScorer::GetValueOfBowl(int index) -> int {     // NOLINT(misc-no-recursion)
    auto bowl = Frames[index];
    switch (bowl) {
        case 'X':
            return ValueOfAllPins;
        case '/':
            return ValueOfAllPins - GetValueOfBowl(index - 1);
        case '-':
            return ValueOfScratch;
        case ' ':
            return 0;
        default:
            return static_cast<int>(strtol(&bowl, nullptr, Base10));
    }
}

void BowlScorer::AddExtraStrikeOrSpareValuesToScore() {
    auto bowl = Frames[CurrentIndex];
    if (FrameNumber != LastFrame) {
        if (bowl == 'X') {
            AddSubsequentBowlsToScore(2);
        } else if (bowl == '/') {
            AddSubsequentBowlsToScore(1);
        }
    }
}

void BowlScorer::AddSubsequentBowlsToScore(int bowlsToAdd) {
    int index = 1;
    while (bowlsToAdd > 0) {
        auto nextIndexToTry = CurrentIndex + index;
        if (Frames[nextIndexToTry] != ' ') {
            Score += GetValueOfBowl(nextIndexToTry);
            bowlsToAdd--;
        }
        index++;
    }
}

void BowlScorer::AdjustFrameNumber() {
    if (Frames[CurrentIndex] == ' ') {
        FrameNumber++;
    }
}
