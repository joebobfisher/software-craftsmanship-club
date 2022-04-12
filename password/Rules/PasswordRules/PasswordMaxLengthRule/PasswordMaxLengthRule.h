#ifndef PASSWORD_PASSWORDMAXLENGTHRULE_H
#define PASSWORD_PASSWORDMAXLENGTHRULE_H


#include "Rule.h"

class PasswordMaxLengthRule : public Rule {
public:
    void Check(const PasswordObject& password) override;
private:
    const int MaxPasswordLength = 255;
};


#endif //PASSWORD_PASSWORDMAXLENGTHRULE_H
