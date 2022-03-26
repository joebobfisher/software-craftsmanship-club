#ifndef PASSWORD_PASSWORDTOOLONGEXCEPTION_H
#define PASSWORD_PASSWORDTOOLONGEXCEPTION_H


#include "PasswordException.h"
#include <utility>

class PasswordTooLongException : public PasswordException {
public:
    explicit PasswordTooLongException(std::string whatArg) : ExceptionString(std::move(whatArg)) {}

    auto what() const noexcept -> const char* override {
        return ExceptionString.c_str();
    }

private:
    std::string ExceptionString;
};


#endif //PASSWORD_PASSWORDTOOLONGEXCEPTION_H
