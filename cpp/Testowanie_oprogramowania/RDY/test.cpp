#include <gtest/gtest.h>
#include <cmath>
#include <iostream>
#include <thread>
#include "SpeedFormatter.hpp"
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
