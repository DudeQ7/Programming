#include "pch.h"
#include "pch.h"
#include "SpeedFormatter.hpp"
#include "SpeedSource.hpp"
#include <cmath>

SpeedFormatter::SpeedFormatter(SpeedSourceInterface* speedSource, UnitsInterface* units, unsigned int updatesPerSecond)
    : m_speedSource(speedSource), m_units(units), updatesPerSecond(updatesPerSecond)
{
}

unsigned int SpeedFormatter::getFormattedSpeed()
{
    if (!m_speedSource || !m_units)
        return 0;

    double currentSpeed = m_speedSource->getSpeed();
    unsigned int roundedSpeed = static_cast<unsigned int>(std::round(currentSpeed));
    auto now = std::chrono::steady_clock::now();

    auto* concreteSpeedSource = dynamic_cast<SpeedSource*>(m_speedSource);
    auto sourceChangeTime = concreteSpeedSource ? concreteSpeedSource->getLastChangeTime() : now;

    // R1: Round using common math rounding rules (>= 5 up, < 5 down)
    // Already handled by std::round above

    // R2: Current unit of measurement shall be used
    // The unit is obtained from m_units, the actual speed value is already in that unit

    // R3: For small speed change (< 2), delay update by 1 second
    //     For large speed change (>= 2), update immediately

    if (!m_initialized)
    {
        // First call: initialize with current speed
        m_lastFormattedSpeed = roundedSpeed;
        m_pendingFormattedSpeed = roundedSpeed;
        m_pendingSince = sourceChangeTime;
        m_initialized = true;
        return m_lastFormattedSpeed;
    }

    double speedDifference = std::abs(currentSpeed - static_cast<double>(m_lastFormattedSpeed));

    // If difference >= 2, update immediately
    if (speedDifference >= 2)
    {
        m_lastFormattedSpeed = roundedSpeed;
        m_pendingFormattedSpeed = roundedSpeed;
        m_pendingSince = sourceChangeTime;
        m_hasPendingUpdate = false;
        return m_lastFormattedSpeed;
    }

    // If difference < 2, start/reset the pending update timer when the source changes.
    if (!m_hasPendingUpdate || m_pendingFormattedSpeed != roundedSpeed || m_pendingSince != sourceChangeTime)
    {
        m_pendingFormattedSpeed = roundedSpeed;
        m_pendingSince = sourceChangeTime;
        m_hasPendingUpdate = true;
        return m_lastFormattedSpeed;
    }

    auto elapsedTime = std::chrono::duration_cast<std::chrono::seconds>(now - sourceChangeTime);
    if (elapsedTime.count() >= 1)
    {
        m_lastFormattedSpeed = m_pendingFormattedSpeed;
        m_hasPendingUpdate = false;
    }

    return m_lastFormattedSpeed;
}

