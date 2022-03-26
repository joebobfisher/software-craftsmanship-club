#ifndef PASSWORD_PASSWORDKEEPER_H
#define PASSWORD_PASSWORDKEEPER_H


#include <map>
#include "PasswordObject.h"
#include "PasswordExceptions.h"

class PasswordKeeper {
public:
    void SetPassword(const PasswordObject& password);
    auto UserExists(const std::string& userName) -> bool;
    const int MinPasswordLength = 8;
    const int MaxPasswordLength = 255;
    const int MinUsernameLength = 3;
    const int MaxUsernameLength = 31;
private:
    std::map<std::string, std::string> Passwords;
};


#endif //PASSWORD_PASSWORDKEEPER_H
