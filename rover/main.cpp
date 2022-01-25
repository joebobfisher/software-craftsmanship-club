#include <iostream>
#include "Rover.h"

int main(int argc, char** argv)
{
    ArgLoader loader = ArgLoader(argc, argv);
    Rover rover = Rover(loader);

    std::string endPositionAndHeading = rover.RoveFromMain();

    std::cout << endPositionAndHeading << std::endl;

    return 0;
}
