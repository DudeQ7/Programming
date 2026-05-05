#include <gtest/gtest.h>
#include <cmath>
#include <iostream>
#include <thread>
#include "SpeedFormatter.hpp"
#include "MockUnits.hpp"
#include "MockSpeedSource.hpp"
#include "MockImmediateSpeedSource.hpp"
#include "TestValues.hpp"
// R1 - Test zaokrąglania
TEST(SpeedFormatterTest, ShouldRoundSpeedCorrectly_R1) {
    std::cout << "TEST INFO: ShouldRoundSpeedCorrectly; values declared in Linux_v2/TestValues.cpp\n";

    MockUnits units(SpeedUnit::KPH);
    MockImmediateSpeedSource source; // immediate updates for rounding test
    ASSERT_NE(&units, nullptr);
    ASSERT_NE(&source, nullptr);

    // NOTE: To break R1 (rounding): change the source.setSpeed values below (10.4/10.5) to numbers that round differently
    // Example: use 11.4 -> 11 and 11.5 -> 12 to make the rounding expectations fail
    // Test 10.4 -> 10
    source.setSpeed(10.4);
    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), 10u);

    // Test 10.5 -> 11
    source.setSpeed(10.5);
    EXPECT_EQ(formatter.getFormattedSpeed(), 11u);
}

// R2 - Test użycia aktualnej jednostki
TEST(SpeedFormatterTest, ShouldUseCurrentUnit_R2) {
    std::cout << "TEST INFO: ShouldUseCurrentUnit; values declared in Linux_v2/TestValues.cpp\n";
    MockUnits units(SpeedUnit::KPH);
    MockSpeedSource source;
    ASSERT_NE(&units, nullptr);
    ASSERT_NE(&source, nullptr);
    source.setSpeed(TV_speed_initial);
    SpeedFormatter formatter(&source, &units, 1);
    // NOTE: To break R2 (unit conversion): change TV_units_multiplier_kph or TV_units_multiplier_mph in TestValues.cpp
    // or change the mocked getMultiplier() in gTest/test_gmock.cpp
    unsigned int expectedKph = 50u; 
    EXPECT_EQ(formatter.getFormattedSpeed(), expectedKph);
    units.setSpeedUnit(SpeedUnit::MPH);
    unsigned int expectedMph = 31u; 
    EXPECT_EQ(formatter.getFormattedSpeed(), expectedMph);
}
// R3 - Test histerezy i czasu (Small change vs Big change)
TEST(SpeedSourceTest, ShouldHandleSmallChangesWithDelay_R3) {
    std::cout << "TEST INFO: ShouldHandleSmallChangesWithDelay; values declared in Linux_v2/TestValues.cpp\n";
    MockUnits units(SpeedUnit::KPH);
    MockSpeedSource source;
    ASSERT_NE(&units, nullptr);
    ASSERT_NE(&source, nullptr);
    // NOTE: To break R3 (hysteresis): edit TV_speed_initial / TV_speed_small_change / TV_speed_big_change in TestValues.cpp
    // or change the mocked sequence in gTest/test_gmock.cpp to return unexpected speeds
    source.setSpeed(TV_speed_initial);
    SpeedFormatter formatter(&source, &units, 1);
    //debug
    std::cout << "DBG: TV_speed_initial=" << TV_speed_initial << ", source.getSpeed()=" << source.getSpeed() << "\n";
    EXPECT_EQ(formatter.getFormattedSpeed(), 50u);
    source.setSpeed(TV_speed_small_change);
    std::cout << "DBG after small change: TV_speed_small_change=" << TV_speed_small_change << ", source.getSpeed()=" << source.getSpeed() << ", formatter=" << formatter.getFormattedSpeed() << "\n";
    EXPECT_EQ(formatter.getFormattedSpeed(), 50u);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "DBG after wait: source.getSpeed()=" << source.getSpeed() << ", formatter=" << formatter.getFormattedSpeed() << "\n";
    EXPECT_EQ(formatter.getFormattedSpeed(), 52u); 
}
TEST(SpeedSourceTest, ShouldUpdateImmediatelyForBigChanges_R3) {
    std::cout << "TEST INFO: ShouldUpdateImmediatelyForBigChanges; values declared in Linux_v2/TestValues.cpp\n";
    MockUnits units(SpeedUnit::KPH);
    MockSpeedSource source;
    ASSERT_NE(&units, nullptr);
    ASSERT_NE(&source, nullptr);
    source.setSpeed(TV_speed_initial); // 50
    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), 50u);
    source.setSpeed(TV_speed_big_change);
    EXPECT_EQ(formatter.getFormattedSpeed(), 53u); 
}
