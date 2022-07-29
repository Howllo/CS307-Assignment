/****************************************
*
*	File: FOLLOWLINK_IFCHANGED.h
*	Author: Tony A. Hardiman Jr.
*	Purpose: To do stuff.
*	Assignment: Programming Assignment 2
*	Declaration: This program is entirely my own work.
*
****************************************/

#pragma once
#include "AlgorithmStrategy.h"

class FOLLOWLINK_IFCHANGED : public AlgorithmStrategy
{
public:
    double AlgorithmUse(double min_data, double max_data, double current_data, WellSensor* linked_sensor) override;
};
