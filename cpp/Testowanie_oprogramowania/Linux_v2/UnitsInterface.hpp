#pragma once

enum class SpeedUnit
{
    MPH,
    KPH
};

class UnitsInterface
{
public:
    virtual SpeedUnit getSpeedUnit() const = 0;
    virtual double getMultiplier() const = 0;
};