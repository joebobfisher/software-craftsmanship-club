#ifndef PASSWORD_RULE_H
#define PASSWORD_RULE_H


#include "PasswordObject.h"

class Rule {
public:
    virtual void Check(const PasswordObject& password) = 0;
    virtual ~Rule() = default;      // Important here since we're `new`ing stuff in the rule checker
};


#endif //PASSWORD_RULE_H
