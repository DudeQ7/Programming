#include "SpeedFormatter.hpp"
#include <cmath>

SpeedFormatter::SpeedFormatter(SpeedSourceInterface* speedSource, UnitsInterface* units, unsigned int updates)
    : m_speedSource(speedSource),
      m_units(units),
      m_updatesPerSecond(updates),
      m_hasCurrent(false),
      m_currentSpeed(0.0),
      m_pendingSpeed(0.0),
      m_isWaiting(false),
      m_lastChangeTime(std::chrono::steady_clock::now()),
      m_stabilityDelay(std::chrono::seconds(1))
{}

unsigned int SpeedFormatter::getFormattedSpeed()
{
    double rawSpeed = m_speedSource->getSpeed();
    double filteredSpeed = filterRawSpeed(rawSpeed);
    double speedInUnits = filteredSpeed * m_units->getMultiplier();
    return static_cast<unsigned int>(std::round(speedInUnits));
}

double SpeedFormatter::filterRawSpeed(double rawSpeed)
{
    if (!m_hasCurrent)
    {
        m_currentSpeed = rawSpeed;
        m_hasCurrent = true;
        m_isWaiting = false;
        return m_currentSpeed;
    }

    const double diff = std::abs(rawSpeed - m_currentSpeed);
    if (diff >= kImmediateThreshold)
    {
        m_currentSpeed = rawSpeed;
        m_isWaiting = false;
        return m_currentSpeed;
    }

    if (diff <= kSampleTolerance)
    {
        m_isWaiting = false;
        return m_currentSpeed;
    }

    auto now = std::chrono::steady_clock::now();
    if (!m_isWaiting || std::abs(rawSpeed - m_pendingSpeed) > kSampleTolerance)
    {
        m_pendingSpeed = rawSpeed;
        m_lastChangeTime = now;
        m_isWaiting = true;
        return m_currentSpeed;
    }

    if (now - m_lastChangeTime >= m_stabilityDelay)
    {
        m_currentSpeed = m_pendingSpeed;
        m_isWaiting = false;
    }
    return m_currentSpeed;
}
