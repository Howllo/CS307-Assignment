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
#include <chrono>
#include <ctime>

WellClass::WellClass()
{
    senTypes = new std::vector<std::string*>; 
    well_sensor_handler = nullptr;
    isSelect = false;
    m_pNext = nullptr;
    numberSensor = 0;
}

WellClass::~WellClass()
{
    delete well_sensor_handler;
    for(int i = 0; i < senTypes->size(); i++)
    {
        const std::string* stringDelete = (*senTypes)[i];
        senTypes->pop_back();
        delete stringDelete;
    }
    delete senTypes;
}

void WellClass::CreateSensorData(OilFieldDataParser* parser)
{
    well_sensor_handler = new WellSensorHandler(senTypes, parser, this);
}

void WellClass::printWellData() const
{
    char time[32];
    const std::time_t timeT = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    ctime_s(time, sizeof(time), &timeT);
    std::cout << std::endl << "\tDisplay Time: " << time;
    std::cout << "Well Operator:\t" << wellOperator << std::endl;
    std::cout << "Well ID:\t" << well_ID << std::endl;
    std::cout << "----------------------Sensor Data-----------------------" << std::endl;
    well_sensor_handler->printSensorData();
    std::cout << "-------------------End of Sensor Data-------------------" << std::endl;
}