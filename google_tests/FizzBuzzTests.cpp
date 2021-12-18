#include "gtest/gtest.h"
#include "FizzBuzz.h"

#define MAX_INPUT_NUMBER 99
#define MAX_INPUT_NUMBER_CSTR_SIZE 3

class FizzBuzzTest : public ::testing::Test {
protected:
    void SetUp() override {
        srand(time(NULL));

        argc = 2;

        char appName[] = "fizzbuzz.exe";
        argv[0] = appName;

        int inputNumber = rand() % MAX_INPUT_NUMBER + 1;
        char inputNumberCStr[MAX_INPUT_NUMBER_CSTR_SIZE];
        itoa(inputNumber, inputNumberCStr, 10);
        argv[1] = inputNumberCStr;
    }

    int argc;
    char * argv[2];
    FizzBuzz fizzBuzz;
};

TEST_F(FizzBuzzTest, FailsOnNoArgs) {
    argc = 1;

    auto result = fizzBuzz.Go(argc, argv);

    ASSERT_EQ(result, 1);
}

TEST_F(FizzBuzzTest, SucceedsOnOneArg) {
    auto result = fizzBuzz.Go(argc, argv);

    ASSERT_EQ(result, 0);
}

TEST_F(FizzBuzzTest, FailsOnTooManyArgs) {
    argc = rand() % (RAND_MAX - 2) + 2;

    auto result = fizzBuzz.Go(argc, argv);

    ASSERT_EQ(result, 1);
}
