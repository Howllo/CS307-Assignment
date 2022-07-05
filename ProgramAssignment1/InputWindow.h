#pragma once
#include <chrono>
#include <memory>

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

    std::unique_ptr<char[]> SelectWell();
    std::unique_ptr<char[]> RemoveSelectedWell();
    
    std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> nextTime;
};
