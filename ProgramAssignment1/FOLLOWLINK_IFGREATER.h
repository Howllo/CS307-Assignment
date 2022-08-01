/****************************************
*
*	File: FOLLOWLIN_IFGREATER.h
*	Author: Tony A. Hardiman Jr.
*	Purpose: Holder file for all the function that the class will be using.
*	Assignment: Programming Assignment 2
*	Declaration: This program is entirely my own work.
*
****************************************/

#pragma once
#include "AlgorithmStrategy.h"

class FOLLOWLINK_IFGREATER : public AlgorithmStrategy
{
public:
    double AlgorithmUse(double min_data, double max_data, double current_data, WellSensor* linked_sensor) override;
};
