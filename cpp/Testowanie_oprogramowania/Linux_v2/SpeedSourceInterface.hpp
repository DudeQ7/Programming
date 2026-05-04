#pragma once

class SpeedSourceInterface {
public:
    virtual ~SpeedSourceInterface() = default;
    virtual void setSpeed(double newSpeed) = 0; // Musi być double!
    virtual double getSpeed() = 0;
};