#pragma once

#include "SensorReader.h"
#include "WellSensor.h"
#include "WellClass.h"

class WellSensorHandler
{
    WellSensor* m_pHead;

    /**
     * \brief Used to generate seeds for randomness.
     * THIS WAS THE ANSWER TO RANDOMNESS. Since computer is faster than perceived time in seconds, and I need to generate new seed
     * faster than a single second. I had to generate new seeds at computer instruction speed, so incrementing it was the only
     * way to generate it fast enough for each function call.
     */
    long SeedGen;
public:
    WellSensorHandler(char* Well_ID, class OilFieldDataParser* parser, int numberSensor);
    ~WellSensorHandler();

    /**
     * \brief Use to print the date from the selected sensor through the use of a linked list.
     */
    void printSensorData();

    /**
     * \brief Used for calling SetWellSensorSelection through the use of a switch case statement.
     * \param Sensor Takes ina int to determine what sensor to change through a switch case statement.
     * \param selection Sensor Selection is enum that tells the function what to do, add or remove.
     */
    void SelectSensor(int Sensor, enum SensorSelection selection);

    /**
     * \brief Used to simulate the changing of sensor data through random.
     */
    void ChangeSensorData();

    /**
     * \brief Used to set the Well Sensor to selected or not select through the use of a boolean.
     * \param Name This takes in a name within the program that comes from the XML file. This is hard-coded from SelectSensor.
     * \param selection Sensor Selection is enum that tells the function what to do, add or remove.
     */
    void SetWellSensorSelect(const char* Name, enum SensorSelection selection) const;

    /**
     * \brief Used to get the sensor linked list.
     * \return Returns the head of the sensor linked list.
     */
    WellSensor* GetWellSensors() const;

    /**
     * \brief Used to add sensor to the linked list.
     * \param sensor Takes in a Well Sensor class to add to the linked list.
     */
    void AddWellSensor(WellSensor* sensor);
};