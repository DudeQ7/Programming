#pragma once
class SpeedSourceInterface {
public:
    virtual ~SpeedSourceInterface() = default;
    virtual void setSpeed(double newSpeed) = 0; 
    virtual double getSpeed() = 0;
};