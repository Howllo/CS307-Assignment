#pragma once
#include <chrono>

class InputWindow
{
    int timeIntervals;
    
public:
    InputWindow();
    ~InputWindow();

    /**
     * \brief Check user for want to 
     * \return Return a true for wanting to quit program, or false for not wanting to quit.
     */
    bool CheckTime();
    std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> nextTime;
};
