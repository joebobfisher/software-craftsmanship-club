#include <iostream>
#include "Arithmetic/Arithmetic.h"

auto main() -> int {
    Arithmetic arithmetic;

    std::cout << arithmetic.Do("(1 + 1)") << std::endl;

    return 0;
}
