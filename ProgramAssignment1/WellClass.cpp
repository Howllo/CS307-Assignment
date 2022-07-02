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
