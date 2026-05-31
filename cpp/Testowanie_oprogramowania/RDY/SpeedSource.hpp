#pragma once 
#include "SpeedSourceInterface.hpp"
class SpeedSource : public SpeedSourceInterface 
{
    public:
        SpeedSource();
        void setSpeed(double newSpeed) override;
        double getSpeed() override;
    private:
        double m_speed;
};
