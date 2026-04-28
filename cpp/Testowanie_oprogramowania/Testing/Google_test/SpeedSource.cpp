#include "pch.h"
#include "SpeedSource.hpp"

SpeedSource::SpeedSource()
    : m_speed(0.0), m_lastChangeTime(std::chrono::steady_clock::now())
{
}

double SpeedSource::getSpeed()
{
    return m_speed;
}

void SpeedSource::setSpeed(double speed)
{
    m_speed = speed;
    m_lastChangeTime = std::chrono::steady_clock::now();
}

std::chrono::steady_clock::time_point SpeedSource::getLastChangeTime() const
{
    return m_lastChangeTime;
}
