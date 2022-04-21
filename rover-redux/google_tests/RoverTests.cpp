#include "gtest/gtest.h"
#include "Rover.h"

class RoverTest : public ::testing::Test
{
protected:
    void SetUp() override;

    Rover target;
};

void RoverTest::SetUp()
{

}

TEST_F(RoverTest, ExecuteGivenEmptyStringReturnsStartingPosition) // NOLINT(cert-err58-cpp)
{
    std::string expected = "0:0:N";
    std::string actual = target.Execute("");
    EXPECT_EQ(expected, actual);
}