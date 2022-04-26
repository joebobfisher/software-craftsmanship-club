#ifndef ROVER_REDUX_ROVER_H
#define ROVER_REDUX_ROVER_H


#include <string>
#include "RoverPosition.h"

class Rover {
public:
    auto Execute(std::string commands) -> std::string;

private:
    RoverPosition _position;
};


#endif //ROVER_REDUX_ROVER_H
