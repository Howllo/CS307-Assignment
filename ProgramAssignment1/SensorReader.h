/****************************************
*
*	File: SensorReader.h
*	Author: Tony A. Hardiman Jr.
*	Purpose: Holder file for all the function that the class will be using.
*	Assignment: Programming Assignment 1
*	Declaration: This program is entirely my own work.
*
****************************************/

#pragma once

#include <chrono>
#include "WellClass.h"
#include "WellSensor.h"

enum SensorSelection { sensor_add, sensor_remove };

class SensorReader
{
    /**
     * \brief Used for printing out sensor selection data and whether if a sensor is currently selected.
     * \param Sensor Takes in WellSensor linked list.
     */
    void PrintSelectionSensor(const WellSensor* Sensor);
public:
    SensorReader();
    ~SensorReader();

    /**
     * \brief Used for selecting the sensors.
     * \param NumberOfSensor Sensor in the total amount of sensor for the given well.
     * \param SensorHead Takes in a linked list of the well sensor for the used from PrintSelection.
     * \param Handler Sends in the sensor handler class to use functions.
     * \param selection The decision type for getting added or remove.
     */
    void SelectSensor(int NumberOfSensor, WellSensor* SensorHead,  class WellSensorHandler* Handler, SensorSelection selection);
};
