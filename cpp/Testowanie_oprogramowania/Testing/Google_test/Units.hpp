#pragma once

#include "UnitsInterface.hpp"

class Units : public UnitsInterface
{
public:
    Units(SpeedUnit unit = SpeedUnit::KPH);
    SpeedUnit getSpeedUnit() override;
    void setSpeedUnit(SpeedUnit unit);

private:
    SpeedUnit m_unit;
};
