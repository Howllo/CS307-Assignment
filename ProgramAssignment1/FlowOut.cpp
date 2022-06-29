/****************************************
*
*	File: FlowOut.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: Handles all the functionality for the class FlowOut.h.
*	Assignment: Programming Assignment 1
*	Declaration: This program is entirely my own work.
*
****************************************/

#include "FlowOut.h"

FlowOut::FlowOut()
{
    SetSensorType(flow_out);
    SetSensorData(0);
}

FlowOut::~FlowOut()
{
}
