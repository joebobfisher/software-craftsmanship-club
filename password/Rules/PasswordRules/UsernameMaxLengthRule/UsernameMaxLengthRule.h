#ifndef PASSWORD_USERNAMEMAXLENGTHRULE_H
#define PASSWORD_USERNAMEMAXLENGTHRULE_H


#include "Rule.h"
#include "PasswordExceptions.h"

class UsernameMaxLengthRule : public Rule {
public:
    void Check(const PasswordObject& password) override {
        if (password.Username.length() > MaxUsernameLength) {
            throw UsernameTooLongException("Username can't be more than " +
                                           std::to_string(MaxUsernameLength) + " characters.");
        }
    }
private:
    const int MaxUsernameLength = 31;
};


#endif //PASSWORD_USERNAMEMAXLENGTHRULE_H
