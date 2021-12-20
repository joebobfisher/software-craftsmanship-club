#include "FizzBuzz.h"

int main(int argc, char * argv[]) {
    FizzBuzz fizzBuzz;

    fizzBuzz.LoadArgs(argc, argv);
    fizzBuzz.Iterate();
}
