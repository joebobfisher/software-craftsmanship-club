#include "PasswordRuleChecker.h"

PasswordRuleChecker::PasswordRuleChecker() {
    Rules = {new PasswordMinLengthRule()};
}

void PasswordRuleChecker::CheckPassword(const PasswordObject& password) {
    for (auto & rule : Rules) {
        rule->Check(password);
    }
}