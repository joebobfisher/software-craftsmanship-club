#ifndef PASSWORD_USERNAMEINVALIDCHARSRULE_H
#define PASSWORD_USERNAMEINVALIDCHARSRULE_H


#include "Rule.h"
#include "PasswordExceptions.h"

class UsernameInvalidCharsRule : public Rule {
public:
    void Check(const PasswordObject& password) override {
        bool foundNonAlphaNum = false;
        for (auto c : password.Username) {  // NOLINT(readability-identifier-length)
            if (isalnum(c) == 0) {
                foundNonAlphaNum = true;
            }
        }
        if (foundNonAlphaNum) {
            throw UsernameBadCharactersException("Username must have only alphanumeric characters.");
        }
    }
};


#endif //PASSWORD_USERNAMEINVALIDCHARSRULE_H
