#include "InputWindow.h"
#include <chrono>
#include <iostream>

typedef std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> time_point;

InputWindow::InputWindow()
{
    bool checkError = false;
    
    while(checkError == false)
    {
        std::cout << "What is seconds between check whether or not you want to quit? Default is 10 seconds." << std::endl;
        try
        {
            std::cin >> timeIntervals;
            checkError = true;
        }
        catch (...)
        {
            std::cout << "Error detected! Please enter a integer number only!" << std::endl;
        }
    }
}

InputWindow::~InputWindow()
{
}

bool InputWindow::CheckTime()
{
    const auto currentTime = std::chrono::system_clock::now();
    char userAnswer = ' ';
    
    if(currentTime >= nextTime)
    {
        std::cout << "Do you want to quit the program? (Y/N)";
        std::cin >> userAnswer;

        if(userAnswer == 'Y')
        {
            return true;
        }
    }
    nextTime = std::chrono::time_point_cast<time_point::duration>(std::chrono::system_clock::now() + std::chrono::seconds(timeIntervals)); 
    return false;
}


