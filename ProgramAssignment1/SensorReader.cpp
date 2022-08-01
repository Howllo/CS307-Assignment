/****************************************
*
*	File: SensorReader.h
*	Author: Tony A. Hardiman Jr.
*	Purpose: Holder file for all the function that the class will be using.
*	Assignment: Programming Assignment 1
*	Declaration: This program is entirely my own work.
*
****************************************/

#include "WellSensorHandler.h"
#include "SensorReader.h"
#include <iostream>

SensorReader::SensorReader()
{
}

SensorReader::~SensorReader()
{
}

void SensorReader::SelectSensor(int NumberOfSensor, WellSensor* SensorHead, WellSensorHandler* Handler, SensorSelection selection,
    std::unordered_map<int, std::string> choiceMap)
{
    int userChoice = 0;
    for(int i = 0; i < NumberOfSensor; i++)
    {
        std::cout << std::endl;
        PrintSelectionSensor(SensorHead);
        std::cout << "Enter the number: ";
        std::cin >> userChoice;
        if(userChoice > 0 && userChoice < 9)
        {
            if(selection == sensor_add)
            {
                Handler->SetWellSensorSelect(choiceMap[userChoice].c_str(), sensor_add);
            }
            else if(selection == sensor_remove)
            {
                Handler->SetWellSensorSelect(choiceMap[userChoice].c_str(), sensor_add);
            }
            std::cout << std::endl;
        }
        else return;
    }
}

void SensorReader::PrintSelectionSensor(const WellSensor* Sensor)
{
    int i = 0;
    std::cout << "Choose a sensor that you want to modify." << std::endl;
    std::cout << "Exit - \t\t\t0" << std::endl;
    
    const WellSensor* temp = Sensor;
    while(temp != nullptr)
    {
        std::string tempStr = temp->GetDisplayName();
        if(!temp->isSelected)
        {
            if(tempStr.size() >= 5 && tempStr.size() <= 12)
            {
                std::cout << temp->GetDisplayName() << " - \t\t" << (i + 1) << std::endl;
            }
            else if(tempStr.size() < 5)
            {
                std::cout << temp->GetDisplayName() << " - \t\t\t" << (i + 1) << std::endl;
            }
            else
            {
                std::cout << temp->GetDisplayName() << " - \t" << (i + 1) << std::endl;
            }
        }
        else if(temp->isSelected)
        {
            if(tempStr.size() >= 5 && tempStr.size() <= 12)
            {
                std::cout << temp->GetDisplayName() << " - \t\t" << (i + 1) << " - Selected" << std::endl;
            }
            else if(tempStr.size() < 5)
            {
                std::cout << temp->GetDisplayName() << " - \t\t\t" << (i + 1) << " - Selected" << std::endl;
            }
            else
            {
                std::cout << temp->GetDisplayName() << " - \t" << (i + 1) << " - Selected" << std::endl;
            }
        }
        temp = temp->next;
        i++;
    }
}