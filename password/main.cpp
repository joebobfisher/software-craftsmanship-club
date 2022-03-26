#include <iostream>
#include "PasswordKeeper.h"

auto main() -> int {
    PasswordKeeper passwordKeeper;

    // Good case
    try {
        passwordKeeper.SetPassword({"joe", "Correct-Horse-Battery-Staple-1"});
    } catch (const PasswordException& e) {
        std::cerr << "Caught an exception when we shouldn't have: \"" << e.what() << "\"" << std::endl;
    }

    // password too short
    try {
        passwordKeeper.SetPassword({"joe", "M0nkey!"});
    } catch (const PasswordTooShortException& e) {
        std::cout << e.what() << std::endl;
    }

    // password too long
    try {
        std::string longPw = "Abcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()_+abcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()_+abcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()_+abcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()_+Abcdefghijklmnopqrstuvwxyz1234567890!@#$%^&*()_+abcdefghijklmnop";
        passwordKeeper.SetPassword({"joe", longPw});
    } catch (const PasswordTooLongException& e) {
        std::cout << e.what() << std::endl;
    }

    // password no lowercase

    // password no uppercase

    // password no digit

    // password no special char

    // password has username (mixed case)

    // username too short

    // username too long

    // username non-alphanumeric

    // username starts with a digit

    auto userExists = passwordKeeper.UserExists("joe");
    if (userExists) {
        std::cout << "User 'joe' exists." << std::endl;
    } else {
        std::cerr << "User 'joe' doesn't exist when they should." << std::endl;
    }

    return 0;
}