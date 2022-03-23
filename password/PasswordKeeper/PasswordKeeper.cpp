#include "PasswordKeeper.h"

void PasswordKeeper::SetPassword(Password password) {
    throw PasswordTooShortException("Password should be at least 8 characters.");
}

bool PasswordKeeper::UserExists(std::string userName) {
    return false;
}
