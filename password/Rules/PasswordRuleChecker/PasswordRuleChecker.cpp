#include "PasswordRuleChecker.h"

PasswordRuleChecker::PasswordRuleChecker() {
    Rules = {new PasswordMinLengthRule(),
             new PasswordMaxLengthRule()};
}

void PasswordRuleChecker::CheckPassword(const PasswordObject& password) {
    for (auto & rule : Rules) {
        rule->Check(password);
    }
}