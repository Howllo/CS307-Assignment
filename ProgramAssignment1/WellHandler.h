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

enum type_well { active_well, selected_well };

class WellHandler
{
    OilFieldDataParser* dataParserXML;
    InputWindow* inputWindow;
    char fileName[256] = "";
    WellClass* m_pActiveWellHead;
    WellClass* m_pSelectedWellHead;

    // Private constructor.
    WellHandler();
public:
    // Destructor
    ~WellHandler();
    
    /**
     * \brief Singleton pattern for the handler class.
     * \return Returns a new created instance, or instance of itself.
     */
    static WellHandler* getInstance();

    /**
     * \brief Used to create new wells.
     * \return Return a true boolean if it successfully creates a well, or returns false if it failed. 
     */
    bool CreateWellFromXML();

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
    bool AddActiveWell(WellClass* Well) const;

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
    bool AddSelectedWell(const char* WellID);

    /**
     * \brief Removes wells from the selected well linked list.
     * \param Well_ID Takes in a character array of a Well ID to find the well within the selected well.
     * \return Return a true boolean if it successfully removed a well, or returns false if it failed.
     */
    bool RemoveSelectedWell(char* Well_ID);

    /**
     * \brief Used to get well from a well id.
     * \param Well_ID Uses character array to get the well.
     * \return Returns a WellClass.
     */
    WellClass* GetWell(char* Well_ID);
    
    /**
     * \brief Creates better readability in Update Function.
     */
    void StartupFunction();

    /**
     * \brief Loops until user exits, or no more wells to select.
     */
    void AddSelectedWellLoop();

    /**
     * \brief Loop until user exits, or no more wells to remove.
     */
    void RemoveSelectedWellLoop();

    /**
     * \brief Loop until user exits, or no more sensor to select.
     */
    void SelectSensorLoop();

    /**
     * \brief Used to set input window within this class.
     * \param input Takes in outside input window class to set input of this class.
     */
    void SetInputWindow(InputWindow* input);

    /**
     * \brief Used to get the active well linked list.
     * \return Returns the active well linked list.
     */
    WellClass* GetActiveWellHead();

    /**
     * \brief Used to get the selected  well linked list.
     * \return Returns the selected well linked list.
     */
    WellClass* GetSelectedWellHead();
    
    /**
     * \brief Used to get the current amount of wells that are selected.
     * \param Type Takes in a enum of active_well or selected_well for conditionals.
     * \return Returns the total amount of selected wells as a int.
     */
    int GetTotalWellNumbers(type_well Type);
};