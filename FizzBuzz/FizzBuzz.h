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
    static void AddFizzToStringIfNeeded(int number, std::string &numberString);
    static void AddBuzzToStringIfNeeded(int number, std::string &numberString);
    static void SetStringToNumberIfNotSetYet(int number, std::string &numberString);

    int TargetNumber = 0;
    std::ostream * OutputStream = &std::cout;
};

#endif //FIZZBUZZ_FIZZBUZZ_H
