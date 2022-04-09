#ifndef PASSWORD_RULE_H
#define PASSWORD_RULE_H


#include "PasswordObject.h"

class Rule {

public:
    virtual void Check(const PasswordObject& password) = 0;
    virtual ~Rule() = default;
};


#endif //PASSWORD_RULE_H
