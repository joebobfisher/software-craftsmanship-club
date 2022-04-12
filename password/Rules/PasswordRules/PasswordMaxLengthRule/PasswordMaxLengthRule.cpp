#include "PasswordMaxLengthRule.h"
#include "PasswordExceptions.h"

void PasswordMaxLengthRule::Check(const PasswordObject &password) {
    if (password.Password.length() > MaxPasswordLength) {
        throw PasswordTooLongException("Password can't be more than " +
                                       std::to_string(MaxPasswordLength) + " characters.");
    }
}