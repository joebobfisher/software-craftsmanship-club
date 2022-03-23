#ifndef PASSWORD_PASSWORDKEEPER_H
#define PASSWORD_PASSWORDKEEPER_H


#include "Password.h"
#include "PasswordExceptions.h"

class PasswordKeeper {
public:
    void SetPassword(Password password);
    bool UserExists(std::string userName);
};


#endif //PASSWORD_PASSWORDKEEPER_H
