/****************************************
*
*	File: STEPINC_MIN2MAX.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: To do stuff.
*	Assignment: Programming Assignment 2
*	Declaration: This program is entirely my own work.
*
****************************************/

#include "STEPINC_MIN2MAX.h"

double STEPINC_MIN2MAX::AlgorithmUse(double min_data, double max_data, double step_data, double current_data)
{
    // Rand
    const int generated = GenerateNewRandom(0, step_data);
    
    if( current_data + generated < max_data )
        return current_data += generated;
    return current_data;
}