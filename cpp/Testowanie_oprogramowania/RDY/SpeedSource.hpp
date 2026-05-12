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
        // Oscillation filtering parameters
        double m_hysteresis;                 // km/h: ignore changes smaller than this when committing
        double m_immediateThreshold;         // km/h: changes above this (plus hysteresis) may apply immediately
        double m_stabilityDelaySeconds;      // seconds: how long a pending value must be stable before committing
};