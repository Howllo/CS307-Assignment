/****************************************
*
*	File: FOLLOWLINK_IFGREATER.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: To do stuff.
*	Assignment: Programming Assignment 2
*	Declaration: This program is entirely my own work.
*
****************************************/

#include "FOLLOWLINK_IFGREATER.h"
#include "WellSensor.h"

double FOLLOWLINK_IFGREATER::AlgorithmUse(double min_data, double max_data, double current_data, WellSensor* linked_sensor)
{
    linked_sensor->ChangeSensorData();
    if(linked_sensor->GetCurrentData() > current_data)
        return linked_sensor->GetCurrentData();
    return GenerateNewRandom(min_data, max_data);
}
