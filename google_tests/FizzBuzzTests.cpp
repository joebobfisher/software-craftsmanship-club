#include "gtest/gtest.h"
#include "FizzBuzz.h"

#define MAX_INPUT_NUMBER 99
#define MAX_INPUT_NUMBER_CSTR_SIZE 2
#define SPACE_FOR_NEG_SIGN 1
#define SPACE_FOR_NULL_TERM 1
#define INPUT_NUMBER_CSTR_ARRAY_SIZE MAX_INPUT_NUMBER_CSTR_SIZE + \
                                     SPACE_FOR_NEG_SIGN + \
                                     SPACE_FOR_NULL_TERM

class FizzBuzzTest : public ::testing::Test {
protected:
    void SetUp() override {
        srand(time(NULL));

        argc = 2;

        char appName[] = "fizzbuzz.exe";
        argv[0] = appName;

        inputNumber = rand() % MAX_INPUT_NUMBER + 1;
        itoa(inputNumber, inputNumberCStr, 10);
        argv[1] = inputNumberCStr;
    }

    int argc;
    char * argv[2];
    int inputNumber;
    char inputNumberCStr[INPUT_NUMBER_CSTR_ARRAY_SIZE];
};

TEST_F(FizzBuzzTest, FailsOnNoArgs) {
    argc = 1;

    auto result = FizzBuzz::Go(argc, argv);

    ASSERT_EQ(result, 1);
}

TEST_F(FizzBuzzTest, FailsOnTooManyArgs) {
    argc = rand() % (RAND_MAX - 2) + 2;

    auto result = FizzBuzz::Go(argc, argv);

    ASSERT_EQ(result, 1);
}

TEST_F(FizzBuzzTest, FailsOnNonIntArg) {
    char abc[] = "abc";
    argv[1] = abc;

    auto result = FizzBuzz::Go(argc, argv);

    ASSERT_EQ(result, 1);
}

TEST_F(FizzBuzzTest, FailsOnNegativeInt) {
    inputNumber = inputNumber * -1;
    itoa(inputNumber, inputNumberCStr, 10);
    argv[1] = inputNumberCStr;

    auto result = FizzBuzz::Go(argc, argv);

    ASSERT_EQ(result, 1);
}

TEST_F(FizzBuzzTest, SucceedsOnCorrectArgs) {
    auto result = FizzBuzz::Go(argc, argv);

    ASSERT_EQ(result, 0);
}
