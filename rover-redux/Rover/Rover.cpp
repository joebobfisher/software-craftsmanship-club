#include "Rover.h"

auto Rover::Execute(std::string commands) -> std::string {
    for (auto command : commands) {
        if (command == 'M') {
            _position.y++;
        }
    }

    return std::to_string(_position.x) + ":" + std::to_string(_position.y) + ":" + "N";
}