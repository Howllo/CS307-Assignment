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
    minData = 0;
    maxData = 0;
    isSelected = false;
    next = nullptr;
    currentData = 0;
}

WellSensor::~WellSensor()
{
}

const char* WellSensor::GetSensorType() const
{
    return sensorType;
}

const char* WellSensor::GetClassName() const
{
    return className;
}

double WellSensor::GetMinSensorData() const
{
    return minData;
}

double WellSensor::GetMaxSensorData() const
{
    return maxData;
}

const char* WellSensor::GetDisplayName() const
{
    return displayName;
}

const char* WellSensor::GetUnitInfo() const
{
    return unitInfo;
}

const char* WellSensor::GetUnitAbbrev() const
{
    return unitAbbrev;
}

double WellSensor::GetCurrentData() const
{
    return currentData;
}

void WellSensor::SetCurrentData(double Data)
{
    currentData = Data;
}

void WellSensor::SetSensorType(char* SensorType)
{
    strcpy_s(sensorType, SensorType);
}

void WellSensor::SetClassName(char* ClassName)
{
    strcpy_s(className, ClassName);
}

void WellSensor::SetMinSensorData(double DataValue)
{
    minData = DataValue;
}

void WellSensor::SetMaxSensorData(double DataValue)
{
    maxData = DataValue;
}

void WellSensor::SetDisplayName(char* Name)
{
    strcpy_s(displayName, Name);
}

void WellSensor::SetUnitInfo(char* Unit_Info)
{
    strcpy_s(unitInfo, Unit_Info);
}

void WellSensor::SetUnitAbbrev(char* Unit_Abbrev)
{
    strcpy_s(unitAbbrev, Unit_Abbrev);
}
