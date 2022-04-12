#ifndef PASSWORD_PASSWORDUPPERCASERULE_H
#define PASSWORD_PASSWORDUPPERCASERULE_H


#include "Rule.h"
#include "PasswordExceptions.h"

class PasswordUppercaseRule : public Rule {
public:
    void Check(const PasswordObject& password) override {
        bool foundUpper = false;
        for (auto c : password.Password) {  // NOLINT(readability-identifier-length)
            if (isupper(c) != 0) {
                foundUpper = true;
            }
        }
        if (!foundUpper) {
            throw PasswordNoUppercaseException("Password must have an uppercase letter.");
        }
    }
};


#endif //PASSWORD_PASSWORDUPPERCASERULE_H
