#include <iostream>
#include "Arithmetic/Arithmetic.h"

auto main() -> int {
    Arithmetic arithmetic;

    std::cout << arithmetic.Calculate("( 1 + 1 )") << std::endl;
    std::cout << arithmetic.Calculate("( ( 1 + 2 ) * ( 3 * 4 ) )") << std::endl;
    std::cout << arithmetic.Calculate("( 1 + ( ( 2 + 3 ) * ( 4 * 5 ) ) )") << std::endl;
    std::cout << arithmetic.Calculate("( 5 * ( 4 * ( 3 * ( 2 * ( 1 * 9 ) / 8 - 7 ) + 6 ) ) )") << std::endl;
    std::cout << arithmetic.Calculate("( ( ( ) ( ) ) )") << std::endl;
    std::cout << arithmetic.Calculate("3 + ( 2 * 1 )") << std::endl;

    return 0;
}
