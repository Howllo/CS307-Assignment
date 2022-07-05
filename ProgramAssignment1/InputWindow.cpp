#include "InputWindow.h"
#include <chrono>
#include <iostream>
#include <string>

typedef std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> time_point;

InputWindow::InputWindow()
{
    bool checkError = false;
    char user_input[3];
    
    while(checkError == false)
    {
        std::cout << "What is seconds between check whether or not you want to quit?" << std::endl;
        std::cout << "Default is 10 seconds: ";
        std::cin >> user_input;

        for(int i = 0; i < 3; i++)
        {
            if(!isdigit(user_input[i]))
                break;
            checkError = true;
        }
    }

    //Convert
    timeIntervals = std::stoi(user_input);
    
    nextTime = std::chrono::time_point_cast<time_point::duration>(std::chrono::system_clock::now() + std::chrono::seconds(timeIntervals)); 
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

std::unique_ptr<char[]> InputWindow::SelectWell()
{
    const auto currentTime = std::chrono::system_clock::now();
    std::unique_ptr<char[]> rWellID(new char[10]);
    if(currentTime > nextTime)
    {
        char WellID[10];
        std::cout << "What well you want to selected?" << std::endl;
        std::cin >> WellID;
        std::copy_n(WellID, 10, &rWellID[0]);
        return rWellID;
    }
    return rWellID;
}

std::unique_ptr<char[]> InputWindow::RemoveSelectedWell()
{
    const auto currentTime = std::chrono::system_clock::now();
    std::unique_ptr<char[]> rWellID(new char[10]);
    if(currentTime > nextTime)
    {
        char CheckUser = ' ';
        std::cout << "Do you want to remove a well?" << std::endl;
        std::cin >> CheckUser;
        if(CheckUser == 'Y' || CheckUser == 'y')
        {
            char WellID[10];
            std::cout << "What well you want to selected?" << std::endl;
            std::cin >> WellID;
            std::copy_n(WellID, 10, &rWellID[0]);
            return rWellID;
        }
    }
    return rWellID;
}

