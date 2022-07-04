#pragma once

#include <chrono>
#include "WellClass.h"

class SensorReader
{
    int timeInterval;

    std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> nextTime;
    
public:
    SensorReader();
    ~SensorReader();

    //Print all data from selected wells.
    void PrintSensorData(WellClass* m_pHead);
};
