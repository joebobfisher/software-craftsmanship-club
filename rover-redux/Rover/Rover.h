#ifndef ROVER_REDUX_ROVER_H
#define ROVER_REDUX_ROVER_H


#include <string>

class Rover {
public:
    auto Execute(std::string commands) -> std::string;
};


#endif //ROVER_REDUX_ROVER_H
