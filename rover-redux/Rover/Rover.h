#ifndef ROVER_REDUX_ROVER_H
#define ROVER_REDUX_ROVER_H


#include <string>

class Rover {
public:
    auto Execute(std::string commands) -> std::string;

private:
    std::string _position = "0:0:N";
};


#endif //ROVER_REDUX_ROVER_H
