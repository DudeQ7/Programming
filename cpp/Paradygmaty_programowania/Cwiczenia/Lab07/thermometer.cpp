#include <iostream>
class thermometer
{

public:
    double temperature; 
};
void updateTemperature(thermometer& t, double newTemp)
{
    t.temperature = newTemp; 
}
void getTemperature(const thermometer& t)
{
    std::cout << "Obecna temperatura: " << t.temperature << " stopnia Celsjusza." << std::endl;
}

int main()
{
    thermometer t;
    updateTemperature(t, 36.5);
    getTemperature(t);
    return 0; 
}