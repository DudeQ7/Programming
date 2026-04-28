#pragma once
enum class SpeedUnit
{
    MPH,
    KPH
};
class UnitsInterface
{
public:
    virtual ~UnitsInterface() = default;
    virtual SpeedUnit getSpeedUnit() = 0;
};