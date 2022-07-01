/****************************************
*
*	File: WellClass.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: Handles all the functionality for the class WellClass.h.
*	Assignment: Programming Assignment 1
*	Declaration: This program is entirely my own work.
*
****************************************/

#include "WellClass.h"

WellClass::WellClass(OilFieldDataParser* parser)
{
    numberSensor = 0;
    well_sensor_handler = new WellSensorHandler(well_ID, parser);
}

WellClass::~WellClass()
{
    delete well_sensor_handler;
}

const char* WellClass::GetWellID() const
{
    return well_ID;
}

const char* WellClass::GetWellOperator() const
{
    return wellOperator;
}

int WellClass::GetNumberSensor() const
{
    return numberSensor;
}
WellSensorHandler* WellClass::GetWellSensorHandler()
{
    return well_sensor_handler;
}

void WellClass::SetWellID(char* ID)
{
    strcpy_s(well_ID, ID);
}

void WellClass::SetWellOperator(char* well_operator)
{
    strcpy_s(wellOperator, well_operator);
}

void WellClass::SetNumberOfSensor(int sensorAmount)
{
    numberSensor = sensorAmount;
}
