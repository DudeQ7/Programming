#include "SpeedSource.hpp"
SpeedSource::SpeedSource()
    : m_speed(0.0)
{}

void SpeedSource::setSpeed(double newSpeed)
{
    m_speed = newSpeed;
}

double SpeedSource::getSpeed()
{
    return m_speed;
}
