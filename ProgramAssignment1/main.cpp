/****************************************
*
*	File: Main.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: Entrance for the entire program.
*	Assignment: Programming Assignment 1
*	Declaration: This program is entirely my own work.
*
****************************************/

#include <iostream>

#include "WellHandler.h"

int main(int argc, char* argv[])
{
    WellHandler* handler = new WellHandler();

    std::cout << "Finished creating object." << std::endl;
    
    //Entrance to program.
    handler->Update();

    delete handler;
    return 0;
}