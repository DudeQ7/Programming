#include <gtest/gtest.h>
#include "SpeedSource.hpp"
TEST(SpeedSourceOscillation, AlternatingDoesNotCommit)
{
    SpeedSource source;
    source.setSpeed(100.0);
    // Alternate between 100 and 101 several times quickly
    for (int i = 0; i < 5; ++i) {
        source.setSpeed(101.0);
        source.setSpeed(100.0);
    }
    EXPECT_DOUBLE_EQ(source.getSpeed(), 100.0);
}
TEST(SpeedSourceOscillation, StableSamplesCommit)
{
    SpeedSource source;
    source.setSpeed(100.0);
    source.setSpeed(101.0);
    source.setSpeed(101.0);
    source.setSpeed(101.0);
    EXPECT_DOUBLE_EQ(source.getSpeed(), 101.0);
}
