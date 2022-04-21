#include "gtest/gtest.h"
#include "Rover.h"

class RoverTest : public ::testing::Test {
protected:
    Rover target;
};

TEST_F(RoverTest, ExecuteGivenEmptyStringReturnsStartingPosition) {
    std::string actual = target.Execute("");
    EXPECT_EQ("0:0:N", actual);
}

TEST_F(RoverTest, ExecuteGivenMMovesNorthFromStarting) {
    std::string actual = target.Execute("M");
    EXPECT_EQ("0:1:N", actual);
}