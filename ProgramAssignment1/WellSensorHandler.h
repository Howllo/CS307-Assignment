#pragma once

#include "SensorReader.h"
#include "WellSensor.h"
#include "WellClass.h"

class WellSensorHandler
{
    // Used to get the head sensor for used in linked list.
    WellSensor* m_pHead;

    // Handles sensor reading.
    SensorReader* sensorReader;
    
    /**
     * \brief Used to generate seeds for randomness.
     * THIS WAS THE ANSWER TO RANDOMNESS. Since computer is faster than perceived time in seconds, and I need to generate new seed
     * faster than a single second. I had to generate new seeds at computer instruction speed, so incrementing it was the only
     * way to generate it fast enough for each function call.
     */
    long SeedGen;

    // Used for total number of sensor within the linked list.
    int NumberOfSensors;

    /**
     * \brief Used to get the total number of sensor through the used of the linked list. It sets "int NumberOfSensors."
     */
    void GetTotalNumberOfSensor();
    
    /**
     * \brief Creates new sensor based on XML file. THIS IS ONLY USED FOR CONSTRUCTOR.
     * \param Well_ID Sends in character array with the sensor Well ID to be looked up in XML file.
     * \param parser Uses the XML parser to find the sensor in the XML file.
     */
    void CreateSensorFromXML(char* Well_ID, OilFieldDataParser* parser);
public:
    /**
     * \brief Constructor takes in important information for the construction of the well sensors.
     * \param Well_ID Takes in a Well_ID to find the correct well sensors in the XML file.
     * \param parser Takes in the parser to used to get the well information from the XML file.
     * \param numberSensor Used to get the total amount of sensor from the well.
     */
    WellSensorHandler(char* Well_ID, class OilFieldDataParser* parser, int numberSensor);

    /**
     * \brief Deletes all the sensor in the linked list, and deletes the sensor reader.
     */
    ~WellSensorHandler();

    /**
     * \brief Used to delete certain sensors within the sensor linked list.
     * \param SensorName Character array that contains the sensor name to be searched and deleted.
     */
    bool DeleteSensor(const char* SensorName);
    
    /**
     * \brief Use to print the date from the selected sensor through the use of a linked list.
     */
    void printSensorData();

    /**
     * \brief Used for calling SetWellSensorSelection through the use of a switch case statement.
     * \param Sensor Takes ina int to determine what sensor to change through a switch case statement.
     * \param selection Sensor Selection is enum that tells the function what to do, add or remove.
     */
    void UserInputProcessor(int Sensor, enum SensorSelection selection);
 
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
    WellSensor* GetWellSensorsList() const;

    /**
     * \brief Used to add sensor to the linked list.
     * \param sensor Takes in a Well Sensor class to add to the linked list.
     */
    void AddWellSensor(WellSensor* sensor);
    
    /**
     * \brief Used to get the sensor reader.
     * \return Returns the SensorReader class.
     */
    SensorReader* GetSensorReader() const;
    
    /**
     * \brief Select sensor to be active.
     * \param Well_ID Send 
     */
    void SelectSensor(const char* Well_ID);

    /**
     * \brief Used to get the number of sensor within the factory.
     * \return Returns int of total number of sensor.
     */
    int GetTotalNumberOfSensor() const;

    /**
     * \brief Used to call sensor reader select sensor without needing to call well sensor handler class several times.
     */
    void CallSensorReaderSelect();
};