#pragma once

#include "WellClass.h"

class SensorReader
{
    int TimeInterval;
    
public:
    SensorReader();
    ~SensorReader();

    //Print all data from selected wells.
    void PrintSensorData(WellClass* m_pHead);
};
