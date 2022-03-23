#ifndef PASSWORD_PASSWORDTOOSHORTEXCEPTION_H
#define PASSWORD_PASSWORDTOOSHORTEXCEPTION_H


#include "PasswordException.h"
#include <utility>

class PasswordTooShortException : public PasswordException {
public:
    explicit PasswordTooShortException(std::string whatArg) : ExceptionString(std::move(whatArg)) {}

    auto what() const noexcept -> const char* override {
        return ExceptionString.c_str();
    }

private:
    std::string ExceptionString;
};


#endif //PASSWORD_PASSWORDTOOSHORTEXCEPTION_H
