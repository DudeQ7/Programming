#pragma once

#include "UnitsInterface.hpp"
#include "TestValues.hpp"

class MockUnits : public UnitsInterface {
public:
    MockUnits(SpeedUnit unit = SpeedUnit::KPH) : m_unit(unit) {}
    SpeedUnit getSpeedUnit() const override { return m_unit; }
    double getMultiplier() const override {
        return (m_unit == SpeedUnit::KPH) ? TV_units_multiplier_kph : TV_units_multiplier_mph;
    }
    void setSpeedUnit(SpeedUnit u) { m_unit = u; }
private:
    SpeedUnit m_unit;
};
