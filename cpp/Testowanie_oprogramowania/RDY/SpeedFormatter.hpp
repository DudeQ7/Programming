#pragma once
#include "SpeedSourceInterface.hpp"
#include "UnitsInterface.hpp"
class SpeedFormatter
{
public:
    SpeedFormatter(SpeedSourceInterface* speedSource, UnitsInterface* units, unsigned int updatesPerSecond);
    unsigned int getFormattedSpeed();
private:
    SpeedSourceInterface* m_speedSource;
    UnitsInterface* m_units;
    unsigned int m_updatesPerSecond;
};
