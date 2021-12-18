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
    void SetUp() override;

    int argc;
    char * argv[2];
    int inputNumber;
    char inputNumberCStr[INPUT_NUMBER_CSTR_ARRAY_SIZE];

    FizzBuzz target;
};

void FizzBuzzTest::SetUp() {
    srand(time(NULL));

    argc = 2;

    char appName[] = "fizzbuzz.exe";
    argv[0] = appName;

    inputNumber = rand() % MAX_INPUT_NUMBER + 1;
    itoa(inputNumber, inputNumberCStr, 10);
    argv[1] = inputNumberCStr;
}

TEST_F(FizzBuzzTest, LoadArgs_FailsOnNoArgs) {
    argc = 1;

    auto result = target.LoadArgs(argc, argv);

    ASSERT_EQ(result, 1);
}

TEST_F(FizzBuzzTest, LoadArgs_FailsOnTooManyArgs) {
    argc = rand() % (RAND_MAX - 2) + 2;

    auto result = target.LoadArgs(argc, argv);

    ASSERT_EQ(result, 1);
}

TEST_F(FizzBuzzTest, LoadArgs_FailsOnNonIntArg) {
    char abc[] = "abc";
    argv[1] = abc;

    auto result = target.LoadArgs(argc, argv);

    ASSERT_EQ(result, 1);
}

TEST_F(FizzBuzzTest, LoadArgs_FailsOnNegativeInt) {
    inputNumber = inputNumber * -1;
    itoa(inputNumber, inputNumberCStr, 10);
    argv[1] = inputNumberCStr;

    auto result = target.LoadArgs(argc, argv);

    ASSERT_EQ(result, 1);
}

TEST_F(FizzBuzzTest, LoadArgs_SucceedsOnCorrectArgs) {
    auto result = target.LoadArgs(argc, argv);

    ASSERT_EQ(result, 0);
}

TEST_F(FizzBuzzTest, Iterate_IteratesNumbersAndFizzBuzz) {
    std::string expectedArray[15] = {"1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"};
    std::string * actualArray = new std::string[15];

    // TODO why does destructor run _after_ new constructor (deletes our actualArray)?!
    FizzBuzz newTarget = FizzBuzz(15, actualArray, nullptr);

    newTarget.Iterate();

    for (int i = 0; i < 15; i++) {
        ASSERT_EQ(actualArray[i], expectedArray[i]);
    }
}