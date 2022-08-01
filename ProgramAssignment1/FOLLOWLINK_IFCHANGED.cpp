/****************************************
*
*	File: FOLLOWLINK_IFCHANGED.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: To do stuff.
*	Assignment: Programming Assignment 2
*	Declaration: This program is entirely my own work.
*
****************************************/

#include "FOLLOWLINK_IFCHANGED.h"
#include <cmath>
#include <limits>
#include "WellSensor.h"


double FOLLOWLINK_IFCHANGED::AlgorithmUse(double min_data, double max_data, double current_data, WellSensor* linked_sensor)
{
    if(last_value == 0.0)
        last_value = linked_sensor->GetCurrentData();

    //Compare the two doubles safely. - JetBrain Rider does not like using !=.
    if(!(std::fabs(linked_sensor->GetCurrentData() - last_value) < std::numeric_limits<double>::epsilon()))
    {
        last_value = linked_sensor->GetCurrentData();
        return GenerateNewRandom(min_data, max_data);
    }
    return 0;
}