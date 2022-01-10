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
        bool fizzOrBuzzWasAdded;

        fizzOrBuzzWasAdded = AddFizzToString(number, numberString);
        fizzOrBuzzWasAdded |= AddBuzzToString(number, numberString);
        SetStringToNumber(number, numberString, fizzOrBuzzWasAdded);

        *OutputStream << numberString << std::endl;
    }
}

bool FizzBuzz::AddFizzToString(int number, std::string &numberString) {
    bool addedFizz = false;

    if (number % 3 == 0) {
        numberString += "Fizz";
        addedFizz = true;
    }

    return addedFizz;
}

bool FizzBuzz::AddBuzzToString(int number, std::string &numberString) {
    bool addedBuzz = false;

    if (number % 5 == 0) {
        numberString += "Buzz";
        addedBuzz = true;
    }

    return addedBuzz;
}

void FizzBuzz::SetStringToNumber(int number, std::string &numberString, bool fizzOrBuzzWasAdded) {
    if (!fizzOrBuzzWasAdded) {
        numberString = std::to_string(number);
    }
}
