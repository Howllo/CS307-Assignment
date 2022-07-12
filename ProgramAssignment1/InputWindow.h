#pragma once
#include <chrono>
#include "WellClass.h"
#include <memory>

class InputWindow
{
    int timeIntervals;
    bool firstTime;
 
    /**
     * \brief Used to get the next time for checking with the user.
     */
    std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> nextTime;

    /**
     * \brief Used to valid user input between user and the well ID.
     * \param input Takes in a character array from the user input to valid information.
     * \param head Takes in a linked list head to go through the list to validate information.
     * \return Returns a bool. True if the input and well exist, or false if there no well from user input.
     */
    bool ValidateUserInput(const char* input, const WellClass* head);
public:
    InputWindow();
    ~InputWindow();

    /**
     * \brief Check user for want to 
     * \return Return a true for wanting to quit program, or false for not wanting to quit.
     */
    bool CheckTime();

    /**
     * \brief Ask user for their input and returns that input.
     * \param activeHead Used only for GetWell.
     * \return Return a unique pointer of a character array type.
     */
    std::unique_ptr<char[]> SelectWell(const WellClass* activeHead);

    /**
     * \brief Used to get user input for removing Wells.
     * \param selectedHead Used only for the GetWell list.
     * \return Return unique_ptr of a character array type.
     */
    std::unique_ptr<char[]> RemoveSelectedWell(const WellClass* selectedHead);

    /**
     * \brief  Show all the wells within a linked list.
     * \param head Send any a linked list head that are WellClass.
     */
    void GetWell(const WellClass* head);

    /**
     * \brief Removes selected sensors from wells.
     * \param head Send any a linked list head that are WellClass.
     * \return Return unique_ptr of a character array type.
     */
    std::unique_ptr<char[]> SensorSettings(WellClass* head);

    /**
     * \brief Get the next time to get user input.
     * \return Return a reference to the next time variable from the chrono time object.
     */
    std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds>& GetNextTime();
};