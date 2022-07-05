#pragma once

#include "WellSensor.h"
#include "WellClass.h"

class WellSensorHandler
{
    WellSensor* m_pHead;
public:
    WellSensorHandler(char* Well_ID, class OilFieldDataParser* parser, int &numberSensor);
    ~WellSensorHandler();

    // Print all the sensor data.
    void printSensorData();

    // Method
    void AddSensor(int* Sensor);
    
    // Getter
    WellSensor* GetWellSensors() const;
    
    // Setters
    void AddWellSensor(WellSensor* sensor);
};