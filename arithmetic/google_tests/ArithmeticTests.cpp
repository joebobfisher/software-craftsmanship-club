#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wunknown-pragmas"
#pragma ide diagnostic ignored "cppcoreguidelines-avoid-non-const-global-variables"
#pragma ide diagnostic ignored "cppcoreguidelines-owning-memory"
#pragma ide diagnostic ignored "cert-err58-cpp"
#pragma ide diagnostic ignored "cppcoreguidelines-avoid-goto"
#pragma ide diagnostic ignored "cppcoreguidelines-non-private-member-variables-in-classes"

#include "gtest/gtest.h"
#include "Arithmetic.h"

 class ArithmeticTest : public ::testing::Test {
 protected:
     void SetUp() override;

     Arithmetic target;
 };

 void ArithmeticTest::SetUp() {
     // nothing for now.
 }

TEST_F(ArithmeticTest, CalculateThrowsErrorIfEmptyString) {
    try {
        target.Calculate("");
    }
    catch (std::invalid_argument &e) {
        ASSERT_STREQ(e.what(), "Expression must be surrounded by parentheses");
    }
}

TEST_F(ArithmeticTest, CalculateReturnsZeroOnSimpleParentheses) {
    auto actual = target.Calculate("( )");
    ASSERT_EQ(0, actual);
}

TEST_F(ArithmeticTest, CalculateReturnsAnswerGivenSimpleAddition) {
     auto actual = target.Calculate("( 1 + 1 )");
     ASSERT_EQ(2, actual);
}

TEST_F(ArithmeticTest, CalculateReturnsAnswerGivenSimplePEMDAS) {
    std::string given = "( 1 + ( ( 2 + 3 ) * ( 4 * 5 ) ) )";
    auto actual = target.Calculate(given);
    ASSERT_EQ(101, actual);
}

TEST_F(ArithmeticTest, CalculateReturnsAnswerGivenComplexPEMDAS) {
    std::string given = "( 5 * ( 4 * ( 3 * ( 2 * ( 1 * 9 ) / 8 - 7 ) + 6 ) ) )";
    auto actual = target.Calculate(given);
    ASSERT_EQ(-165, actual);
}

TEST_F(ArithmeticTest, CalculateReturnsZeroOnComplexParentheses) {
    std::string given = "( ( ( ) ( ) ) )";
    auto actual = target.Calculate(given);
    ASSERT_EQ(0, actual);
}

TEST_F(ArithmeticTest, ThrowsErrorIfNoOutsideParentheses) {
    try {
        target.Calculate("3 + ( 2 * 1 )");
    }
    catch (std::invalid_argument &e) {
        ASSERT_STREQ(e.what(), "Expression must be surrounded by parentheses");
    }
}

#pragma clang diagnostic pop