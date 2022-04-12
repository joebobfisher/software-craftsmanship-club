#ifndef PASSWORD_RULECHECKER_H
#define PASSWORD_RULECHECKER_H


#include <vector>
#include <memory>
#include "Rule.h"

class RuleChecker {
public:
    RuleChecker();
    void RunRulesChecks(const PasswordObject& password);

private:
    // Can't have a vector of abstract classes, but one can have a vector of pointers to them!
    std::vector<Rule*> Rules;
};


#endif //PASSWORD_RULECHECKER_H
