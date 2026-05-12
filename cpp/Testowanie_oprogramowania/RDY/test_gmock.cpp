#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <cmath>
#include "SpeedFormatter.hpp"
#include "TestValues.hpp"
using ::testing::Return;
class MockUnitsG : public UnitsInterface
{
public:
    MOCK_METHOD(SpeedUnit, getSpeedUnit, (), (const, override));
    MOCK_METHOD(double, getMultiplier, (), (const, override));
};

class MockSpeedSourceG : public SpeedSourceInterface
{
public:
    MOCK_METHOD(void, setSpeed, (double), (override));
    MOCK_METHOD(double, getSpeed, (), (override));
};

//R1 - Rounding
TEST(SpeedFormatterGmock, ShouldRoundSpeedCorrectly_R1)
{
    MockUnitsG units;
    MockSpeedSourceG source;
    EXPECT_CALL(units, getMultiplier()).WillRepeatedly(Return(1.0));
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(10.4));
    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), 10u);
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(10.5));
    EXPECT_EQ(formatter.getFormattedSpeed(), 11u);
}

//R2 - Actual Unit
TEST(SpeedFormatterGmock, ShouldUseCurrentUnit_R2)
{
    MockUnitsG units;
    MockSpeedSourceG source;
    EXPECT_CALL(source, getSpeed()).WillRepeatedly(Return(TV_speed_initial));
    EXPECT_CALL(units, getMultiplier()).WillOnce(Return(TV_units_multiplier_kph));
    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), static_cast<unsigned int>(std::round(TV_speed_initial * TV_units_multiplier_kph)));
}

//R3 - Hysteresis-like sequence
TEST(SpeedSourceGmock, HysteresisLikeSequence_R3)
{
    MockUnitsG units;
    MockSpeedSourceG source;
    EXPECT_CALL(units, getMultiplier()).WillRepeatedly(Return(1.0));
    ::testing::InSequence s;
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(TV_speed_initial));
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(TV_speed_initial));
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(TV_speed_small_change));

    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), static_cast<unsigned int>(std::round(TV_speed_initial)));
    EXPECT_EQ(formatter.getFormattedSpeed(), static_cast<unsigned int>(std::round(TV_speed_initial)));
    EXPECT_EQ(formatter.getFormattedSpeed(), static_cast<unsigned int>(std::round(TV_speed_small_change)));
}
