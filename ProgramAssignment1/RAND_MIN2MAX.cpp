/****************************************
*
*	File: RAND_MIN2MAX.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: Holder file for all the function that the class will be using.
*	Assignment: Programming Assignment 2
*	Declaration: This program is entirely my own work.
*
****************************************/

#include "RAND_MIN2MAX.h"

double RAND_MIN2MAX::AlgorithmUse(double min_data, double max_data, double step_data, double current_data)
{
    return current_data = GenerateNewRandom(min_data, max_data);
}