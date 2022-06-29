/****************************************
*
*	File: TorqueMax.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: Handles all the functionality for the class TorqueMax.h.
*	Assignment: Programming Assignment 1
*	Declaration: This program is entirely my own work.
*
****************************************/

#include "TorqueMax.h"

TorqueMax::TorqueMax()
{
    SetSensorType(torque_max);
    SetSensorData(0);
}

TorqueMax::~TorqueMax()
{
}
