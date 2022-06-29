/****************************************
*
*	File: HoleDepth.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: Handles all the functionality for the class HoleDepth.h.
*	Assignment: Programming Assignment 1
*	Declaration: This program is entirely my own work.
*
****************************************/

#include "HoleDepth.h"

HoleDepth::HoleDepth()
{
    SetSensorType(hole_depth);
    SetSensorData(0.f);
}

HoleDepth::~HoleDepth()
{
}
