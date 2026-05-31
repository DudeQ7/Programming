#pragma once
#include "SpeedSourceInterface.hpp"
#include "UnitsInterface.hpp"
#include <chrono>
class SpeedFormatter
{
public:
    SpeedFormatter(SpeedSourceInterface* speedSource, UnitsInterface* units, unsigned int updatesPerSecond);
    unsigned int getFormattedSpeed();
private:
    double filterRawSpeed(double rawSpeed);

    SpeedSourceInterface* m_speedSource;
    UnitsInterface* m_units;
    unsigned int m_updatesPerSecond;

    bool m_hasCurrent;
    double m_currentSpeed;
    double m_pendingSpeed;
    bool m_isWaiting;
    std::chrono::steady_clock::time_point m_lastChangeTime;
    std::chrono::seconds m_stabilityDelay;

    static constexpr double kImmediateThreshold = 2.0;
    static constexpr double kSampleTolerance = 0.001;
};
