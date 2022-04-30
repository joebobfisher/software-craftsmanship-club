#include "MyRandom.h"
#include <algorithm>

MyRandom::MyRandom() {
    mersenneTwisterEngine = std::mt19937 (randomDevice());
}

auto MyRandom::GetRandomInt(int lowerEndInclusive, int upperEndExclusive) -> int {
    std::uniform_int_distribution<> distribution(lowerEndInclusive, upperEndExclusive);
    return distribution(mersenneTwisterEngine);
}

auto MyRandom::GetRandomString(int size) -> std::string {
    std::string allChars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::uniform_int_distribution<> distribution(0, static_cast<int>(allChars.size())-1);

    std::string randomString;
    for (int i = 0; i < size; i++) {
        int index = distribution(mersenneTwisterEngine);
        randomString += allChars.at(index);
    }

    return randomString;
}