#ifndef FIZZBUZZ_FIZZBUZZ_H
#define FIZZBUZZ_FIZZBUZZ_H

#include <iostream>

class FizzBuzz {
public:
    FizzBuzz();
    FizzBuzz(int targetNumber, std::string * numberStringsArray, std::ostream * outStream);
    ~FizzBuzz();
    void LoadArgs(int argc, char * argv[]);
    void Iterate();

private:
    int TargetNumber = 0;
    std::string * NumberStrings = nullptr;
    std::ostream * OutputStream = nullptr;
};

#endif //FIZZBUZZ_FIZZBUZZ_H
