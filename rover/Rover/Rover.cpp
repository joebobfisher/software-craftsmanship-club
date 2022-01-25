#include <regex>
#include "Rover.h"

#define MAX_LENGTH_OF_AREA 10
#define MAX_WIDTH_OF_AREA 10

Rover::Rover(ArgLoader &loader) : _loader(loader) {}

std::string Rover::RoveFromMain()
{
    std::string commandString = _loader.GetArgAsString(1);
    ProcessCommands(commandString);
    return GetStateAsString();
}

void Rover::ProcessCommands(std::string &moveCommandString)
{
    SanitizeCommandString(moveCommandString);

    for (auto cmd : moveCommandString)
    {
        ProcessCommand(cmd);
    }

    // TODO Could create enum for N/E/S/W, and +1 for right, -1 for left.
    // Then single check only is needed when moving R or L (check for overflow)
}

void Rover::SanitizeCommandString(std::string &moveCommandString)
{
    CheckForInvalidCommands(moveCommandString);
    TransformCommandsToUpperCase(moveCommandString);
}

void Rover::CheckForInvalidCommands(const std::string &moveCommandString)
{
    if (!std::regex_match(moveCommandString, std::regex("^[MRL]*$")))
    {
        throw std::invalid_argument("Rover command string must only contain valid commands");
    }
}

void Rover::TransformCommandsToUpperCase(std::string &moveCommandString)
{
    std::transform(moveCommandString.begin(),
                   moveCommandString.end(),
                   moveCommandString.begin(),
                   ::toupper);
}

void Rover::ProcessCommand(char cmd)
{
    switch (cmd)
    {
        case 'M':
            ProcessMoveCommand();
            break;
        case 'R':
            ProcessTurnRightCommand();
            break;
        case 'L':
            ProcessTurnLeftCommand();
            break;
        default:
            throw std::invalid_argument("Received an invalid command: '" +
                                        std::to_string(cmd) + "'");
    }
}

void Rover::ProcessMoveCommand()
{
    switch (_roverPositionAndHeading.heading)
    {
        case 'N':
            MoveNorth();
            break;
        case 'E':
            MoveEast();
            break;
        case 'S':
            MoveSouth();
            break;
        case 'W':
            MoveWest();
            break;
    }
}

void Rover::MoveNorth()
{
    _roverPositionAndHeading.y++;
    if (_roverPositionAndHeading.y >= MAX_LENGTH_OF_AREA)
    {
        _roverPositionAndHeading.y = 0;
    }
}

void Rover::MoveEast()
{
    _roverPositionAndHeading.x++;
    if (_roverPositionAndHeading.x >= MAX_WIDTH_OF_AREA)
    {
        _roverPositionAndHeading.x = 0;
    }
}

void Rover::MoveSouth()
{
    _roverPositionAndHeading.y--;
    if (_roverPositionAndHeading.y < 0)
    {
        _roverPositionAndHeading.y = MAX_LENGTH_OF_AREA;
    }
}

void Rover::MoveWest()
{
    _roverPositionAndHeading.x--;
    if (_roverPositionAndHeading.x < 0)
    {
        _roverPositionAndHeading.x = MAX_WIDTH_OF_AREA;
    }
}

void Rover::ProcessTurnRightCommand()
{
    switch (_roverPositionAndHeading.heading)
    {
        case 'N':
            _roverPositionAndHeading.heading = 'E';
            break;
        case 'E':
            _roverPositionAndHeading.heading = 'S';
            break;
        case 'S':
            _roverPositionAndHeading.heading = 'W';
            break;
        case 'W':
            _roverPositionAndHeading.heading = 'N';
            break;
    }
}

void Rover::ProcessTurnLeftCommand()
{
    switch (_roverPositionAndHeading.heading)
    {
        case 'N':
            _roverPositionAndHeading.heading = 'W';
            break;
        case 'E':
            _roverPositionAndHeading.heading = 'N';
            break;
        case 'S':
            _roverPositionAndHeading.heading = 'E';
            break;
        case 'W':
            _roverPositionAndHeading.heading = 'S';
            break;
    }
}

std::string Rover::GetStateAsString() const
{
    return std::to_string(_roverPositionAndHeading.x) + ":" +
           std::to_string(_roverPositionAndHeading.y) + ":" +
           _roverPositionAndHeading.heading;
}