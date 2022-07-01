/****************************************
*
*	File: WellSensor.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: Handles all the functionality for the class WellSensor.h.
*	Assignment: Programming Assignment 1
*	Declaration: This program is entirely my own work.
*
****************************************/

#include "WellSensor.h"
#include <string>

WellSensor::WellSensor()
{
    sensorType = sensor_none;
    minData = 0;
    maxData = 0;
    next = nullptr;
}

WellSensor::~WellSensor()
{
}

double WellSensor::GetMinSensorData() const
{
    return minData;
}

double WellSensor::GetMaxSensorData() const
{
    return maxData;
}

const char* WellSensor::GetUnitInfo() const
{
    return unitInfo;
}

const char* WellSensor::GetUnitAbbrev() const
{
    return unitAbbrev;
}

const char* WellSensor::GetDisplayName() const
{
    return displayName;
}

SensorType WellSensor::GetSensorType() const
{
    return sensorType;
}

void WellSensor::SetMinSensorData(double DataValue)
{
    minData = DataValue;
}

void WellSensor::SetMaxSensorData(double DataValue)
{
    maxData = DataValue;
}

void WellSensor::SetUnitInfo(char* Unit_Info)
{
    strcpy_s(unitInfo, Unit_Info);
}

void WellSensor::SetUnitAbbrev(char* Unit_Abbrev)
{
    strcpy_s(unitAbbrev, Unit_Abbrev);
}

void WellSensor::SetDisplayName(char* Name)
{
    strcpy_s(displayName, Name);
}

void WellSensor::SetSensorType(SensorType Type)
{
    sensorType = Type;
}
