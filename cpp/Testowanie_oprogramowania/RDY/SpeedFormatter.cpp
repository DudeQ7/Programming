#include "SpeedFormatter.hpp"
#include <cmath>
SpeedFormatter::SpeedFormatter(SpeedSourceInterface* speedSource, UnitsInterface* units, unsigned int updates) : m_speedSource(speedSource), m_units(units), m_updatesPerSecond(updates) {}
unsigned int SpeedFormatter::getFormattedSpeed()
{
    //R2: get current speed from source
    double rawSpeed = m_speedSource->getSpeed();
    //R2: convert to desired units
    double speedInUnits = rawSpeed * m_units->getMultiplier();
    //R2: round to nearest integer
    return static_cast<unsigned int>(std::round(speedInUnits));
}
