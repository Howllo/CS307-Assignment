/****************************************
*
*	File: WellHandler.h
*	Author: Tony A. Hardiman Jr.
*	Purpose: Holder file for all the function that the class will be using.
*	Assignment: Programming Assignment 1
*	Declaration: This program is entirely my own work.
*
****************************************/

#pragma once

#include <vector>
#include "BitDepth.h"
#include "CasingPressure.h"
#include "FlowOut.h"
#include "HoleDepth.h"
#include "MudPitVolume.h"
#include "PumpPenetration.h"
#include "RateOfPenetration.h"
#include "TorqueMax.h"
#include "WellSensor.h"

class WellHandler
{
private:
    HoleDepth* holeDepth;
    BitDepth* bitDepth;
    RateOfPenetration* rateOfPenetration;
    PumpPenetration* pumpPenetration;
    CasingPressure* casingPressure;
    FlowOut* flowOut;
    TorqueMax* torqueMax;
    MudPitVolume* mudPitVolume;

    // Any extra sensor will be based on the parent class. Set to default 3.
    std::vector<WellSensor*> extraSensor;
public:
    WellHandler();
    ~WellHandler();

    /**
     * \brief Return sensor class from the well.
     * \tparam T Template is based on child objects of the superclass WellSensor.
     * \param Type Uses sensor type enum to return the right type of class.
     * \return Return child classes of WellSensor superclass.
     */
    template<class T>
    T* ReturnSensorClass(const SensorType Type)
    {
        switch (Type)
        {
            case hole_depth:
                return holeDepth;
            case bit_depth:
                return bitDepth;
            case rate_of_penetration:
                return rateOfPenetration;
            case pump_penetration:
                return pumpPenetration;
            case casingPressure:
                return casingPressure;
            case flow_out:
                return flowOut;
            case torque_max:
                return torqueMax;
            default:
                break;
        }
        return nullptr;
    }
private:
    // Getter
    HoleDepth* GetHoleDepth();
    BitDepth* GetBitDepth();
    RateOfPenetration* GetRateOfPenetration();
    PumpPenetration* GetPumpPenetration();
    CasingPressure* GetCasingPressure();
    FlowOut* GetFlowOut();
    TorqueMax* GetTorqueMax();
    MudPitVolume* GetMudPtVolume();
    std::vector<WellSensor*> GetExtraSensors();

    // Setters
    void SetHoleDepth(HoleDepth* hole_depth);
    void SetBitDepth(BitDepth* bit_depth);
    void SetRateOfPenetration(RateOfPenetration* rate_penetration);
    void SetPumpPenetration(PumpPenetration* pump_penetration);
    void SetCasingPressure(CasingPressure*casing_pressure);
    void SetFlowOut(FlowOut* flow_out);
    void SetTorqueMax(TorqueMax* torque_Max);
    void SetMudPitVolume(MudPitVolume* mud_pit_volume);
    void AddExtraSensors(WellSensor* Sensor);
};
