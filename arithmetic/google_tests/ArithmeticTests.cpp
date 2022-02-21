#include "gtest/gtest.h"
#include "Arithmetic.h"

// class ArithmeticTest : public ::testing:Test {
// protected:
//     void SetUp() override;

//     Arithmetic target;
// };

// void ArithmeticTest::SetUp() {
//     // nothing for now.
// }

// TEST_F(ArithmeticTest, Do_ReturnsZero) {
//     auto actual = target.Do("");

//     ASSERT_EQ(0, actual);
// }

TEST(ArithmeticTest, Do_ReturnsZero) { // NOLINT
    Arithmetic target;
    auto actual = target.Do("");
    ASSERT_EQ(0, actual);
}