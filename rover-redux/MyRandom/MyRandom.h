#ifndef ROVER_REDUX_MYRANDOM_H
#define ROVER_REDUX_MYRANDOM_H


#include <random>

class MyRandom {
public:
    MyRandom();
    auto GetRandomInt(int lowerEndInclusive, int upperEndExclusive) -> int;

private:
    std::random_device randomDevice;
    std::mt19937 mersenneTwisterEngine;
};


#endif //ROVER_REDUX_MYRANDOM_H
