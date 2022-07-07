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
#include <iostream>

WellClass::WellClass(OilFieldDataParser* parser)
{
    isSelect = false;
    m_pNext = nullptr;
    
    // Create Well Sensor Handler Object
    well_sensor_handler = new WellSensorHandler(well_ID, parser, numberSensor);
}

WellClass::~WellClass()
{
    delete well_sensor_handler;
}

void WellClass::printWellData()
{
    std::cout << std::endl << "Well Operator:\t" << wellOperator;
    std::cout << "\tWell ID:\t" << well_ID << std::endl;
    std::cout << "-----------------------Sensor Data-----------------------" << std::endl;
    well_sensor_handler->printSensorData();
}
