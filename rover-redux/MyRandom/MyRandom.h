#ifndef ROVER_REDUX_MYRANDOM_H
#define ROVER_REDUX_MYRANDOM_H


#include <random>
#include <string>

class MyRandom {
public:
    MyRandom();
    auto GetRandomInt(int lowerEndInclusive, int upperEndExclusive) -> int;
    auto GetRandomString(int size) -> std::string;

private:
    std::random_device randomDevice;
    std::mt19937 mersenneTwisterEngine;
};


#endif //ROVER_REDUX_MYRANDOM_H
