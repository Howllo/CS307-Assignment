/****************************************
*
*	File: CasingPressure.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: Handles all the functionality for the class CasingPressure.h.
*	Assignment: Programming Assignment 1
*	Declaration: This program is entirely my own work.
*
****************************************/

#include "CasingPressure.h"

CasingPressure::CasingPressure()
{
    SetSensorType(casing_pressure);
    SetSensorData(0);
}

CasingPressure::~CasingPressure()
{
}
