#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cmath>

#include "SpeedFormatter.hpp"
#include "TestValues.hpp"

using ::testing::Return;

class MockUnitsG : public UnitsInterface {
public:
    MOCK_METHOD(SpeedUnit, getSpeedUnit, (), (const, override));
    MOCK_METHOD(double, getMultiplier, (), (const, override));
};

class MockSpeedSourceG : public SpeedSourceInterface {
public:
    MOCK_METHOD(void, setSpeed, (double), (override));
    MOCK_METHOD(double, getSpeed, (), (override));
};

TEST(SpeedFormatterGMock, ShouldRoundSpeedCorrectly_R1) {
    MockUnitsG units;
    MockSpeedSourceG source;

    EXPECT_CALL(units, getMultiplier()).WillRepeatedly(Return(1.0));
    // NOTE: To break R1 (rounding): change the two mocked getSpeed() returns below (10.4 / 10.5) to values that round differently
    // Example: Return(11.4) and Return(11.5) will make the rounding expectations fail.
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(11.4)); //prev 10.4 
    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), 10u);

    // (See note above) Change this to break R1 rounding behavior
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(11.5)); //prev 10.5
    EXPECT_EQ(formatter.getFormattedSpeed(), 11u);
}

TEST(SpeedFormatterGMock, ShouldUseCurrentUnit_R2) {
    MockUnitsG units;
    MockSpeedSourceG source;

    EXPECT_CALL(source, getSpeed()).WillRepeatedly(Return(TV_speed_initial));
    // NOTE: To break R2 (unit conversion): change the multiplier returned here or edit TV_units_multiplier_kph in TestValues.cpp
    // Example: return 0.5 here or set TV_units_multiplier_mph to 0.5 to make the MPH expectation fail
    EXPECT_CALL(units, getMultiplier()).WillOnce(Return(TV_units_multiplier_kph));
    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), static_cast<unsigned int>(std::round(TV_speed_initial * TV_units_multiplier_kph)));

    // (See note above) Changing TV_units_multiplier_mph in TestValues.cpp or mocking a different multiplier here will break R2
    EXPECT_CALL(units, getMultiplier()).WillOnce(Return(TV_units_multiplier_mph));
    EXPECT_EQ(formatter.getFormattedSpeed(), static_cast<unsigned int>(std::round(TV_speed_initial * TV_units_multiplier_mph)));
}

TEST(SpeedSourceGMock, HysteresisLikeSequence_R3) {
    MockUnitsG units;
    MockSpeedSourceG source;

    EXPECT_CALL(units, getMultiplier()).WillRepeatedly(Return(1.0));
    // Simulate initial = 50, then small change (51.5) then after delay becomes 51.5
    ::testing::InSequence s;
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(TV_speed_initial));
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(TV_speed_initial)); // immediate after small change
    // NOTE: To break R3 (hysteresis/time): change TV_speed_small_change in TestValues.cpp or mock a different value here
    // Example: RETURN(TV_speed_small_change + 10.0) will cause the hysteresis expectation to fail
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(TV_speed_small_change)); // after delay

    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), static_cast<unsigned int>(std::round(TV_speed_initial)));

    // small change: immediate check still returns initial
    EXPECT_EQ(formatter.getFormattedSpeed(), static_cast<unsigned int>(std::round(TV_speed_initial)));

    // simulate later read (after delay)
    EXPECT_EQ(formatter.getFormattedSpeed(), static_cast<unsigned int>(std::round(TV_speed_small_change)));}
