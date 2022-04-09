#ifndef PASSWORD_PASSWORDMINLENGTHRULE_H
#define PASSWORD_PASSWORDMINLENGTHRULE_H


#include "Rule.h"

class PasswordMinLengthRule : public Rule {
public:
    PasswordMinLengthRule() = default;
    void Check(const PasswordObject& password) override;
private:
    const int MinPasswordLength = 8;
};


#endif //PASSWORD_PASSWORDMINLENGTHRULE_H
