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
public:
    WellClass(class OilFieldDataParser* parser);
    ~WellClass();

    // Public variable.
    WellClass* m_pNext;
    char well_ID[8];
    char wellOperator[28];
    int numberSensor;
    class WellSensorHandler* well_sensor_handler;
};
