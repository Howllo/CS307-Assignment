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
#include <random>

AlgorithmStrategy::AlgorithmStrategy()
{
    seed_gen = 0;
    last_value = 0.0;
}

AlgorithmStrategy::~AlgorithmStrategy()
= default;

int AlgorithmStrategy::GenerateNewRandom(double min, double max)
{
    seed_gen++;
    std::default_random_engine totalRand(seed_gen);
    const std::uniform_int_distribution<int> RandomNum(static_cast<int>(min), static_cast<int>(max));
    return RandomNum(totalRand);
}

double AlgorithmStrategy::AlgorithmUse(double min_data, double max_data, double step_data, double current_data)
{
    std::cout << "Error: Override failed." << std::endl;
    return 0;
}

double AlgorithmStrategy::AlgorithmUse(double min_data, double max_data, double current_data, WellSensor* linked_sensor)
{
    std::cout << "Error: Overload function failed to override." << std::endl;
    return 0;
}
