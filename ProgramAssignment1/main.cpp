/****************************************
*
*	File: main.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: Entrance for the entire program.
*	Assignment: Programming Assignment 1
*	Declaration: This program is entirely my own work.
*
****************************************/

#include <iostream>
#include "WellHandler.h"

typedef std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> time_point;

int main(int argc, char* argv[])
{
    WellHandler* handler = WellHandler::getInstance();
    InputWindow* inputWindow = new InputWindow();
    bool bProgramStillRunning = true;
    int timeInterval = 5;
    auto nextTime = std::chrono::time_point_cast<time_point::duration>(std::chrono::system_clock::now() + std::chrono::seconds(timeInterval));
    
    // Start up functions.
    handler->SetInputWindow(inputWindow);
    handler->StartupFunction();
    
    // Main Loop
    while(bProgramStillRunning != false)
    {
        const auto currentTime = std::chrono::system_clock::now();
    
        // Print Well Data and Sensor Data for Wells. After next time.
        if(currentTime >= nextTime)
        {
            const WellClass* temp = handler->GetSelectedWellHead();
            while(temp != nullptr)
            {
                temp->printWellData();
                temp = temp->m_pNext;
            }
            nextTime = std::chrono::time_point_cast<time_point::duration>(std::chrono::system_clock::now() + std::chrono::seconds(timeInterval)); 
            std::cout << std::endl;
        }

        if(currentTime >= inputWindow->GetNextTime())
        {
            handler->RemoveSelectedWellLoop();
            handler->AddSelectedWellLoop();
            handler->SelectSensorLoop();
            if(inputWindow->CheckTime())
            {
                bProgramStillRunning = false;
            }
            std::cout << std::endl;
        }
    }

    delete inputWindow;
    delete handler;
    return 0;
}