#include "MyRandom.h"

MyRandom::MyRandom() {
    mersenneTwisterEngine = std::mt19937 (randomDevice());
}

auto MyRandom::GetRandomInt(int lowerEndInclusive, int upperEndExclusive) -> int {
    std::uniform_int_distribution<int> distribution(lowerEndInclusive, upperEndExclusive);
    return distribution(mersenneTwisterEngine);
}