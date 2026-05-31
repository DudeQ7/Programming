#pragma once
#include <stdexcept>
#include "TemperatureSensorInterface.h"

class Valve {
public:
    void injectInterface(TemperatureSensorInterface* temperatureSensorInterface);

    void setExpectedTempValue(int value);

    void setCallIntervalMin(int value = 5);

    bool openValve();

private:
    TemperatureSensorInterface* temperatureSensor{};
    int expectedTempValue = 0;
    int callCounter = 5;
    int callIntervalMin = 5;
    bool isValveOpen = false;
};