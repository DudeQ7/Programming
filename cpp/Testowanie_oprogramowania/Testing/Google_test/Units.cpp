#include "pch.h"
#include "Units.hpp"

Units::Units(SpeedUnit unit)
    : m_unit(unit)
{
}

SpeedUnit Units::getSpeedUnit() const
{
    return m_unit;
}

double Units::getMultiplier() const
{
    return (m_unit == SpeedUnit::KPH) ? 1.0 : 0.62;
}

void Units::setSpeedUnit(SpeedUnit unit)
{
    m_unit = unit;
}
