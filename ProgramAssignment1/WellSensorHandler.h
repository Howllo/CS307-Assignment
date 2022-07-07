#pragma once

#include "SensorReader.h"
#include "WellSensor.h"
#include "WellClass.h"

class WellSensorHandler
{
    WellSensor* m_pHead;
public:
    WellSensorHandler(char* Well_ID, class OilFieldDataParser* parser, int numberSensor);
    ~WellSensorHandler();

    // Print all the sensor data.
    void printSensorData();

    // Method
    void SelectSensor(int Sensor, enum SensorSelection selection);
    void ChangeSensorData();
    void SetWellSensorSelect(const char* Name, enum SensorSelection selection) const;
    
    // Getter
    WellSensor* GetWellSensors() const;
    
    // Setters
    void AddWellSensor(WellSensor* sensor);
};