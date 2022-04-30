#include "gtest/gtest.h"
#include "Rover.h"
#include "MyRandom.h"

class RoverTest : public ::testing::Test {
protected:
    void SetUp() override;
    auto GenerateRandomCommands(int maxNumberOfCommands, std::string allowedCommands) -> std::string;

    MyRandom random;
    Rover target;
};

void RoverTest::SetUp() {
    target = Rover();
}

auto RoverTest::GenerateRandomCommands(int maxNumberOfCommands, std::string allowedCommands) -> std::string {
    if (maxNumberOfCommands < 1) {
        return "";
    }

    int numberOfCommands = random.GetRandomInt(1, maxNumberOfCommands);

    std::string commandString;
    for (int i = 0; i < numberOfCommands; i++) {
        int indexOfCommandToGet = random.GetRandomInt(0, static_cast<int>(allowedCommands.size()-1));
        commandString += allowedCommands.at(indexOfCommandToGet);
    }

    return commandString;
}

TEST_F(RoverTest, ExecuteGivenEmptyStringReturnsStartingPosition) {
    std::string actual = target.Execute("");
    EXPECT_EQ("0:0:N", actual);
}

TEST_F(RoverTest, ExecuteGivenMMovesNorthFromStarting) {
    std::string actual = target.Execute("M");
    EXPECT_EQ("0:1:N", actual);
}

TEST_F(RoverTest, ExecuteGivenMultipleMsMovesNorthMTimes) {
    const int maxMovesWithoutRollingOver = 9;
    std::string commandString = GenerateRandomCommands(maxMovesWithoutRollingOver, "M");
    std::string expected = "0:" + std::to_string(commandString.size()) + ":N";

    std::string actual = target.Execute(commandString);

    EXPECT_EQ(expected, actual);
}

TEST_F(RoverTest, ExecuteGivenInvalidStringDoesNotMove) {
    const int maxRandomStringSize = 100;
    int randomStringSize = random.GetRandomInt(0, maxRandomStringSize);
    std::string randomCommandString = random.GetRandomString(randomStringSize);

    std::string actual = target.Execute(randomCommandString);

    EXPECT_EQ("0:0:N", actual);
}