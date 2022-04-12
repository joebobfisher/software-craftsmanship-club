#ifndef PASSWORD_PASSWORDSPECIALCHARSRULE_H
#define PASSWORD_PASSWORDSPECIALCHARSRULE_H


#include "Rule.h"
#include "PasswordExceptions.h"
#include "PasswordRuleCommonMethods.h"

class PasswordSpecialCharsRule : public Rule {
public:
    void Check(const PasswordObject& password) override {
        bool foundSpecial = false;
        for (auto c : password.Password) {  // NOLINT(readability-identifier-length)
            if (PasswordRuleCommonMethods::IsAllowedSpecialChar(c)) {
                foundSpecial = true;
            }
        }
        if (!foundSpecial) {
            throw PasswordNoSpecialCharException("Password must have one of the valid special characters.");
        }
    }
};


#endif //PASSWORD_PASSWORDSPECIALCHARSRULE_H
