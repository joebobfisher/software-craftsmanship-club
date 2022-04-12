#include "RuleChecker.h"
#include "PasswordRules.h"

RuleChecker::RuleChecker() {
    Rules = {new PasswordMinLengthRule(),
             new PasswordMaxLengthRule(),
             new PasswordLowercaseRule(),
             new PasswordUppercaseRule(),
             new PasswordDigitsRule(),
             new PasswordSpecialCharsRule(),
             new PasswordInvalidCharsRule(),
             new PasswordUsernameRule(),
             new UsernameMinLengthRule(),
             new UsernameMaxLengthRule(),
             new UsernameInvalidCharsRule(),
             new UsernameStartingDigitRule()};
}

void RuleChecker::RunRulesChecks(const PasswordObject& password) {
    for (auto & rule : Rules) {
        rule->Check(password);
    }
}