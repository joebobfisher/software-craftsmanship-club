#include "FizzBuzz.h"

#define BASE_10 10

FizzBuzz::FizzBuzz() = default;

FizzBuzz::FizzBuzz(int targetNumber, std::string * numberStringsArray, std::ostream * outStream) {
    TargetNumber = targetNumber;
    NumberStrings = numberStringsArray;
    OutputStream = outStream;
}

FizzBuzz::~FizzBuzz() {
    delete [] NumberStrings;
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
    // TODO this if statement is necessary, but how to test it?
    if (NumberStrings == nullptr) {
        NumberStrings = new std::string[TargetNumber];
    }

    for (int i = 0; i < TargetNumber; i++) {
        int number = i + 1;
        std::string numberString;

        if (number % 3 != 0 && number % 5 != 0) {
            numberString = std::to_string(number);
        } else {
            if (number % 3 == 0) {
                numberString += "Fizz";
            }
            if (number % 5 == 0) {
                numberString += "Buzz";
            }
        }

        NumberStrings[i] = numberString;

        // TODO Again how to test the if statement?
        if (OutputStream == nullptr) {
            OutputStream = &std::cout;
        }
        *OutputStream << numberString << std::endl;
    }
}