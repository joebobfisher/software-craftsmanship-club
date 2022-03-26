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
    try {
        passwordKeeper.SetPassword({"joe", "M0NKIES!"});
    } catch (const PasswordNoLowercaseException& e) {
        std::cout << e.what() << std::endl;
    }

    // password no uppercase
    try {
        passwordKeeper.SetPassword({"joe", "m0nkies!"});
    } catch (const PasswordNoUppercaseException& e) {
        std::cout << e.what() << std::endl;
    }

    // password no digit
    try {
        passwordKeeper.SetPassword({"joe", "Monkies!"});
    } catch (const PasswordNoDigitException& e) {
        std::cout << e.what() << std::endl;
    }

    // password no special char
    try {
        passwordKeeper.SetPassword({"joe", "Monkies1"});
    } catch (const PasswordNoSpecialCharException& e) {
        std::cout << e.what() << std::endl;
    }

    // password bad characters
    try {
        passwordKeeper.SetPassword({"joe", "M0nkies!/"});
    } catch (const PasswordBadCharactersException& e) {
        std::cout << e.what() << std::endl;
    }

    // password has username (mixed case)
    try {
        passwordKeeper.SetPassword({"joe", "M0nkeyJoEM0nkey!"});
    } catch (const PasswordHasUsernameException& e) {
        std::cout << e.what() << std::endl;
    }

    // username too short
    try {
        passwordKeeper.SetPassword({"jo", "M0nkies!"});
    } catch (const UsernameTooShortException& e) {
        std::cout << e.what() << std::endl;
    }

    // username too long
    try {
        passwordKeeper.SetPassword({"HubertWolfeschlegelsteinhausenSr", "M0nkies!"});
    } catch (const UsernameTooLongException& e) {
        std::cout << e.what() << std::endl;
    }

    // username non-alphanumeric
    try {
        passwordKeeper.SetPassword({"j@e", "M0nkies!"});
    } catch (const UsernameBadCharactersException& e) {
        std::cout << e.what() << std::endl;
    }

    // username starts with a digit
    try {
        passwordKeeper.SetPassword({"1oe", "M0nkies!"});
    } catch (const UsernameStartsWithADigitException& e) {
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