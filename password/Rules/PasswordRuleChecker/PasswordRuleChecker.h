#ifndef PASSWORD_PASSWORDRULECHECKER_H
#define PASSWORD_PASSWORDRULECHECKER_H


#include <vector>
#include <memory>
#include "PasswordRules.h"

class PasswordRuleChecker {
public:
    PasswordRuleChecker();
    void CheckPassword(const PasswordObject& password);

private:
    std::vector<Rule*> Rules{};
};


#endif //PASSWORD_PASSWORDRULECHECKER_H
