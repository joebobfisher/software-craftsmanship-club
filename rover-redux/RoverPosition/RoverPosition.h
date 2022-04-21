#ifndef ROVER_REDUX_ROVERPOSITION_H
#define ROVER_REDUX_ROVERPOSITION_H


enum RoverHeading {
    North,
    East,
    South,
    West
};

class RoverPosition {
public:
    unsigned int x;
    unsigned int y;
    enum RoverHeading heading;
};


#endif //ROVER_REDUX_ROVERPOSITION_H
