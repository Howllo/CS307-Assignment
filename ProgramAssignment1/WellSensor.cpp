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

WellSensor::WellSensor()
{
    sensorType = sensor_none;
    sensorData = 0;
}

WellSensor::~WellSensor()
{
}

float WellSensor::GetSensorData() const
{
    return sensorData;
}

SensorType WellSensor::GetSensorType() const
{
    return sensorType;
}

void WellSensor::SetSensorData(float DataValue)
{
    sensorData = DataValue;
}

void WellSensor::SetSensorType(SensorType Type)
{
    sensorType = Type;
}
