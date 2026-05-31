#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <chrono>
#include <thread>
#include "SpeedFormatter.hpp"
#include "SpeedSource.hpp"
using ::testing::Return;
class MockUnits : public UnitsInterface
{
public:
    MOCK_METHOD(SpeedUnit, getSpeedUnit, (), (const, override));
    MOCK_METHOD(double, getMultiplier, (), (const, override));
};
class MockSpeedSource : public SpeedSourceInterface
{
public:
    MOCK_METHOD(void, setSpeed, (double), (override));
    MOCK_METHOD(double, getSpeed, (), (override));
};
TEST(SpeedFormatterGmock, R1_RoundsDownBelowHalf)
{
    MockUnits units;
    MockSpeedSource source;
    EXPECT_CALL(units, getMultiplier()).WillRepeatedly(Return(1.0));
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(10.4));
    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), 10u);
}
TEST(SpeedFormatterGmock, R1_RoundsUpAtHalf)
{
    MockUnits units;
    MockSpeedSource source;
    EXPECT_CALL(units, getMultiplier()).WillRepeatedly(Return(1.0));
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(10.5));
    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), 11u);
}
TEST(SpeedFormatterGmock, R2_UsesCurrentUnitMultiplier)
{
    MockUnits units;
    MockSpeedSource source;
    EXPECT_CALL(source, getSpeed()).WillRepeatedly(Return(54.0));
    EXPECT_CALL(units, getMultiplier())
        .WillOnce(Return(1.0))
        .WillOnce(Return(0.621371));
    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), 54u);
    EXPECT_EQ(formatter.getFormattedSpeed(), 34u);
}

TEST(SpeedFormatterGmock, ConvertsBeforeRounding)
{
    MockUnits units;
    MockSpeedSource source;
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(10.49));
    EXPECT_CALL(units, getMultiplier()).WillOnce(Return(1.5));
    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), 16u);
}

TEST(SpeedFormatterGmock, R3_AlternatingSmallChangesDoNotOscillate)
{
    MockUnits units;
    MockSpeedSource source;
    EXPECT_CALL(units, getMultiplier()).WillRepeatedly(Return(1.0));
    ::testing::InSequence s;
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(100.0));
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(101.0));
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(100.0));
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(101.0));
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(100.0));
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(101.0));
    SpeedFormatter formatter(&source, &units, 3);
    EXPECT_EQ(formatter.getFormattedSpeed(), 100u);
    EXPECT_EQ(formatter.getFormattedSpeed(), 100u);
    EXPECT_EQ(formatter.getFormattedSpeed(), 100u);
    EXPECT_EQ(formatter.getFormattedSpeed(), 100u);
    EXPECT_EQ(formatter.getFormattedSpeed(), 100u);
    EXPECT_EQ(formatter.getFormattedSpeed(), 100u);
}

TEST(SpeedFormatterGmock, R3_SmallChangeDelaysThenCommits)
{
    MockUnits units;
    MockSpeedSource source;
    EXPECT_CALL(units, getMultiplier()).WillRepeatedly(Return(1.0));
    ::testing::InSequence s;
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(100.0));
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(101.0));
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(101.0));
    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), 100u);
    EXPECT_EQ(formatter.getFormattedSpeed(), 100u);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    EXPECT_EQ(formatter.getFormattedSpeed(), 101u);
}

TEST(SpeedFormatterGmock, R3_LargeJumpCommitsImmediately)
{
    MockUnits units;
    MockSpeedSource source;
    EXPECT_CALL(units, getMultiplier()).WillRepeatedly(Return(1.0));
    ::testing::InSequence s;
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(100.0));
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(102.0));
    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), 100u);
    EXPECT_EQ(formatter.getFormattedSpeed(), 102u);
}

TEST(SpeedSource, RawValuePassThrough)
{
    SpeedSource source;
    source.setSpeed(123.4);
    EXPECT_DOUBLE_EQ(source.getSpeed(), 123.4);
}
