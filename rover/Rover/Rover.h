#include "ArgLoader.h"

struct RoverState
{
    unsigned int x;
    unsigned int y;
    char heading;
};

class Rover
{
private:
    static void SanitizeCommandString(std::string& moveCommandString);
    static void CheckForInvalidCommands(const std::string &moveCommandString);
    static void TransformCommandsToUpperCase(std::string &moveCommandString);
    void ProcessCommand(char cmd);
    void ProcessMoveCommand();
    void MoveNorth();
    void MoveEast();
    void MoveSouth();
    void MoveWest();
    void ProcessTurnRightCommand();
    void ProcessTurnLeftCommand();

    ArgLoader _loader;
    struct RoverState _roverPositionAndHeading = {0, 0, 'N'};

public:
    explicit Rover(ArgLoader &loader);
    std::string RoveFromMain();
    void ProcessCommands(std::string& moveCommandString);
    std::string GetStateAsString() const;
};
