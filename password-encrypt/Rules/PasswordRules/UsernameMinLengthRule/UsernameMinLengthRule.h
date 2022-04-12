#ifndef PASSWORD_USERNAMEMINLENGTHRULE_H
#define PASSWORD_USERNAMEMINLENGTHRULE_H


#include "Rule.h"
#include "PasswordExceptions.h"

class UsernameMinLengthRule : public Rule {
public:
    void Check(const PasswordObject& password) override {
        if (password.Username.length() < MinUsernameLength) {
            throw UsernameTooShortException("Username must be at least " +
                                            std::to_string(MinUsernameLength) + " characters.");
        }
    }
private:
    const int MinUsernameLength = 3;
};


#endif //PASSWORD_USERNAMEMINLENGTHRULE_H
