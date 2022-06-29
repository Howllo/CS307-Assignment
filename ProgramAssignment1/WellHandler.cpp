/****************************************
*
*	File: WellHandler.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: Handles all the functionality for the class WellHandler.h.
*	Assignment: Programming Assignment 1
*	Declaration: This program is entirely my own work.
*
****************************************/

#include "WellHandler.h"

WellHandler::WellHandler()
{
    holeDepth = nullptr;
    bitDepth = nullptr;
    rateOfPenetration = nullptr;
    pumpPenetration = nullptr;
    casingPressure = nullptr;
    flowOut = nullptr;
    torqueMax = nullptr;
    mudPitVolume = nullptr;
    extraSensor.resize(3);

    // Set the elements to nullptr.
    for(int i = 0; i < extraSensor.size(); i++)
    {
        extraSensor[i] = nullptr;
    }
}

WellHandler::~WellHandler()
= default;

HoleDepth* WellHandler::GetHoleDepth()
{
    return holeDepth;
}

BitDepth* WellHandler::GetBitDepth()
{
    return bitDepth;
}

RateOfPenetration* WellHandler::GetRateOfPenetration()
{
    return rateOfPenetration;
}

PumpPenetration* WellHandler::GetPumpPenetration()
{
    return pumpPenetration;
}

CasingPressure* WellHandler::GetCasingPressure()
{
    return casingPressure;
}

FlowOut* WellHandler::GetFlowOut()
{
    return flowOut;
}

TorqueMax* WellHandler::GetTorqueMax()
{
    return torqueMax;
}

MudPitVolume* WellHandler::GetMudPtVolume()
{
    return mudPitVolume;
}

std::vector<WellSensor*> WellHandler::GetExtraSensors()
{
    return extraSensor;
}

void WellHandler::AddExtraSensors(WellSensor* Sensor)
{
    for(int i = 0; i < extraSensor.size(); i++)
    {
        if(extraSensor[i] == nullptr)
        {
            extraSensor[i] = Sensor;
            return;
        }
    }

    // If there is no open slots resize the array based on the size plus one. Add the sensor on the end.
    extraSensor.resize( extraSensor.size() + 1 );
    extraSensor.push_back(Sensor);
}

void WellHandler::SetHoleDepth(HoleDepth* hole_depth)
{
    holeDepth = hole_depth;
}

void WellHandler::SetBitDepth(BitDepth* bit_depth)
{
    bitDepth = bit_depth;
}

void WellHandler::SetRateOfPenetration(RateOfPenetration* rate_penetration)
{
    rateOfPenetration = rate_penetration;
}

void WellHandler::SetPumpPenetration(PumpPenetration* pump_penetration)
{
    pumpPenetration = pump_penetration;
}

void WellHandler::SetCasingPressure(CasingPressure* casing_pressure)
{
    casingPressure = casing_pressure;
}

void WellHandler::SetFlowOut(FlowOut* flow_out)
{
    flowOut = flow_out;
}

void WellHandler::SetTorqueMax(TorqueMax* torque_Max)
{
    torqueMax = torque_Max;
}

void WellHandler::SetMudPitVolume(MudPitVolume* mud_pit_volume)
{
    mudPitVolume = mud_pit_volume;
}

