#include "PasswordKeeper.h"

void PasswordKeeper::SetPassword(const PasswordObject& password) {
    if (password.Password.length() < MinPasswordLength) {
        throw PasswordTooShortException("Password should be at least " +
            std::to_string(MinPasswordLength) + " characters.");
    }

    if (password.Password.length() > MaxPasswordLength) {
        throw PasswordTooLongException("Password can't be more than " +
            std::to_string(MaxPasswordLength) + " characters.");
    }

    Passwords.insert({password.Username, password.Password});
}

auto PasswordKeeper::UserExists(const std::string& userName) -> bool {
    return Passwords.count(userName) > 0;
}
