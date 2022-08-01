/****************************************
*
*	File: WellClass.h
*	Author: Tony A. Hardiman Jr.
*	Purpose: Holder file for all the function that the class will be using.
*	Assignment: Programming Assignment 1
*	Declaration: This program is entirely my own work.
*
****************************************/

#pragma once
#include <string>
#include <vector>

#include "WellSensorHandler.h"

class WellClass
{

public:
    WellClass();
    ~WellClass();

    // Public variable.
    WellClass* m_pNext;
    char well_ID[9] = "";
    char wellOperator[32] = "";
    int numberSensor;
    bool isSelect;
    std::vector<std::string*>* senTypes;
    
    /**
     * \brief Handles all the well sensors.
     */
    class WellSensorHandler* well_sensor_handler;

    /**
     * \brief Prints the well information and calls the sensor print.
     */
    void printWellData() const;

    /**
     * \brief Only used during start due to creation of well not having a well ID.
     * \param parser Take in a data parser for creating sensors.
     */
    void CreateSensorData(class OilFieldDataParser* parser); 
};
