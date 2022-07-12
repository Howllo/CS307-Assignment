#include "SensorReader.h"
#include <iostream>



SensorReader::SensorReader()
{
}

SensorReader::~SensorReader()
{
}

void SensorReader::SelectSensor(int NumberOfSensor, WellSensor* SensorHead, WellSensorHandler* Handler, SensorSelection selection)
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
                Handler->UserInputProcessor(userChoice, sensor_add);
            }
            else if(selection == sensor_remove)
            {
                Handler->UserInputProcessor(userChoice, sensor_remove);
            }
            std::cout << std::endl;
        }
        else return;
    }
}

void SensorReader::PrintSelectionSensor(const WellSensor* Sensor)
{
    std::cout << "Please set the sensor you want to watch" << std::endl;
    std::cout << "Exit - \t\t\t0" << std::endl;
    
    const WellSensor* temp = Sensor;
    while(temp != nullptr)
    {
        if(!temp->isSelected && strcmp(temp->GetClassName(), "SensorBitDepth") == 0)
        {
            std::cout << "Bit Depth - \t\t1" << std::endl;
        }
        else if(temp->isSelected && strcmp(temp->GetClassName(), "SensorBitDepth") == 0)
        {
            std::cout << "Bit Depth - \t\t1" << " - Selected" << std::endl;
        }

        if(!temp->isSelected && strcmp(temp->GetClassName(), "SensorHoleDepth") == 0)
        {
            std::cout << "Hole Depth - \t\t2" << std::endl;
        }
        else if(temp->isSelected && strcmp(temp->GetClassName(), "SensorHoleDepth") == 0)
        {
            std::cout << "Hole Depth - \t\t2" << " - Selected" << std::endl;
        }

        if(!temp->isSelected && strcmp(temp->GetClassName(), "SensorROP") == 0)
        {
            std::cout << "Rate of Penetration - \t3" << std::endl;
        }
        else if(temp->isSelected && strcmp(temp->GetClassName(), "SensorROP") == 0)
        {
            std::cout << "Rate of Penetration - \t3" << " - Selected" << std::endl;
        }

        if(!temp->isSelected && strcmp(temp->GetClassName(), "SensorPumpPressure") == 0)
        {
            std::cout << "Pump Pressure - \t4" << std::endl;
        }
        else if(temp->isSelected && strcmp(temp->GetClassName(), "SensorPumpPressure") == 0)
        {
            std::cout << "Pump Pressure - \t4" << " - Selected" << std::endl;
        }

        if(!temp->isSelected && strcmp(temp->GetClassName(), "SensorCasingPressure") == 0)
        {
            std::cout << "Casing Pressure: - \t5" << std::endl;
        }
        else if(temp->isSelected && strcmp(temp->GetClassName(), "SensorCasingPressure") == 0)
        {
             std::cout << "Casing Pressure: - \t5" << " - Selected" << std::endl;
        }

        if(!temp->isSelected && strcmp(temp->GetClassName(), "SensorFlowOut") == 0)
        {
            std::cout << "Flow Out - \t\t6" << std::endl;
        }
        else if(temp->isSelected && strcmp(temp->GetClassName(), "SensorFlowOut") == 0)
        {
            std::cout << "Flow Out - \t\t6" <<  " - Selected" << std::endl;
        }

        if(!temp->isSelected && strcmp(temp->GetClassName(), "SensorTorqueMax") == 0)
        {
            std::cout << "Torque Max - \t\t7" << std::endl;
        }
        else if(temp->isSelected && strcmp(temp->GetClassName(), "SensorTorqueMax") == 0)
        {
            std::cout << "Torque Max - \t\t7" << " - Selected" << std::endl;
        }

        if(!temp->isSelected && strcmp(temp->GetClassName(), "SensorMudPitVolume") == 0)
        {
            std::cout << "Mud Pit Volume - \t8" << std::endl;
        }
        else if(temp->isSelected && strcmp(temp->GetClassName(), "SensorMudPitVolume") == 0)
        {
            std::cout << "Mud Pit Volume - \t8" << " - Selected" << std::endl;
        }
        temp = temp->next;
    }
}