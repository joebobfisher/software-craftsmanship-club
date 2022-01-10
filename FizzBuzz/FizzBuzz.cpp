#include "FizzBuzz.h"

#define BASE_10 10

FizzBuzz::FizzBuzz() = default;

FizzBuzz::FizzBuzz(int targetNumber, std::ostream * outStream) {
    TargetNumber = targetNumber;
    OutputStream = outStream;
}

void FizzBuzz::LoadArgs(int argc, char * argv[]) {
    if (argc != 2) {
        throw std::invalid_argument("Too few or too many arguments");
    }

    TargetNumber = (int)strtol(argv[1], nullptr, BASE_10);

    if (TargetNumber <= 0) {
        throw std::invalid_argument("Argument must be natural number");
    }
}

void FizzBuzz::Iterate() {
    for (int number = 1; number < TargetNumber+1; number++) {
        std::string numberString;

        AddFizzToStringIfNeeded(number, numberString);
        AddBuzzToStringIfNeeded(number, numberString);
        SetStringToNumberIfNotSetYet(number, numberString);

        *OutputStream << numberString << std::endl;
    }
}

void FizzBuzz::AddFizzToStringIfNeeded(int number, std::string &numberString) {
    if (number % 3 == 0) {
        numberString += "Fizz";
    }
}

void FizzBuzz::AddBuzzToStringIfNeeded(int number, std::string &numberString) {
    if (number % 5 == 0) {
        numberString += "Buzz";
    }
}

void FizzBuzz::SetStringToNumberIfNotSetYet(int number, std::string &numberString) {
    if (numberString == "") {
        numberString = std::to_string(number);
    }
}
