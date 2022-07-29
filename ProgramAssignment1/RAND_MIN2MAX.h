/****************************************
*
*	File: SensorReader.h
*	Author: Tony A. Hardiman Jr.
*	Purpose: Holder file for all the function that the class will be using.
*	Assignment: Programming Assignment 1
*	Declaration: This program is entirely my own work.
*
****************************************/

#pragma once
#include "AlgorithmStrategy.h"

class RAND_MIN2MAX : public AlgorithmStrategy
{
public:
    double AlgorithmUse(double min_data, double max_data, double step_data, double current_data) override;
};
