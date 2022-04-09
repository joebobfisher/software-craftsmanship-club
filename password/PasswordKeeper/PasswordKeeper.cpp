#include "PasswordKeeper.h"
#include "PasswordRuleChecker.h"
#include "UsernameRuleChecker.h"
#include <regex>

void PasswordKeeper::SetPassword(const PasswordObject& password) {
    CheckPasswordTooLong(password);
    CheckPasswordLowercase(password);
    CheckPasswordUppercase(password);
    CheckPasswordDigits(password);
    CheckPasswordSpecialChars(password);
    CheckPasswordBadChars(password);
    CheckPasswordUsername(password);
    CheckUsernameTooShort(password);
    CheckUsernameTooLong(password);
    CheckUsernameBadChars(password);
    CheckUsernameDigitStart(password);

    auto passwordChecker = PasswordRuleChecker();
    auto usernameChecker = UsernameRuleChecker();

    passwordChecker.CheckPassword(password);

    Passwords.insert({password.Username, password.Password});
}

void PasswordKeeper::CheckUsernameDigitStart(const PasswordObject &password) const {
    if (isdigit(password.Username[0]) != 0) {
        throw UsernameStartsWithADigitException("Username starts with a digit.");
    }
}

void PasswordKeeper::CheckUsernameBadChars(const PasswordObject &password) const {
    bool foundNonAlphaNum = false;
    for (auto c : password.Username) {
        if (isalnum(c) == 0) {
            foundNonAlphaNum = true;
        }
    }
    if (foundNonAlphaNum) {
        throw UsernameBadCharactersException("Username has non-alphanumeric characters.");
    }
}

void PasswordKeeper::CheckUsernameTooLong(const PasswordObject &password) const {
    if (password.Username.length() > MaxUsernameLength) {
        throw UsernameTooLongException("Username can't be more than " +
                                       std::to_string(MinUsernameLength) + " characters.");
    }
}

void PasswordKeeper::CheckUsernameTooShort(const PasswordObject &password) const {
    if (password.Username.length() < MinUsernameLength) {
        throw UsernameTooShortException("Username should be at least " +
                                        std::to_string(MinUsernameLength) + " characters.");
    }
}

void PasswordKeeper::CheckPasswordUsername(const PasswordObject &password) const {
    std::regex expr(password.Username, std::regex::icase);
    if (std::regex_search(password.Password, expr)) {
        throw PasswordHasUsernameException("Password contains the username.");
    }
}

void PasswordKeeper::CheckPasswordBadChars(const PasswordObject &password) const {
    for (auto c : password.Password) {
        if (islower(c) == 0 &&
            isupper(c) == 0 &&
            isdigit(c) == 0 &&
            !IsAllowedSpecialChar(c)) {
            throw PasswordBadCharactersException("Password has invalid characters.");
        }
    }
}

auto PasswordKeeper::IsAllowedSpecialChar(const char c) -> bool {
    return (c == '!' || c == '@' || c == '#' || c == '$' ||
            c == '%' || c == '^' || c == '&' || c == '*' ||
            c == '(' || c == ')' || c == '-' || c == '_' ||
            c == '=' || c == '+');
}

void PasswordKeeper::CheckPasswordSpecialChars(const PasswordObject &password) const {
    bool foundSpecial = false;
    for (auto c : password.Password) {
        if (IsAllowedSpecialChar(c)) {
            foundSpecial = true;
        }
    }
    if (!foundSpecial) {
        throw PasswordNoSpecialCharException("Password doesn't have any of the necessary special characters.");
    }
}

void PasswordKeeper::CheckPasswordDigits(const PasswordObject &password) const {
    bool foundDigit = false;
    for (auto c : password.Password) {
        if (isdigit(c) != 0) {
            foundDigit = true;
        }
    }
    if (!foundDigit) {
        throw PasswordNoDigitException("Password doesn't have any digits.");
    }
}

void PasswordKeeper::CheckPasswordUppercase(const PasswordObject &password) const {
    bool foundUpper = false;
    for (auto c : password.Password) {
        if (isupper(c) != 0) {
            foundUpper = true;
        }
    }
    if (!foundUpper) {
        throw PasswordNoUppercaseException("Password doesn't have any uppercase letters.");
    }
}

void PasswordKeeper::CheckPasswordLowercase(const PasswordObject &password) const {
    bool foundLower = false;
    for (auto c : password.Password) {
        if (islower(c) != 0) {
            foundLower = true;
        }
    }
    if (!foundLower) {
        throw PasswordNoLowercaseException("Password doesn't have any lowercase letters.");
    }
}

void PasswordKeeper::CheckPasswordTooLong(const PasswordObject &password) const {
    if (password.Password.length() > MaxPasswordLength) {
        throw PasswordTooLongException("Password can't be more than " +
                                       std::to_string(MaxPasswordLength) + " characters.");
    }
}

auto PasswordKeeper::UserExists(const std::string& userName) -> bool {
    return Passwords.count(userName) > 0;
}
