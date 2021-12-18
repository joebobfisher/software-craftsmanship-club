#include "FizzBuzz.h"

int main(int argc, char * argv[]) {
    FizzBuzz fizzBuzz;

    (void)fizzBuzz.LoadArgs(argc, argv);
    fizzBuzz.Iterate();
}
