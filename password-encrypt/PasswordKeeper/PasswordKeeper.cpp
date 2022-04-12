#include "PasswordKeeper.h"
#include "RuleChecker.h"

void PasswordKeeper::SetPassword(const PasswordObject& password) {
    auto ruleChecker = RuleChecker();
    ruleChecker.RunRulesChecks(password);

    Passwords.insert({password.Username, password.Password});
}

auto PasswordKeeper::UserExists(const std::string& userName) -> bool {
    return Passwords.count(userName) > 0;
}
