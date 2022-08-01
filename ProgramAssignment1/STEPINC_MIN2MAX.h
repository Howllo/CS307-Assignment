/****************************************
*
*	File: STEPINC_MIN2MAX.h
*	Author: Tony A. Hardiman Jr.
*	Purpose: To do stuff.
*	Assignment: Programming Assignment 2
*	Declaration: This program is entirely my own work.
*
****************************************/

#pragma once
#include "AlgorithmStrategy.h"

class STEPINC_MIN2MAX : public AlgorithmStrategy
{
public:
    double AlgorithmUse(double min_data, double max_data, double step_data, double current_data) override;
};
