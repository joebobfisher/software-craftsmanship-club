#ifndef PASSWORD_PASSWORDINVALIDCHARSRULE_H
#define PASSWORD_PASSWORDINVALIDCHARSRULE_H


#include "Rule.h"
#include "PasswordExceptions.h"
#include "PasswordRuleCommonMethods.h"

class PasswordInvalidCharsRule : public Rule {
public:
    void Check(const PasswordObject& password) override {
        for (auto c : password.Password) {  // NOLINT(readability-identifier-length)
            if (islower(c) == 0 &&
                isupper(c) == 0 &&
                isdigit(c) == 0 &&
                !PasswordRuleCommonMethods::IsAllowedSpecialChar(c)) {
                throw PasswordBadCharactersException("Password can't have any invalid special characters.");
            }
        }
    }
};


#endif //PASSWORD_PASSWORDINVALIDCHARSRULE_H
