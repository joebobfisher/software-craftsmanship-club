#include "FizzBuzz.h"

FizzBuzz::FizzBuzz() = default;

FizzBuzz::FizzBuzz(int targetNumber, std::string * numberStringsArray, std::ostream * outStream) {
    TargetNumber = targetNumber;
    NumberStrings = numberStringsArray;
    OutputStream = outStream;
}

FizzBuzz::~FizzBuzz() {
    delete [] NumberStrings;
}

// TODO return void here once you throw exceptions
int FizzBuzz::LoadArgs(int argc, char * argv[]) {
    if (argc != 2) {
        // TODO throw exception here?
        return 1;
    }

    TargetNumber = (int)strtol(argv[1], nullptr, 10);

    if (TargetNumber <= 0) {
        // TODO throw exception here?
        return 1;
    }

    // TODO just "return" instead of returning int (assuming we have exceptions above)?
    return 0;
}

void FizzBuzz::Iterate() {
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

        // TODO Inject your own cout to properly test (and not print during test runs!)
        std::cout << numberString << std::endl;
    }
}