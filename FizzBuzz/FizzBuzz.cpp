#include <cstdlib>
#include "FizzBuzz.h"

int FizzBuzz::Go(int argc, char * argv[]) {
    if (argc != 2) {
        return 1;
    }

    auto targetNumber = strtol(argv[1], nullptr, 10);

    if (targetNumber <= 0) {
        return 1;
    }

    return 0;
}