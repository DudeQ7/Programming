#pragma once 
#include "SpeedSourceInterface.hpp"
#include "chrono"
class SpeedSource : public SpeedSourceInterface 
{
    public:
        SpeedSource();
        void setSpeed(double newSpeed) override;
        double getSpeed() override;
    private:
        double m_currentSpeed;
        double m_pendingSpeed;
        bool   m_isWaiting;
        std::chrono::steady_clock::time_point m_lastChangeTime;
};