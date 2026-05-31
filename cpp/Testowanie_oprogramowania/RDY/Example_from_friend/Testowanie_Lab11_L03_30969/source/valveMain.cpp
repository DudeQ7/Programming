#include "valveMain.h"
#include <stdexcept>

using namespace std;

void Valve::injectInterface(TemperatureSensorInterface* temperatureSensorInterface) {
    if (temperatureSensorInterface == nullptr) {
        throw invalid_argument(" !!! > Temperature sensor interface injection cannot be null");
    }
    temperatureSensor = temperatureSensorInterface;
}

void Valve::setExpectedTempValue(int value) {
    expectedTempValue = value;
}

void Valve::setCallIntervalMin(int value) {
    callIntervalMin = value;
    callCounter += value;
}

bool Valve::openValve() {
    callCounter += 1;

    if (callCounter >= callIntervalMin) {
        int temperature = temperatureSensor->getTemperature();

        if (temperature < expectedTempValue and !isValveOpen) {
            isValveOpen = true;
            callCounter = 0;
        }
        if (temperature > expectedTempValue and isValveOpen) {
            isValveOpen = false;
            callCounter = 0;
        }
    }

    return isValveOpen;
}
