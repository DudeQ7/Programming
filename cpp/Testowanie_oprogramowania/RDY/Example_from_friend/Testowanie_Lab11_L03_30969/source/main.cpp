#include <iostream>

#include "TemperatureSensorInterface.h"
#include "TemperatureSensor.h"
#include "valveMain.h"

using namespace std;


int main() {
    bool valveStatus = false;
    Valve valve;
    TemperatureSensor temperatureSensor;
    valve.injectInterface(&temperatureSensor);
    valve.setExpectedValue(16);
    valveStatus = valve.openValve();
    cout << "Temperature: " << temperatureSensor.getTemperature() << "^C | ";
    cout << "Valve status: " << (valveStatus ? "Open" : "Close") << endl;

    return 0;
}
