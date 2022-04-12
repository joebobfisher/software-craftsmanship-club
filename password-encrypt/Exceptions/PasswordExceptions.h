#ifndef PASSWORD_PASSWORDEXCEPTIONS_H
#define PASSWORD_PASSWORDEXCEPTIONS_H


#include <string>
#include <exception>
#include <utility>

class PasswordException : public std::exception {
public:
    auto what() const noexcept -> const char* override {
        return ExceptionString.c_str();
    }

protected:
    std::string ExceptionString;    // NOLINT(cppcoreguidelines-non-private-member-variables-in-classes)
};

class PasswordTooShortException : public PasswordException {
public:
    explicit PasswordTooShortException(std::string whatArg) {
        ExceptionString = std::move(whatArg);
    }
};

class PasswordTooLongException : public PasswordException {
public:
    explicit PasswordTooLongException(std::string whatArg) {
        ExceptionString = std::move(whatArg);
    }
};

class PasswordNoLowercaseException : public PasswordException {
public:
    explicit PasswordNoLowercaseException(std::string whatArg) {
        ExceptionString = std::move(whatArg);
    }
};

class PasswordNoUppercaseException : public PasswordException {
public:
    explicit PasswordNoUppercaseException(std::string whatArg) {
        ExceptionString = std::move(whatArg);
    }
};

class PasswordNoDigitException : public PasswordException {
public:
    explicit PasswordNoDigitException(std::string whatArg) {
        ExceptionString = std::move(whatArg);
    }
};

class PasswordNoSpecialCharException : public PasswordException {
public:
    explicit PasswordNoSpecialCharException(std::string whatArg) {
        ExceptionString = std::move(whatArg);
    }
};

class PasswordBadCharactersException : public PasswordException {
public:
    explicit PasswordBadCharactersException(std::string whatArg) {
        ExceptionString = std::move(whatArg);
    }
};

class PasswordHasUsernameException : public PasswordException {
public:
    explicit PasswordHasUsernameException(std::string whatArg) {
        ExceptionString = std::move(whatArg);
    }
};

class UsernameTooShortException : public PasswordException {
public:
    explicit UsernameTooShortException(std::string whatArg) {
        ExceptionString = std::move(whatArg);
    }
};

class UsernameTooLongException : public PasswordException {
public:
    explicit UsernameTooLongException(std::string whatArg) {
        ExceptionString = std::move(whatArg);
    }
};

class UsernameBadCharactersException : public PasswordException {
public:
    explicit UsernameBadCharactersException(std::string whatArg) {
        ExceptionString = std::move(whatArg);
    }
};

class UsernameStartsWithADigitException : public PasswordException {
public:
    explicit UsernameStartsWithADigitException(std::string whatArg) {
        ExceptionString = std::move(whatArg);
    }
};


#endif //PASSWORD_PASSWORDEXCEPTIONS_H
