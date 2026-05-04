#include "SpeedFormatter.hpp"
#include <cmath>

SpeedFormatter::SpeedFormatter(SpeedSourceInterface* speedSource, UnitsInterface* units, unsigned int updates)
    : m_speedSource(speedSource), m_units(units), updatesPerSecond(updates) {}

unsigned int SpeedFormatter::getFormattedSpeed() {
    double rawSpeed = m_speedSource->getSpeed();
    
    // R2: Pobieramy mnożnik jednostki (np. 1.0 dla km/h, 0.62 dla mph)
    double speedInUnits = rawSpeed * m_units->getMultiplier();
    
    // R1: Zaokrąglanie matematyczne (0.5 w górę)
    return static_cast<unsigned int>(std::round(speedInUnits));
}