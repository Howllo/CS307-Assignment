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
#include "WellSensorHandler.h"

class WellClass
{
    char well_ID[8];
    char wellOperator[28];
    int numberSensor;
    class WellSensorHandler* well_sensor_handler;
public:
    WellClass(class OilFieldDataParser* parser);
    ~WellClass();

    // Getters
    const char* GetWellID() const;
    const char* GetWellOperator() const;
    int GetNumberSensor() const;
    WellSensorHandler* GetWellSensorHandler();

    // Setters
    void SetWellID(char* ID);
    void SetWellOperator(char* well_operator);
    void SetNumberOfSensor(int sensorAmount);
};
