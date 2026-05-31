#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include <./TemperatureSensorInterface.h>
#include <../source/valveMain.h>

class MockGetTemperature : public TemperatureSensorInterface {
public:
    MOCK_METHOD(int, getTemperature, (), (override));
};

class TemperatureSensorTest : public ::testing::Test {
protected:
    MockGetTemperature* mockSensor{};
    Valve* valve{};

    void SetUp() override {
        mockSensor = new MockGetTemperature();
        valve = new Valve();
        valve->injectInterface(mockSensor);
        valve->setExpectedTempValue(21);
    }

    void TearDown() override {
        delete valve;
        delete mockSensor;
    }
};

using testing::Return;
using testing::InSequence;

TEST_F(TemperatureSensorTest, InterfaceInjection) {
    EXPECT_CALL(*mockSensor, getTemperature()).WillOnce(Return(15));
    EXPECT_NO_THROW(valve->openValve());
}

TEST(ValveInjectionTest, NullInjectException) {
    Valve valve;
    EXPECT_THROW({
        valve.injectInterface(nullptr);
    }, std::invalid_argument);
}


TEST_F(TemperatureSensorTest, Part_1) {
    struct TestCase {
        int temperature;
        bool expectedValveState;
    };

    TestCase testCases[] = {
        {17, true},
        {19, true},
        {20, true},
        {21, true},
        {21, true},
        {22, false},
        {21, false},
        {21, false},
        {20, false},
        {19, false},
        {18, true},
        {19, true},
        {20, true},
        {21, true},
        {22, true},
        {23, false},
        {22, false},
        {22, false},
        {21, false},
        {20, false},
        {20, true},
        {21, true}
    };

    {
        InSequence s;
        for (const auto& t : testCases) {
            EXPECT_CALL(*mockSensor, getTemperature()).Times(testing::AnyNumber());
            ON_CALL(*mockSensor, getTemperature()).WillByDefault(Return(t.temperature));
            bool result = valve->openValve();
            EXPECT_EQ(result, t.expectedValveState)
                << "Temperature: " << t.temperature;
        }
    }
}

TEST_F(TemperatureSensorTest, Part_2) {
    struct TestCase {
        int temperature;
        bool expectedValveState;
    };

    TestCase testCases[] = {
        {21, false},
        {20, true},
        {20, true},
        {21, true},
        {22, true},
        {22, true},
        {23, false},
        {22, false},
        {21, false},
        {20, false},
        {19, false},
        {18, true},
        {19, true},
        {20, true},
        {21, true},
        {21, true},
        {22, false},
        {21, false},
        {21, false},
        {20, false},
        {19, false},
        {17, true}
    };

    {
        InSequence s;
        for (const auto& t : testCases) {
            EXPECT_CALL(*mockSensor, getTemperature()).Times(testing::AnyNumber());
            ON_CALL(*mockSensor, getTemperature()).WillByDefault(Return(t.temperature));
            bool result = valve->openValve();
            EXPECT_EQ(result, t.expectedValveState)
                << "Temperature: " << t.temperature;
        }
    }
}
