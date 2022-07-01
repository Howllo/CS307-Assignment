#include "WellSensorHandler.h"

WellSensorHandler::WellSensorHandler(char* Well_ID, OilFieldDataParser* parser)
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

WellSensorHandler::~WellSensorHandler()
{
    
}

HoleDepth* WellSensorHandler::GetHoleDepth()
{
    return holeDepth;
}

BitDepth* WellSensorHandler::GetBitDepth()
{
    return bitDepth;
}

RateOfPenetration* WellSensorHandler::GetRateOfPenetration()
{
    return rateOfPenetration;
}

PumpPenetration* WellSensorHandler::GetPumpPenetration()
{
    return pumpPenetration;
}

CasingPressure* WellSensorHandler::GetCasingPressure()
{
    return casingPressure;
}

FlowOut* WellSensorHandler::GetFlowOut()
{
    return flowOut;
}

TorqueMax* WellSensorHandler::GetTorqueMax()
{
    return torqueMax;
}

MudPitVolume* WellSensorHandler::GetMudPtVolume()
{
    return mudPitVolume;
}

std::vector<WellSensor*> WellSensorHandler::GetExtraSensors()
{
    return extraSensor;
}

void WellSensorHandler::AddExtraSensors(WellSensor* Sensor)
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

void WellSensorHandler::SetHoleDepth(HoleDepth* hole_depth)
{
    holeDepth = hole_depth;
}

void WellSensorHandler::SetBitDepth(BitDepth* bit_depth)
{
    bitDepth = bit_depth;
}

void WellSensorHandler::SetRateOfPenetration(RateOfPenetration* rate_penetration)
{
    rateOfPenetration = rate_penetration;
}

void WellSensorHandler::SetPumpPenetration(PumpPenetration* pump_penetration)
{
    pumpPenetration = pump_penetration;
}

void WellSensorHandler::SetCasingPressure(CasingPressure* casing_pressure)
{
    casingPressure = casing_pressure;
}

void WellSensorHandler::SetFlowOut(FlowOut* flow_out)
{
    flowOut = flow_out;
}

void WellSensorHandler::SetTorqueMax(TorqueMax* torque_Max)
{
    torqueMax = torque_Max;
}

void WellSensorHandler::SetMudPitVolume(MudPitVolume* mud_pit_volume)
{
    mudPitVolume = mud_pit_volume;
}

void WellSensorHandler::SetOwner(WellClass* well_class)
{
    getOwner = well_class;
}
