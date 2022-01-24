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
    switch (_state.heading)
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
    _state.y++;
    if (_state.y >= MAX_LENGTH_OF_AREA)
    {
        _state.y = 0;
    }
}

void Rover::MoveEast()
{
    _state.x++;
    if (_state.x >= MAX_WIDTH_OF_AREA)
    {
        _state.x = 0;
    }
}

void Rover::MoveSouth()
{
    _state.y--;
    if (_state.y < 0)
    {
        _state.y = MAX_LENGTH_OF_AREA;
    }
}

void Rover::MoveWest()
{
    _state.x--;
    if (_state.x < 0)
    {
        _state.x = MAX_WIDTH_OF_AREA;
    }
}

void Rover::ProcessTurnRightCommand()
{
    switch (_state.heading)
    {
        case 'N':
            _state.heading = 'E';
            break;
        case 'E':
            _state.heading = 'S';
            break;
        case 'S':
            _state.heading = 'W';
            break;
        case 'W':
            _state.heading = 'N';
            break;
    }
}

void Rover::ProcessTurnLeftCommand()
{
    switch (_state.heading)
    {
        case 'N':
            _state.heading = 'W';
            break;
        case 'E':
            _state.heading = 'N';
            break;
        case 'S':
            _state.heading = 'E';
            break;
        case 'W':
            _state.heading = 'S';
            break;
    }
}

std::string Rover::GetStateAsString() const
{
    return std::to_string(_state.x) + ":" +
           std::to_string(_state.y) + ":" +
           _state.heading;
}