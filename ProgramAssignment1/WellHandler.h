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
#include "InputWindow.h"
#include "SensorReader.h"

class WellHandler
{
    OilFieldDataParser* dataParserXML;
    SensorReader* sensorReader;
    InputWindow* inputWindow;
    char fileName[256];
    WellClass* m_pActiveWellHead;
    WellClass* m_pSelectedWellHead;
    int totalActiveWell;
 
public:
    WellHandler();
    ~WellHandler();

    /**
     * \brief Main loop for the entire program.
     */
    void Update();

    /**
     * \brief Used to create new wells.
     * \return Return a true boolean if it successfully creates a well, or returns false if it failed. 
     */
    bool CreateWell();

    /**
     * \brief Used for deleting wells from the program only.
     * \param Well_ID Takes in a Well_ID to delete the well from the program.
     * \return Return a true boolean if it successfully deletes a well, or returns false if it failed. 
     */
    bool DeleteWell(const char* Well_ID);

    /**
     * \brief This is used to add wells back to the active wells linked list.
     * \param Well Takes in a Well Class to add back to the active well linked list.
     * \return Return a true boolean if it successfully added a well, or returns false if it failed. 
     */
    bool AddActiveWell(WellClass* Well);

    /**
     * \brief Used to remove wells from the active well list and add it to the selected wells.
     * \param Well Takes in a WellClass to remove from the linked list. Used for comparison.
     * \return Return a true boolean if it successfully removed a well, or returns false if it failed. 
     */
    bool RemoveActiveWell(WellClass* Well);

    /**
     * \brief Used for adding wells to the selected well linked list.
     * \param WellID Takes in a character array of a Well ID to find the well within the selected well.
     * \return Return a true boolean if it successfully added a well, or returns false if it failed.
     */
    bool AddSelectedWell(char* WellID);

    /**
     * \brief Removes wells from the selected well linked list.
     * \param Well_ID Takes in a character array of a Well ID to find the well within the selected well.
     * \return Return a true boolean if it successfully removed a well, or returns false if it failed.
     */
    bool RemoveSelectedWell(char* Well_ID);

    /**
     * \brief Used to select and deselect sensors within a well.
     * \param Well_ID Takes in a well id to access the sensor data.
     */
    void Select_Sensor(char* Well_ID);
};