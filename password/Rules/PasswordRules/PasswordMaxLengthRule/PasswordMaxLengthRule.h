#ifndef PASSWORD_PASSWORDMAXLENGTHRULE_H
#define PASSWORD_PASSWORDMAXLENGTHRULE_H


#include "Rule.h"
#include "PasswordExceptions.h"

class PasswordMaxLengthRule : public Rule {
public:
    void Check(const PasswordObject& password) override {
        if (password.Password.length() > MaxPasswordLength) {
            throw PasswordTooLongException("Password can't be more than " +
                                           std::to_string(MaxPasswordLength) + " characters.");
        }
    }
private:
    const int MaxPasswordLength = 255;
};


#endif //PASSWORD_PASSWORDMAXLENGTHRULE_H
