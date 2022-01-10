#ifndef FIZZBUZZ_FIZZBUZZ_H
#define FIZZBUZZ_FIZZBUZZ_H

#include <iostream>

class FizzBuzz {
public:
    FizzBuzz();
    FizzBuzz(int targetNumber, std::ostream * outStream);
    void LoadArgs(int argc, char * argv[]);
    void Iterate();

private:
    bool AddFizzToString(int number, std::string &numberString);
    bool AddBuzzToString(int number, std::string &numberString);
    void SetStringToNumber(int number, std::string &numberString, bool fizzOrBuzzWasAdded);

    int TargetNumber = 0;
    std::ostream * OutputStream = &std::cout;
};

#endif //FIZZBUZZ_FIZZBUZZ_H
