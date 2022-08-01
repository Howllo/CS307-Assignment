/****************************************
*
*	File: InputWindow.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: To do stuff.
*	Assignment: Programming Assignment 1
*	Declaration: This program is entirely my own work.
*
****************************************/

#include "InputWindow.h"
#include <iostream>
#include <string>

typedef std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> time_point;

InputWindow::InputWindow()
{
    bool checkError = false;
    char user_input[3];
    firstTime = true;

    std::cout << "Time between asking for input in seconds: ";
    std::cin >> user_input;
    std::cout << std::endl;

    for(int i = 0; i < 3; i++)
    {
        if(!isdigit(user_input[i]))
            break;
        checkError = true;
    }
    
    while(checkError == false)
    {
        std::cout << "Error! Time in the integer seconds: ";
        std::cin >> user_input;
        std::cout << std::endl;

        for(int i = 0; i < 3; i++)
        {
            if(!isdigit(user_input[i]))
                break;
            checkError = true;
        }
    }

    //Convert
    timeIntervals = std::stoi(user_input);

    //Set Next Time.
    nextTime = std::chrono::time_point_cast<time_point::duration>(std::chrono::system_clock::now() + std::chrono::seconds(15)); 
}

InputWindow::~InputWindow()
{
}

bool InputWindow::CheckTime()
{
    const auto currentTime = std::chrono::system_clock::now();
    
    if(currentTime >= nextTime)
    {
        char userAnswer[3];
        
        std::cout << "Do you want to quit the program? (Y/N): ";
        std::cin >> userAnswer;

        if(userAnswer[0] == 'Y' || userAnswer[0] == 'y')
        {
            return true;
        }
    } else
    {
        return false;
    }
    nextTime = std::chrono::time_point_cast<time_point::duration>(std::chrono::system_clock::now() + std::chrono::seconds(timeIntervals)); 
    return false;
}

std::unique_ptr<char[]> InputWindow::SelectWell(const WellClass* activeHead)
{
    if(activeHead == nullptr) return nullptr;
    const auto currentTime = std::chrono::system_clock::now();
    
    if(currentTime > nextTime || firstTime == true)
    {
        std::unique_ptr<char[]> rWellID(new char[10]);
        bool input_validation = false;
        while(input_validation == false)
        {
            GetWell(activeHead);
            char WellID[10];
            std::cout << "What well do you want to selected?" << std::endl;
            std::cout << "Select: ";
            std::cin >> WellID;
            std::copy_n(WellID, 10, &rWellID[0]);
            input_validation = ValidateUserInput(WellID, activeHead);
        }
    }
    return nullptr;
}

std::unique_ptr<char[]> InputWindow::RemoveSelectedWell(const WellClass* selectedHead)
{
    const auto currentTime = std::chrono::system_clock::now();
    if(currentTime > nextTime)
    {
        std::unique_ptr<char[]> rWellID(new char[10]);
        bool input_validate = false;
        while(input_validate == false)
        {
            GetWell(selectedHead);
            char WellID[10];
            std::cout << "What well do you want to remove from selection?" << std::endl;
            std::cout << "Select: ";
            std::cin >> WellID;
            std::copy_n(WellID, 10, &rWellID[0]);
            input_validate = ValidateUserInput(WellID, selectedHead);
        }
        return rWellID;
    }
    return nullptr;
}

std::unique_ptr<char[]> InputWindow::SensorSettings(WellClass* head)
{
    const auto currentTime = std::chrono::system_clock::now();
    if(currentTime > nextTime)
    {
        std::unique_ptr<char[]> rWellID(new char[10]);
        bool input_validation = false;
        while(input_validation == false)
        {
            char WellID[10];
            GetWell(head);
            std::cout << "What well you want to selected?" << std::endl;
            std::cout << "Select: ";
            std::cin >> WellID;
            std::copy_n(WellID, 10, &rWellID[0]);
            input_validation = ValidateUserInput(WellID, head);
        }
        return rWellID;
    }
    return nullptr;
}

void InputWindow::GetWell(const WellClass* head)
{
    const WellClass* temp = head;
    std::cout << std::endl << "Choose from these well(s): " << std::endl;
    
    while (temp != nullptr)
    {
        std::cout << "Well: " << temp->well_ID << std::endl;
        temp = temp->m_pNext;
    }
}


std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds>& InputWindow::GetNextTime()
{
    return nextTime;
}

bool InputWindow::ValidateUserInput(const char* input, const WellClass* head)
{
    const WellClass* temp = head;

    while(temp != nullptr)
    {
        if(strcmp(temp->well_ID, input) == 0)
        {
            return true;
        }
        temp = temp->m_pNext;
    }
    return false;
}