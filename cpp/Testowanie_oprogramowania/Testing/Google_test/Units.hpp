#pragma once

#include "UnitsInterface.hpp"

class Units : public UnitsInterface
{
public:
    Units(SpeedUnit unit = SpeedUnit::KPH);
    SpeedUnit getSpeedUnit() const override;
    double getMultiplier() const override;
    void setSpeedUnit(SpeedUnit unit);

private:
    SpeedUnit m_unit;
};
