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
private:
    std::map<std::string, std::string> Passwords;
};


#endif //PASSWORD_PASSWORDKEEPER_H
