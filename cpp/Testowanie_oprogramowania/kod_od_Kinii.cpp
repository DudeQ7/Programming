#include "pch.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "SpeedFormatter.hpp"
#include "SpeedSourceInterface.hpp"
#include "UnitsInterface.hpp"
using namespace testing;


class MockSpeedSource : public SpeedSourceInterface {
public:
    MOCK_METHOD(double, getSpeed, (), (override));


};
class MockUnits :public UnitsInterface {
public:
    MOCK_METHOD(SpeedUnit, getSpeedUnit, (), (override));
};
TEST(TestCaseName, TestName) {
	EXPECT_EQ(1, 1);
	EXPECT_TRUE(true);

};

/*TEST(SpeedFormatterTest, FirstTest) {
    MockSpeedSource source;
    MockUnits units;
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(100.0));
    EXPECT_CALL(units, getSpeedUnit()).WillOnce(Return(SpeedUnit::MPH));

    SpeedFormatter formatter(&source, &units, 1);

    unsigned int wynik = formatter.getFormattedSpeed();

    EXPECT_EQ(wynik, 62);
}

TEST(SpeedFormatterTest, ZeroSpeed) {
    MockSpeedSource source;
    MockUnits units;
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(0.0));
    EXPECT_CALL(units, getSpeedUnit()).WillOnce(Return(SpeedUnit::KPH));
    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), 0);
}
TEST(SpeedFormatterTest, SmallValue) {
    MockSpeedSource source;
    MockUnits units;
    EXPECT_CALL(source, getSpeed()).WillOnce(Return(0.4));
    EXPECT_CALL(units, getSpeedUnit()).WillOnce(Return(SpeedUnit::KPH));
    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), 0);
}
TEST(SpeedFormatterTest, HalfOne)
{
    MockSpeedSource source;
    MockUnits units;

    EXPECT_CALL(source, getSpeed()).WillOnce(Return(0.5));
    EXPECT_CALL(units, getSpeedUnit()).WillOnce(Return(SpeedUnit::KPH));

    SpeedFormatter formatter(&source, &units, 1);

    EXPECT_EQ(formatter.getFormattedSpeed(), 1);
}
TEST(SpeedFormatterTest, LargeValue)
{
    MockSpeedSource source;
    MockUnits units;

    EXPECT_CALL(source, getSpeed()).WillOnce(Return(250.7));
    EXPECT_CALL(units, getSpeedUnit()).WillOnce(Return(SpeedUnit::KPH));

    SpeedFormatter formatter(&source, &units, 1);

    EXPECT_EQ(formatter.getFormattedSpeed(), 251);
}
TEST(SpeedFormatterTest, MPHWithRounding)
{
    MockSpeedSource source;
    MockUnits units;

    EXPECT_CALL(source, getSpeed()).WillOnce(Return(50.0));
    EXPECT_CALL(units, getSpeedUnit()).WillOnce(Return(SpeedUnit::MPH));

    SpeedFormatter formatter(&source, &units, 1);

    // 50 km/h to tak ok 31.07 czyli powinno dac 31
    EXPECT_EQ(formatter.getFormattedSpeed(), 31);
}
TEST(SpeedFormatterTest, MPHBoundary)
{
    MockSpeedSource source;
    MockUnits units;

    EXPECT_CALL(source, getSpeed()).WillOnce(Return(80.5));
    EXPECT_CALL(units, getSpeedUnit()).WillOnce(Return(SpeedUnit::MPH));

    SpeedFormatter formatter(&source, &units, 1);

    EXPECT_EQ(formatter.getFormattedSpeed(), 50);
}
TEST(SpeedFormatterTest, Testy) {
    MockSpeedSource source;
    MockUnits units;

    EXPECT_CALL(source, getSpeed()).WillOnce(Return(1));
    EXPECT_CALL(units, getSpeedUnit()).WillOnce(Return(SpeedUnit::MPH));

    SpeedFormatter formatter(&source, &units,1);
    EXPECT_EQ(formatter.getFormattedSpeed(), 1);
}
TEST(SpeedFormatterTest, OneUnit) {
    MockSpeedSource source;
    MockUnits units;

    EXPECT_CALL(source, getSpeed()).WillOnce(Return(162));
    EXPECT_CALL(units, getSpeedUnit()).WillOnce(Return(SpeedUnit::MPH));

    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), 101);
}
TEST(SpeedFormatterTest, TwoUnit) {
    MockSpeedSource source;
    MockUnits units;

    EXPECT_CALL(source, getSpeed()).WillOnce(Return(161));
    EXPECT_CALL(units, getSpeedUnit()).WillOnce(Return(SpeedUnit::MPH));

    SpeedFormatter formatter(&source, &units, 1);
    EXPECT_EQ(formatter.getFormattedSpeed(), 100);
}*/
TEST(SpeedFormatter, ArrayUnit) {
    double input[] = {         0.0,           10.2,           10.5,         10.6,            100.0,           162 ,            161};//zwracane wartoœci
    SpeedUnit array[] = { SpeedUnit::KPH, SpeedUnit::MPH, SpeedUnit::MPH, SpeedUnit::MPH, SpeedUnit::MPH , SpeedUnit::MPH, SpeedUnit::MPH};
    int expect[] = {           0,            6,               7,              7,              62,             101,             100 };//oczekiwane wartoœci
    for (int i = 0; i < 7; i++) {
        MockSpeedSource source;
        MockUnits units;
        EXPECT_CALL(source, getSpeed()).WillOnce(Return(input[i]));
        EXPECT_CALL(units, getSpeedUnit()).WillOnce(Return(array[i]));

        SpeedFormatter formatter(&source, &units, 1);

        unsigned int result = formatter.getFormattedSpeed();

        EXPECT_EQ(result, expect[i]);
    

    }
}