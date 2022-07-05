/****************************************
*
*	File: WellHandler.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: Handles all the functionality for the class WellHandler.h.
*	Assignment: Programming Assignment 1
*	Declaration: This program is entirely my own work.
*
****************************************/

#include "WellHandler.h"
#include "OilFieldDataParser.h"
#include <iostream>
#include <string>

WellHandler::WellHandler()
{
    char TestArray[] = "I:/CS-307/Program/ProgramAssignment1/OilFieldData.xml";
    //std::cout << "Enter file location: ";
    //std::cin >> fileName;
    
    dataParserXML = new OilFieldDataParser(const_cast<const char*>(TestArray));
    displayClass = new DisplayClass();
    sensorReader = new SensorReader();
    
    // Creates the Wells
    for(int i = 0; i < dataParserXML->getWellCount(); i++)
    {
        AddWell();
    }

    // Delay until wells are in place.
    inputWindow = new InputWindow();
}

WellHandler::~WellHandler()
{
    delete displayClass;
    delete sensorReader;
    delete inputWindow;
}

void WellHandler::Update()
{
    bool bProgramStillRunning = true;
    
   while(bProgramStillRunning != false)
   {
       sensorReader->PrintSensorData(m_pSelectedWellHead);
       AddToSelectedWell(inputWindow->SelectWell().get());
       RemoveFromSelectedWell(inputWindow->RemoveSelectedWell().get());
       if(inputWindow->CheckTime())
       {
           bProgramStillRunning = false;
       }
   }
}

bool WellHandler::AddWell()
{
    WellClass* createWell = new WellClass(dataParserXML);
    WellClass* temp = m_pActiveWellHead;

    if(m_pActiveWellHead == nullptr)
    {
        m_pActiveWellHead = createWell;
        dataParserXML->getWellData(createWell->well_ID, createWell->wellOperator, &createWell->numberSensor);
        return true;
    }

    while (temp != nullptr)
    {
        if(temp->m_pNext == nullptr)
        {
            temp->m_pNext = createWell;
            dataParserXML->getWellData(createWell->well_ID, createWell->wellOperator, &createWell->numberSensor);
            return true;
        }
        temp = temp->m_pNext;
    }
    return false;
}

bool WellHandler::RemoveWell(char* Well_ID)
{
    WellClass* temp = m_pActiveWellHead;
    WellClass* back = nullptr;
    
    while (temp != nullptr)
    {   
        if(strcmp(temp->well_ID, Well_ID) == 0)
        {
            if(back != nullptr)
            {
                back->m_pNext = temp->m_pNext;
                temp->m_pNext = nullptr;
                delete temp;
                return true;
            }
            m_pActiveWellHead = temp->m_pNext;
            temp->m_pNext = nullptr;
            delete temp;
            return true;
        }
        back = temp;
        temp = temp->m_pNext;
    }
    return false;
}

WellClass* WellHandler::ReturnWell(char* Well_ID)
{
    WellClass* temp = m_pActiveWellHead;
    while(temp != nullptr)
    {
        if(strcmp(temp->well_ID, Well_ID) == 0)
        {
            return temp;
        }
        temp = temp->m_pNext;
    }
    return nullptr;
}

bool WellHandler::AddToSelectedWell(char* Well_ID)
{
    if(Well_ID == nullptr) return false;
    WellClass* temp = m_pActiveWellHead;
    WellClass* temp2 = m_pSelectedWellHead;
    
    while(temp != nullptr)
    {
        if(strcmp(Well_ID, temp->well_ID) == 0)
        {
            while(temp2 != nullptr)
            {
                if(temp2->m_pNext == nullptr)
                {
                    temp2->m_pNext = temp;
                    SelectSensor(temp);
                    return true;
                }
                temp2 = temp2->m_pNext;
            }
        }
        temp = temp->m_pNext;
    }
    
    return false;
}

bool WellHandler::RemoveFromSelectedWell(char* Well_ID)
{
    WellClass* temp = m_pSelectedWellHead;
    WellClass* back = nullptr;
    
    while(temp != nullptr)
    {
        if(strcmp(Well_ID, temp->well_ID) == 0)
        {
            if(back != nullptr)
            {
                back->m_pNext = temp->m_pNext;
                temp->m_pNext = nullptr;
                return true;
            }
            m_pActiveWellHead = temp->m_pNext;
            temp->m_pNext = nullptr;
            return true;
        }
        back = temp;
        temp = temp->m_pNext;
    }
    return false;
}

void WellHandler::SelectSensor(WellClass* well)
{
    int userChoice[5];
    int x = 0;
    
    std::cout << "Exit - 0" << std::endl;
    std::cout << "Bit Depth - 1" << std::endl;
    std::cout << "Hole Depth - 2" << std::endl;
    std::cout << "Rate of Penetration - 2" << std::endl;
    std::cout << "Pump Pressure - 3" << std::endl;
    std::cout << "Casing Pressure: - 4" << std::endl;
    std::cout << "Flow Out - 5" << std::endl;
    std::cout << "Torque Max - 6" << std::endl;
    std::cout << "Mud Pit Volume - 7" << std::endl;
    std::cout << "What selected sensor do you want to choose: " << std::endl;
    
    while(x < well->numberSensor)
    {
        std::cout << "Choose sensor: ";
        std::cin >> userChoice[x];
        std::cout << std::endl;
        x++;
    }

    well->well_sensor_handler->AddSensor(userChoice);
}