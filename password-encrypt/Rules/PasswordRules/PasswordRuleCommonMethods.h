#ifndef PASSWORD_PASSWORDRULECOMMONMETHODS_H
#define PASSWORD_PASSWORDRULECOMMONMETHODS_H


class PasswordRuleCommonMethods {
public:
    static auto IsAllowedSpecialChar(const char c) -> bool {    // NOLINT(readability-identifier-length)
        return (c == '!' || c == '@' || c == '#' || c == '$' ||
                c == '%' || c == '^' || c == '&' || c == '*' ||
                c == '(' || c == ')' || c == '-' || c == '_' ||
                c == '=' || c == '+');
    }
};


#endif //PASSWORD_PASSWORDRULECOMMONMETHODS_H
