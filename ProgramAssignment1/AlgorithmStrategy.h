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
protected:
    // Generator random seed.
    int seed_gen;

    // Saved Value
    double last_value;

    /**
     * \brief Used to generate numbers for the used of algorithm amd sensor simulation.
     * \param min The minimal number that will be generated.
     * \param max The maximum number that will be generated.
     * \return Returns a random number between min and max.
     */
    int GenerateNewRandom(double min, double max);
public:
    AlgorithmStrategy();
    virtual ~AlgorithmStrategy();
    
    /**
     * \brief Get random current to set the sensor.
     * \param min_data The min allows for the sensor.
     * \param max_data Max allowed for the sensor.
     * \param step_data The total step data for the sensor.
     * \param current_data Current data in the sensor.
     * \return Returns a double of the current.
     */
    virtual double AlgorithmUse(double min_data, double max_data, double step_data, double current_data);
    
    /**
     * \brief Get random value, but also generate a random or check current value for
     * the linked sensor.
     * \param min_data The min allows for the sensor.
     * \param max_data Max allowed for the sensor.
     * \param current_data Current data in the sensor.
     * \param linked_sensor Get the linked sensor.
     * \return Returns a double of the current.
     */
    virtual double AlgorithmUse(double min_data, double max_data, double current_data, class WellSensor* linked_sensor);
};