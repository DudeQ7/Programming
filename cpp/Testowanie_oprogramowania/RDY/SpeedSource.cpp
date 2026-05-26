#include "SpeedSource.hpp"
#include <cmath>
#include <chrono>
SpeedSource::SpeedSource()
    : m_currentSpeed(0.0),
      m_pendingSpeed(0.0),
      m_isWaiting(false),
      m_hysteresis(0.5),
      m_immediateThreshold(2.0),
      m_stabilityDelaySeconds(1.0),
      m_requiredStableSamples(3),
      m_stableCount(0)
{
    m_lastChangeTime = std::chrono::steady_clock::now();
}
//R3
void SpeedSource::setSpeed(double newSpeed)
{
    double diff = std::abs(newSpeed - m_currentSpeed);

    // If the change is significantly larger than the immediate threshold + hysteresis, apply immediately
    if (diff >= (m_immediateThreshold + m_hysteresis))
    {
        m_currentSpeed = newSpeed;
        m_isWaiting = false;
        m_stableCount = 0;
        return;
    }

    // Otherwise treat as a pending (debounced) change: require it to be stable for stability delay or for N samples
    const double SAMPLE_TOLERANCE = 0.001;
    auto now = std::chrono::steady_clock::now();

    if (!m_isWaiting || std::abs(newSpeed - m_pendingSpeed) > SAMPLE_TOLERANCE)
    {
        // new pending value, reset timer and counter
        m_pendingSpeed = newSpeed;
        m_lastChangeTime = now;
        m_isWaiting = true;
        m_stableCount = 1;
        return;
    }

    // same (or very close) as pending -> increment stable count
    ++m_stableCount;

    // if enough consecutive samples, commit immediately 
    if (m_stableCount >= m_requiredStableSamples)
    {
        if (std::abs(m_pendingSpeed - m_currentSpeed) >= m_hysteresis)
        {
            m_currentSpeed = m_pendingSpeed;
        }
        m_isWaiting = false;
        m_stableCount = 0;
    }
}

double SpeedSource::getSpeed()
{
    if (m_isWaiting)
    {
        auto now = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsed = now - m_lastChangeTime;
        if (elapsed.count() >= m_stabilityDelaySeconds || m_stableCount >= m_requiredStableSamples)
        {
            // Commit pending only if it meaningfully differs from current speed
            if (std::abs(m_pendingSpeed - m_currentSpeed) >= m_hysteresis)
            {
                m_currentSpeed = m_pendingSpeed;
            }
            m_isWaiting = false;
            m_stableCount = 0;
        }
    }
    return m_currentSpeed;
}