#include "PasswordRuleChecker.h"

PasswordRuleChecker::PasswordRuleChecker() {
    Rules.emplace_back(PasswordMinLengthRule());
}

void PasswordRuleChecker::CheckPassword(const PasswordObject& password) {
    for (auto & rule : Rules) {
        rule.Check(password);
    }
}