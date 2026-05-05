#pragma once
#include "SpeedSourceInterface.hpp"
class MockImmediateSpeedSource : public SpeedSourceInterface {
public:
    MockImmediateSpeedSource(double initial = 0.0) : m_currentSpeed(initial) {}
    void setSpeed(double newSpeed) override { m_currentSpeed = newSpeed; }
    double getSpeed() override { return m_currentSpeed; }
private:
    double m_currentSpeed;
};
