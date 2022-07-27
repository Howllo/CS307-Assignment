/****************************************
*
*	File: AlgorithmStrategy.h
*	Author: Tony A. Hardiman Jr.
*	Purpose: To do stuff.
*	Assignment: Programming Assignment 2
*	Declaration: This program is entirely my own work.
*
****************************************/

#pragma once

class AlgorithmStrategy
{
public:
    AlgorithmStrategy();
    virtual ~AlgorithmStrategy();
    virtual double AlgorithmUse(double min, double max, double step);
};