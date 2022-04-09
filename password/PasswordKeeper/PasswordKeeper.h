#ifndef PASSWORD_PASSWORDKEEPER_H
#define PASSWORD_PASSWORDKEEPER_H


#include <map>
#include "PasswordObject.h"
#include "PasswordExceptions.h"

class PasswordKeeper {
public:
    void SetPassword(const PasswordObject& password);
    auto UserExists(const std::string& userName) -> bool;

private:
    std::map<std::string, std::string> Passwords;
    const int MinPasswordLength = 8;
    const int MaxPasswordLength = 255;
    const int MinUsernameLength = 3;
    const int MaxUsernameLength = 31;

    void CheckPasswordTooShort(const PasswordObject &password) const;
    void CheckPasswordTooLong(const PasswordObject &password) const;
    void CheckPasswordLowercase(const PasswordObject &password) const;
    void CheckPasswordUppercase(const PasswordObject &password) const;
    void CheckPasswordDigits(const PasswordObject &password) const;
    void CheckPasswordSpecialChars(const PasswordObject &password) const;
    void CheckPasswordBadChars(const PasswordObject &password) const;
    void CheckPasswordUsername(const PasswordObject &password) const;
    void CheckUsernameTooShort(const PasswordObject &password) const;
    void CheckUsernameTooLong(const PasswordObject &password) const;
    void CheckUsernameBadChars(const PasswordObject &password) const;
    void CheckUsernameDigitStart(const PasswordObject &password) const;

    static auto IsAllowedSpecialChar(char c) -> bool;                              // NOLINT(readability-identifier-length)
};


#endif //PASSWORD_PASSWORDKEEPER_H
