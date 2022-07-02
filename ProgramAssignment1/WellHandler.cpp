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
    std::cout << "Enter data file name, XML files only: ";
    std::cin >> fileName;
    
    dataParserXML = new OilFieldDataParser(const_cast<const char*>(fileName));
    displayClass = new DisplayClass();
    sensorReader = new SensorReader();
    inputWindow = new InputWindow();

    for(int i = 0; i < dataParserXML->getWellCount(); i++)
    {
        AddWell();
    }
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
    }

    while (temp != nullptr)
    {
        if(temp->m_pNext == nullptr)
        {
            temp->m_pNext = createWell;
        }
    }
    dataParserXML->getWellData(createWell->well_ID, createWell->wellOperator, &createWell->numberSensor);
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
            }
            else if(temp->m_pNext != nullptr)
            {
                m_pActiveWellHead = temp->m_pNext;
                temp->m_pNext = nullptr;
                delete temp;
            }
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

bool WellHandler::AddToSelectedWell()
{

    return false;
}

bool WellHandler::RemoveFromSelectedWell(char* Well_ID)
{
    
    return false;
}
