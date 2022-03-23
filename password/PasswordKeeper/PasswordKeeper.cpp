#include "PasswordKeeper.h"

void PasswordKeeper::SetPassword(const PasswordObject& password) {
    if (password.Password.length() < MinPasswordLength) {
        throw PasswordTooShortException("Password should be at least 8 characters.");
    }

    Passwords.insert({password.Username, password.Password});
}

auto PasswordKeeper::UserExists(const std::string& userName) -> bool {
    return Passwords.count(userName) > 0;
}
