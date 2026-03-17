#pragma once
enum class SpeedUnit
{
    MPH,
    KPH
};
class UnitsInterface
{
public:
    virtual SpeedUnit getSpeedUnit() = 0;
};