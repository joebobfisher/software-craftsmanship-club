#ifndef PASSWORD_PASSWORDLOWERCASERULE_H
#define PASSWORD_PASSWORDLOWERCASERULE_H


#include "Rule.h"
#include "PasswordExceptions.h"

class PasswordLowercaseRule : public Rule {
public:
    void Check(const PasswordObject& password) override {
        bool foundLower = false;
        for (auto c : password.Password) {  // NOLINT(readability-identifier-length)
            if (islower(c) != 0) {
                foundLower = true;
            }
        }
        if (!foundLower) {
            throw PasswordNoLowercaseException("Password must have a lowercase letter.");
        }
    }
};


#endif //PASSWORD_PASSWORDLOWERCASERULE_H
