#ifndef PASSWORD_USERNAMESTARTINGDIGITSRULE_H
#define PASSWORD_USERNAMESTARTINGDIGITSRULE_H


#include "Rule.h"
#include "PasswordExceptions.h"

class UsernameStartingDigitRule : public Rule {
public:
    void Check(const PasswordObject& password) override {
        if (isdigit(password.Username[0]) != 0) {
            throw UsernameStartsWithADigitException("Username can't start with a digit.");
        }
    }
};


#endif //PASSWORD_USERNAMESTARTINGDIGITSRULE_H
