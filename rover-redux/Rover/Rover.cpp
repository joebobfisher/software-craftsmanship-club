#include "Rover.h"

auto Rover::Execute(std::string commands) -> std::string {
    if (commands == "M") {
        _position = "0:1:N";
    }

    return _position;
}