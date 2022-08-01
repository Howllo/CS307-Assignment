/****************************************
*
*	File: STEPDEC_MAX2MIN.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: To do stuff.
*	Assignment: Programming Assignment 2
*	Declaration: This program is entirely my own work.
*
****************************************/

#include "STEPDEC_MAX2MIN.h"

double STEPDEC_MAX2MIN::AlgorithmUse(double min_data, double max_data, double step_data, double current_data)
{
    // Rand
    const double generated = GenerateNewRandom(0, step_data);
    
    if( current_data - generated  > min_data )
        return current_data -= generated;
    return current_data;
}