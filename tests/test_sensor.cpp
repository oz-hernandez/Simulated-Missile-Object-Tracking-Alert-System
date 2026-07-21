#include <gtest/gtest.h>
#include <string>
#include "sensor.h"

class SensorTest : public ::testing::Test {


};

TEST_F(SensorTest, FileDoesNotExist) {
    std::string filename = "doesnotexist.txt";
    EXPECT_THROW(Sensor{filename}, std::runtime_error);
}
