#include "gtest/gtest.h"
#include "FizzBuzz.h"

#define MAX_INPUT_NUMBER 99
#define MAX_INPUT_NUMBER_CSTR_SIZE 2
#define SPACE_FOR_NEG_SIGN 1
#define SPACE_FOR_NULL_TERM 1
#define INPUT_NUMBER_CSTR_ARRAY_SIZE MAX_INPUT_NUMBER_CSTR_SIZE + \
                                     SPACE_FOR_NEG_SIGN + \
                                     SPACE_FOR_NULL_TERM

#define BASE_10 10

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
    srand(time(nullptr));

    argc = 2;

    char appName[] = "fizzbuzz.exe";
    argv[0] = appName;

    inputNumber = rand() % MAX_INPUT_NUMBER + 1;
    itoa(inputNumber, inputNumberCStr, BASE_10);
    argv[1] = inputNumberCStr;
}

TEST_F(FizzBuzzTest, LoadArgs_FailsOnNoArgs) { // NOLINT Clang-Tidy doesn't get Google Test macros
    argc = 1;

    try {
        target.LoadArgs(argc, argv);
    }
    catch (std::invalid_argument &e) {
        ASSERT_STREQ(e.what(), "Too few or too many arguments");
    }
}

TEST_F(FizzBuzzTest, LoadArgs_FailsOnTooManyArgs) { // NOLINT Clang-Tidy doesn't get Google Test macros
    argc = rand() % (RAND_MAX - 2) + 2;

    try {
        target.LoadArgs(argc, argv);
    }
    catch (std::invalid_argument &e) {
        ASSERT_STREQ(e.what(), "Too few or too many arguments");
    }
}

TEST_F(FizzBuzzTest, LoadArgs_FailsOnNonIntArg) { // NOLINT Clang-Tidy doesn't get Google Test macros
    char abc[] = "abc";
    argv[1] = abc;

    try {
        target.LoadArgs(argc, argv);
    }
    catch (std::invalid_argument &e) {
        ASSERT_STREQ(e.what(), "Argument must be natural number");
    }
}

TEST_F(FizzBuzzTest, LoadArgs_FailsOnNegativeInt) { // NOLINT Clang-Tidy doesn't get Google Test macros
    inputNumber = inputNumber * -1;
    itoa(inputNumber, inputNumberCStr, BASE_10);
    argv[1] = inputNumberCStr;

    try {
        target.LoadArgs(argc, argv);
    }
    catch (std::invalid_argument &e) {
        ASSERT_STREQ(e.what(), "Argument must be natural number");
    }
}

TEST_F(FizzBuzzTest, LoadArgs_FailsOnZero) { // NOLINT Clang-Tidy doesn't get Google Test macros
    itoa(0, inputNumberCStr, BASE_10);
    argv[1] = inputNumberCStr;

    try {
        target.LoadArgs(argc, argv);
    }
    catch (std::invalid_argument &e) {
        ASSERT_STREQ(e.what(), "Argument must be natural number");
    }
}

TEST_F(FizzBuzzTest, LoadArgs_SucceedsOnCorrectArgs) { // NOLINT Clang-Tidy doesn't get Google Test macros
    try {
        target.LoadArgs(argc, argv);
    }
    catch (...) {
        FAIL();
    }

    SUCCEED();
}

TEST_F(FizzBuzzTest, Iterate_IteratesNumbersAndFizzBuzz) { // NOLINT Clang-Tidy doesn't get Google Test macros
    std::vector<std::string> expectedAnswers { "1","2","Fizz","4","Buzz","Fizz","7","8",
                                               "Fizz","Buzz","11","Fizz","13","14","FizzBuzz" };
    std::string actual;

    std::stringstream stream;
    std::ostream dummyOutStream(stream.rdbuf());

    FizzBuzz newTarget = FizzBuzz(15, &dummyOutStream);

    newTarget.Iterate();

    for (auto &expected : expectedAnswers) {
        std::getline(stream, actual);
        ASSERT_STREQ(actual.c_str(), expected.c_str());
    }

    if (std::getline(stream, actual)) {
        FAIL();
    }
}

