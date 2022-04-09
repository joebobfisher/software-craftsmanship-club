#include "PasswordMinLengthRule.h"
#include "PasswordExceptions.h"

void PasswordMinLengthRule::Check(const PasswordObject& password) {
    if (password.Password.length() < MinPasswordLength) {
        throw PasswordTooShortException("Password should be at least " +
                                        std::to_string(MinPasswordLength) + " characters.");
    }
}