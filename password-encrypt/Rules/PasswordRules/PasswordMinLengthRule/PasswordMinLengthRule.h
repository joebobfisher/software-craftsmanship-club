#ifndef PASSWORD_PASSWORDMINLENGTHRULE_H
#define PASSWORD_PASSWORDMINLENGTHRULE_H


#include "Rule.h"
#include "PasswordExceptions.h"

class PasswordMinLengthRule : public Rule {
public:
    void Check(const PasswordObject& password) override {
        if (password.Password.length() < MinPasswordLength) {
            throw PasswordTooShortException("Password must be at least " +
                                            std::to_string(MinPasswordLength) + " characters.");
        }
    };
private:
    const int MinPasswordLength = 8;
};


#endif //PASSWORD_PASSWORDMINLENGTHRULE_H
