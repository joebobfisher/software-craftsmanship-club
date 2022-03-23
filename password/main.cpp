#include <iostream>
#include "PasswordKeeper.h"

auto main() -> int {
    PasswordKeeper passwordKeeper;

    try {
        passwordKeeper.SetPassword({"joe", "Correct-Horse-Battery-Staple-1"});
    } catch (const PasswordException& e) {
        std::cerr << "Caught an exception when we shouldn't have: \"" << e.what() << "\"" << std::endl;
    }

    try {
        passwordKeeper.SetPassword({"joe", "monkey"});
    } catch (const PasswordTooShortException& e) {
        std::cout << e.what() << std::endl;
    }

    auto userExists = passwordKeeper.UserExists("joe");

    if (userExists) {
        std::cout << "User 'joe' exists." << std::endl;
    } else {
        std::cerr << "User 'joe' doesn't exist when they should." << std::endl;
    }

    return 0;
}