#pragma once

#include <chrono>
#include "WellClass.h"
#include "WellSensor.h"

enum SensorSelection { sensor_add, sensor_remove };

class SensorReader
{
    int timeInterval;
    std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> nextTime;

    /**
     * \brief Used for printing out sensor selection data and whether if a sensor is currently selected.
     * \param Sensor Takes in WellSensor linked list.
     */
    void PrintSelectionSensor(WellSensor* Sensor);
public:
    SensorReader();
    ~SensorReader();

    /**
     * \brief Prints data from the selected sensor to be printed.
     * \param m_pHead Head of the selected linked list of wells.
     */
    void PrintSensorData(class WellClass* m_pHead);

    /**
     * \brief Used to add and remove sensor from the user tracking.
     * \param well Sends in well class that needs to be modified.
     * \param selection Send in action that will happen, sensor_add or sensor_remove.
     */
    void SelectSensor(class WellClass* well, SensorSelection selection);
};
