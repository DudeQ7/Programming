#pragma once
#include "SpeedSourceInterface.hpp"
#include "TestValues.hpp"
#include <chrono>
#include <cmath>

class MockSpeedSource : public SpeedSourceInterface
{
public:
    MockSpeedSource() : m_currentSpeed(TV_speed_initial), m_pendingSpeed(TV_speed_initial), m_isWaiting(false) {}

    void setSpeed(double newSpeed) override
    {
        m_pendingSpeed = newSpeed;
        if (std::abs(newSpeed - m_currentSpeed) >= 2.0)
        {
            m_currentSpeed = newSpeed;
            m_isWaiting = false;
        }
        else
        {
            m_isWaiting = true;
            m_lastChangeTime = std::chrono::steady_clock::now();
        }
    }

    double getSpeed() override
    {
        if (m_isWaiting)
        {
            auto now = std::chrono::steady_clock::now();
            if (std::chrono::duration_cast<std::chrono::seconds>(now - m_lastChangeTime).count() >= 1)
            {
                m_currentSpeed = m_pendingSpeed;
                m_isWaiting = false;
            }
        }
        return m_currentSpeed;
    }

private:
    double m_currentSpeed;
    double m_pendingSpeed;
    bool m_isWaiting;
    std::chrono::steady_clock::time_point m_lastChangeTime;
};
