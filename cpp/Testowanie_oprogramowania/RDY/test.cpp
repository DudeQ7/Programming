#include <gtest/gtest.h>
#include <cmath>
#include <iostream>
#include <thread>
#include "SpeedFormatter.hpp"
#include "SpeedSource.hpp"
#include "MockUnits.hpp"
#include "MockSpeedSource.hpp"
#include "MockImmediateSpeedSource.hpp"
#include "TestValues.hpp"
//R1 test
TEST(SpeedFormatterTest,ShouldRoundSpeedCorrectly_R1)
{
    MockUnits units(SpeedUnit::KPH);
    MockImmediateSpeedSource source;
    source.setSpeed(10.4);
    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), 10u);
    source.setSpeed(10.5);
    EXPECT_EQ(formatter.getFormattedSpeed(), 11u);
}
//R2 test
TEST(SpeedFormatterTest,ShouldUseCurrentUnit_R2)
{
    MockUnits units(SpeedUnit::KPH);
    MockSpeedSource source;
    source.setSpeed(TV_speed_initial);
    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), 54u);
    units.setSpeedUnit(SpeedUnit::MPH);
    EXPECT_EQ(formatter.getFormattedSpeed(), 34u);
}
//R3 small change wait 1 second
TEST(SpeedSourceTest,ShouldHandleSmallChangesWithDelay_R3)
{
    MockUnits units(SpeedUnit::KPH);
    MockSpeedSource source;
    source.setSpeed(TV_speed_initial);
    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), 54u);
    source.setSpeed(TV_speed_small_change);
    EXPECT_EQ(formatter.getFormattedSpeed(), 52u);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    EXPECT_EQ(formatter.getFormattedSpeed(), 52u);
}
//R3 big change immediate
TEST(SpeedSourceTest,ShouldUpdateImmedaitelyForBingChanges_R3)
{
    MockUnits units(SpeedUnit::KPH);
    MockSpeedSource source;
    source.setSpeed(TV_speed_initial);
    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), 54u);
    source.setSpeed(TV_speed_big_change);
    EXPECT_EQ(formatter.getFormattedSpeed(), 54u);
}

// Additional tests to cover MockUnits and MockSpeedSource
TEST(MockUnitsTest, GetSpeedUnitAndMultiplier)
{
    MockUnits units(SpeedUnit::MPH);
    EXPECT_EQ(units.getSpeedUnit(), SpeedUnit::MPH);
    EXPECT_DOUBLE_EQ(units.getMultiplier(), TV_units_multiplier_mph);
    units.setSpeedUnit(SpeedUnit::KPH);
    EXPECT_EQ(units.getSpeedUnit(), SpeedUnit::KPH);
}

TEST(MockSpeedSourceTest, PendingCommitAfterDelay)
{
    MockSpeedSource source;
    EXPECT_EQ(source.getSpeed(), TV_speed_initial);
    source.setSpeed(TV_speed_big_change); // choose a value within hysteresis threshold
    EXPECT_EQ(source.getSpeed(), TV_speed_initial);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    EXPECT_EQ(source.getSpeed(), TV_speed_big_change);
}

// Real SpeedSource tests
TEST(SpeedSourceReal, ImmediateChangeApplied)
{
    SpeedSource source;
    source.setSpeed(TV_speed_initial);
    EXPECT_EQ(source.getSpeed(), TV_speed_initial);
    source.setSpeed(51.4); // diff 2.6 -> immediate (>= 2.5)
    EXPECT_EQ(source.getSpeed(), 51.4);
}

TEST(SpeedSourceReal, DelayedCommit)
{
    SpeedSource source;
    source.setSpeed(TV_speed_initial);
    source.setSpeed(53.0); // diff 1.0 -> pending
    EXPECT_EQ(source.getSpeed(), TV_speed_initial);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    EXPECT_EQ(source.getSpeed(), 53.0);
}
