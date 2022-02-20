#include <iostream>
#include "Arithmetic/Arithmetic.h"

auto main() -> int {
    Arithmetic arithmetic;

    std::cout << arithmetic.Calculate("(1 + 1)") << std::endl;

    return 0;
}
