#include "PasswordKeeper.h"
#include <regex>

void PasswordKeeper::SetPassword(const PasswordObject& password) {
    if (password.Password.length() < MinPasswordLength) {
        throw PasswordTooShortException("Password should be at least " +
                                        std::to_string(MinPasswordLength) + " characters.");
    }

    if (password.Password.length() > MaxPasswordLength) {
        throw PasswordTooLongException("Password can't be more than " +
                                       std::to_string(MaxPasswordLength) + " characters.");
    }

    // password no lowercase
    bool foundLower = false;
    for (auto c : password.Password) {
        if (std::islower(c) != 0) {
            foundLower = true;
        }
    }
    if (!foundLower) {
        throw PasswordNoLowercaseException("Password doesn't have any lowercase letters.");
    }

    // password no uppercase
    bool foundUpper = false;
    for (auto c : password.Password) {
        if (std::isupper(c) != 0) {
            foundUpper = true;
        }
    }
    if (!foundUpper) {
        throw PasswordNoUppercaseException("Password doesn't have any uppercase letters.");
    }

    // password no digit
    bool foundDigit = false;
    for (auto c : password.Password) {
        if (std::isdigit(c) != 0) {
            foundDigit = true;
        }
    }
    if (!foundDigit) {
        throw PasswordNoDigitException("Password doesn't have any digits.");
    }

    // password no special char
    bool foundSpecial = false;
    for (auto c : password.Password) {
        if (c == '!' || c == '@' || c == '#' || c == '$' ||
            c == '%' || c == '^' || c == '&' || c == '*' ||
            c == '(' || c == ')' || c == '-' || c == '_' ||
            c == '=' || c == '+') {
            foundSpecial = true;
        }
    }
    if (!foundSpecial) {
        throw PasswordNoSpecialCharException("Password doesn't have any of the necessary special characters.");
    }

    // password bad characters
    for (auto c : password.Password) {
        if (std::islower(c) == 0 &&
            std::isupper(c) == 0 &&
            std::isdigit(c) == 0 &&
            !(c == '!' || c == '@' || c == '#' || c == '$' ||
              c == '%' || c == '^' || c == '&' || c == '*' ||
              c == '(' || c == ')' || c == '-' || c == '_' ||
              c == '=' || c == '+')) {
            throw PasswordBadCharactersException("Password has invalid characters.");
        }
    }

    // password has username (mixed case)
    std::regex expr(password.Username, std::regex::icase);
    if (std::regex_search(password.Password, expr)) {
        throw PasswordHasUsernameException("Password contains the username.");
    }

    // username too short
    if (password.Username.length() < 3) {
        throw UsernameTooShortException("Username should be at least " +
                                        std::to_string(MinUsernameLength) + " characters.");
    }

    // username too long
    if (password.Username.length() > 31) {
        throw UsernameTooLongException("Username can't be more than " +
                                        std::to_string(MinUsernameLength) + " characters.");
    }

    // username non-alphanumeric
    bool foundNonAlphaNum = false;
    for (auto c : password.Username) {
        if (std::isalnum(c) == 0) {
            foundNonAlphaNum = true;
        }
    }
    if (foundNonAlphaNum) {
        throw UsernameBadCharactersException("Username has non-alphanumeric characters.");
    }

    // username starts with a digit
    if (isdigit(password.Username[0]) != 0) {
        throw UsernameStartsWithADigitException("Username starts with a digit.");
    }

    Passwords.insert({password.Username, password.Password});
}

auto PasswordKeeper::UserExists(const std::string& userName) -> bool {
    return Passwords.count(userName) > 0;
}
