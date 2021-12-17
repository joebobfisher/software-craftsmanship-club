#include "gtest/gtest.h"
#include "FizzBuzz.h"

TEST(FizzBuzz, FailsOnNoArgs) {
    int argc = 1;
    char appName[] = "fizzbuzz.exe";
    char * argv[] = {appName};

    FizzBuzz fizzBuzz;
    auto result = fizzBuzz.Go(argc, argv);

    ASSERT_EQ(result, 1);
}
