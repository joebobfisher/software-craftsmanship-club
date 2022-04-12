#ifndef PASSWORD_PASSWORDDIGITSRULE_H
#define PASSWORD_PASSWORDDIGITSRULE_H


#include "Rule.h"
#include "PasswordExceptions.h"

class PasswordDigitsRule : public Rule {
public:
    void Check(const PasswordObject& password) override {
        bool foundDigit = false;
        for (auto c : password.Password) {  // NOLINT(readability-identifier-length)
            if (isdigit(c) != 0) {
                foundDigit = true;
            }
        }
        if (!foundDigit) {
            throw PasswordNoDigitException("Password must have a digit.");
        }
    }
};


#endif //PASSWORD_PASSWORDDIGITSRULE_H
