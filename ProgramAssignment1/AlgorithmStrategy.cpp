/****************************************
*
*	File: AlgorithmStrategy.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: To do stuff.
*	Assignment: Programming Assignment 2
*	Declaration: This program is entirely my own work.
*
****************************************/

#include "AlgorithmStrategy.h"

#include <iostream>

AlgorithmStrategy::AlgorithmStrategy()
= default;

AlgorithmStrategy::~AlgorithmStrategy()
= default;

double AlgorithmStrategy::AlgorithmUse(double min, double max, double step)
{
    std::cout << "Error: Override failed." << std::endl;
    return 0;
}
