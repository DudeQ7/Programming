#include "SpeedSource.hpp"
#include <cmath>
#include <chrono>

SpeedSource::SpeedSource() : m_currentSpeed(0.0),m_pendingSpeed(0.0),m_isWaiting(false)
{
    m_lastChangeTime =std::chrono::steady_clock::now();
}
//R3
void SpeedSource::setSpeed(double newSpeed)
{
    double diff = std::abs(newSpeed - m_currentSpeed);
    if(diff >=2.0)
    {
        m_currentSpeed = newSpeed;
        m_isWaiting = false;
    }
    else
    {
        if(!m_isWaiting || std::abs(newSpeed - m_pendingSpeed) >0.001)
        {
            m_pendingSpeed = newSpeed; 
            m_lastChangeTime = std::chrono::steady_clock::now();
            m_isWaiting = true;
        }
    }
}
double SpeedSource::getSpeed()
{
    if(m_isWaiting)
    {
        auto now = std::chrono::steady_clock::now();
        auto elapsed = std::chrono::duration_cast<std::chrono::seconds>(now - m_lastChangeTime);
            if(elapsed.count() >= 1)
            {
                m_currentSpeed = m_pendingSpeed;
                m_isWaiting = false;
            }
    }
    return m_currentSpeed;
}