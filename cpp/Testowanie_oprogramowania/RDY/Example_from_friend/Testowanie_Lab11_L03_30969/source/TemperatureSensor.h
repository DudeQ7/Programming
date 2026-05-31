#pragma once
#include "../source/TemperatureSensorInterface.h"

class TemperatureSensor : public TemperatureSensorInterface {
public:
    int getTemperature() override;
};
