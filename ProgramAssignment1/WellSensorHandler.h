/****************************************
*
*	File: WellSensorHandler.h
*	Author: Tony A. Hardiman Jr.
*	Purpose: To do stuff.
*	Assignment: Programming Assignment 1
*	Declaration: This program is entirely my own work.
*
****************************************/

#pragma once

#include "SensorReader.h"
#include <unordered_map>
#include "WellSensor.h"
#include "WellClass.h"

class WellSensorHandler
{
    // Owning object of well sensor handler.
    class WellClass* owning_object_;
    
    // Used to get the head sensor for used in linked list.
    WellSensor* m_pHead;

    // Handles sensor reading.
    SensorReader* sensorReader;

    // Dynamic selection for user choice.
    std::unordered_map<int, std::string> userChoiceMap;
    
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
     * \param senTypes Sends in character array with the sensor type to be looked up in XML file.
     * \param parser Uses the XML parser to find the sensor in the XML file.
     */
    void CreateSensorFromXML(std::vector<std::string*>* senTypes, class OilFieldDataParser* parser);
public:
    /**
     * \brief Constructor takes in important information for the construction of the well sensors.
     * \param senTypes Takes in a SensorType to find the correct well sensors in the XML file.
     * \param parser Takes in the parser to used to get the well information from the XML file.
     * \param owner Takes in a Well Class to set the owning object.
     */
    WellSensorHandler(std::vector<std::string*>* senTypes, class OilFieldDataParser* parser, WellClass* owner);

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
     */
    void SelectSensor();

    /**
     * \brief Used to get the number of sensor within the factory.
     * \return Returns int of total number of sensor.
     */
    int GetTotalNumberOfSensor() const;

    /**
     * \brief Used to call sensor reader select sensor without needing to call well sensor handler class several times.
     */
    void CallSensorReaderSelect();

    /**
     * \brief Used to set algorithms.
     * \param Sensor Sends in a newly created sensor to find what type of algorithm  it uses.
     */
    void SetSensorAlgorithm(WellSensor* Sensor);

    /**
     * \brief Used to find well sensor and returns the address of a the well sensor.
     * \param sensorType Takes in a character array to compare array with the sensor type array.
     * \return Returns a Well sensor with the same time that the character array is looking for.
     */
    WellSensor* FindWellSensor(const char* sensorType) const;

    /**
     * \brief Used to generate a map of all the sensor within the program.
     * \param senTypes Takes in a vectors with all the sensor types of this specific well.
     */
    void CreateUserMap(std::vector<std::string*>* senTypes);

    /**
     * \brief Used to get total selected or not selected sensor. Prevents the locking of user input.
     * \param selection Sensor_add check to see if there are sensor able to be added.
     *                  Sensor_remove check to see if sensor are able to be removed.
     * \return Returns a int of how many sensors are currently selected, or not selected.
     */
    int GetTotalNumberSensor(enum SensorSelection selection);
};