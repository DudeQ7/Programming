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

TEST(SpeedFormatterGMock, ShouldRoundSpeedCorrectly) {
    MockUnitsG units;
    MockSpeedSourceG source;

    EXPECT_CALL(units, getMultiplier()).WillRepeatedly(Return(1.0));
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(10.4));
    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), 10u);

    EXPECT_CALL(source, getSpeed()).WillOnce(Return(10.5));
    EXPECT_EQ(formatter.getFormattedSpeed(), 11u);
}

TEST(SpeedFormatterGMock, ShouldUseCurrentUnit) {
    MockUnitsG units;
    MockSpeedSourceG source;

    EXPECT_CALL(source, getSpeed()).WillRepeatedly(Return(TV_speed_initial));
    EXPECT_CALL(units, getMultiplier()).WillOnce(Return(TV_units_multiplier_kph));
    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), static_cast<unsigned int>(std::round(TV_speed_initial * TV_units_multiplier_kph)));

    EXPECT_CALL(units, getMultiplier()).WillOnce(Return(TV_units_multiplier_mph));
    EXPECT_EQ(formatter.getFormattedSpeed(), static_cast<unsigned int>(std::round(TV_speed_initial * TV_units_multiplier_mph)));
}

TEST(SpeedSourceGMock, HysteresisLikeSequence) {
    MockUnitsG units;
    MockSpeedSourceG source;

    EXPECT_CALL(units, getMultiplier()).WillRepeatedly(Return(1.0));
    // Simulate initial = 50, then small change (51.5) then after delay becomes 51.5
    ::testing::InSequence s;
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(TV_speed_initial));
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(TV_speed_initial)); // immediate after small change
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(TV_speed_small_change)); // after delay

    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), static_cast<unsigned int>(std::round(TV_speed_initial)));

    // small change: immediate check still returns initial
    EXPECT_EQ(formatter.getFormattedSpeed(), static_cast<unsigned int>(std::round(TV_speed_initial)));

    // simulate later read (after delay)
    EXPECT_EQ(formatter.getFormattedSpeed(), static_cast<unsigned int>(std::round(TV_speed_small_change)));}
