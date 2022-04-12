#ifndef PASSWORD_PASSWORDUSERNAMERULE_H
#define PASSWORD_PASSWORDUSERNAMERULE_H


#include "Rule.h"
#include "PasswordExceptions.h"
#include <regex>

class PasswordUsernameRule : public Rule {
public:
    void Check(const PasswordObject& password) override {
        std::regex expr(password.Username, std::regex::icase);
        if (std::regex_search(password.Password, expr)) {
            throw PasswordHasUsernameException("Password can't contain the username (regardless of case).");
        }
    }
};


#endif //PASSWORD_PASSWORDUSERNAMERULE_H
