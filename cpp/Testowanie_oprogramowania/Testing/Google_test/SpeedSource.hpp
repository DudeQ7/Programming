#pragma once

#include "SpeedSourceInterface.hpp"
#include <chrono>

class SpeedSource : public SpeedSourceInterface
{
public:
    SpeedSource();
    double getSpeed() override;
    void setSpeed(double speed);
    std::chrono::steady_clock::time_point getLastChangeTime() const;

private:
    double m_speed;
    std::chrono::steady_clock::time_point m_lastChangeTime;
};
