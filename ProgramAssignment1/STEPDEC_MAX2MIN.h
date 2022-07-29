/****************************************
*
*	File: STEPDEC_MAX2MIN.h
*	Author: Tony A. Hardiman Jr.
*	Purpose: To do stuff.
*	Assignment: Programming Assignment 2
*	Declaration: This program is entirely my own work.
*
****************************************/

#pragma once
#include "AlgorithmStrategy.h"

class STEPDEC_MAX2MIN : public AlgorithmStrategy
{
public:
    double AlgorithmUse(double min_data, double max_data, double step_data, double current_data) override;
};