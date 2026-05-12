#include <gtest/gtest.h>
#include "SpeedSourceInterface.hpp"

class DummySpeedSource : public SpeedSourceInterface {
public:
    DummySpeedSource(): speed_(0.0) {}
    void setSpeed(double newSpeed) override { speed_ = newSpeed; }
    double getSpeed() override { return speed_; }
private:
    double speed_;
};

TEST(SpeedSourceInterfaceTest, BasicSetGetAndDestructor)
{
    SpeedSourceInterface* src = new DummySpeedSource();
    src->setSpeed(100.0);
    EXPECT_DOUBLE_EQ(src->getSpeed(), 100.0);
    delete src; // exercise destructor defined in the header
}
