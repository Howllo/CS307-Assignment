#include "InputWindow.h"
#include <iostream>
#include <string>

typedef std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> time_point;

InputWindow::InputWindow()
{
    bool checkError = false;
    char user_input[3];
    firstTime = true;
    
    while(checkError == false)
    {
        std::cout << "Time between asking for input in seconds: ";
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
    const auto currentTime = std::chrono::system_clock::now();
    std::unique_ptr<char[]> rWellID(new char[10]);
    if(currentTime > nextTime || firstTime == true)
    {
        firstTime = false;
        char CheckUser = ' ';
        std::cout << "Do you want to select a well? (Y/N): ";
        std::cin >> CheckUser;
        std::cout << std::endl;
        if(CheckUser == 'Y' || CheckUser == 'y')
        {
            GetWell(activeHead);
            char WellID[10];
            std::cout << "What well you want to selected?" << std::endl;\
            std::cin >> WellID;
            std::copy_n(WellID, 10, &rWellID[0]);
            return rWellID;
        }
    }
    return nullptr;
}

std::unique_ptr<char[]> InputWindow::RemoveSelectedWell(const WellClass* selectedHead)
{
    const auto currentTime = std::chrono::system_clock::now();
    std::unique_ptr<char[]> rWellID(new char[10]);
    if(currentTime > nextTime)
    {
        char CheckUser = ' ';
        std::cout << "Do you want to remove a well? (Y/N): ";
        std::cin >> CheckUser;
        std::cout << std::endl;
        if(CheckUser == 'Y' || CheckUser == 'y')
        {
            GetWell(selectedHead);
            char WellID[10];
            std::cout << "What well you want to selected?" << std::endl;
            std::cin >> WellID;
            std::copy_n(WellID, 10, &rWellID[0]);
            return rWellID;
        }
    }
    return nullptr;
}

void InputWindow::GetWell(const WellClass* head)
{
    const WellClass* temp = head;
    std::cout << std::endl << "Choose from these wells: " << std::endl;
    
    while (temp != nullptr)
    {
        std::cout << "Well: " << temp->well_ID << std::endl;
        temp = temp->m_pNext;
    }
}

std::unique_ptr<char[]> InputWindow::SensorSettings()
{
    const auto currentTime = std::chrono::system_clock::now();
    std::unique_ptr<char[]> rWellID(new char[10]);
    if(currentTime > nextTime)
    {
        char CheckUser = ' ';
        std::cout << "Do you want to change sensor setting? (Y/N): ";
        std::cin >> CheckUser;
        std::cout << std::endl;
        if(CheckUser == 'Y' || CheckUser == 'y')
        {
            char WellID[10];
            std::cout << "What well you want to selected?" << std::endl;
            std::cin >> WellID;
            std::copy_n(WellID, 10, &rWellID[0]);
            return rWellID;
        }
    }
    return nullptr;
}

std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds>& InputWindow::GetNextTime()
{
    return nextTime;
}
