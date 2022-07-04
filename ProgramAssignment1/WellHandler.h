/****************************************
*
*	File: WellHandler.h
*	Author: Tony A. Hardiman Jr.
*	Purpose: Holder file for all the function that the class will be using.
*	Assignment: Programming Assignment 1
*	Declaration: This program is entirely my own work.
*
****************************************/

#pragma once
#include "DisplayClass.h"
#include "InputWindow.h"
#include "SensorReader.h"

class WellHandler
{
    OilFieldDataParser* dataParserXML;
    DisplayClass* displayClass;
    SensorReader* sensorReader;
    InputWindow* inputWindow;
    char fileName[128];
    WellClass* m_pActiveWellHead;
    WellClass* m_pSelectedWellHead;
    
public:
    WellHandler();
    ~WellHandler();

    /**
     * \brief Where the program actually runs from.
     */
    void Update();

    // Active Well Linked List
    bool AddWell();
    bool RemoveWell(char* Well_ID);
    WellClass* ReturnWell(char* Well_ID);

    //Selected Well Linked List
    bool AddToSelectedWell();
    bool RemoveFromSelectedWell(char* Well_ID);
};
