/****************************************
*
*	File: WellSensor.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: Handles all the functionality for the class WellSensor.h.
*	Assignment: Programming Assignment 1
*	Declaration: This program is entirely my own work.
*
****************************************/

#include "WellSensor.h"
#include <string>

WellSensor::WellSensor()
{
    minData = 0;
    maxData = 0;
    isSelected = false;
    next = nullptr;
    currentData = 0;
    step = 0;
    minUdf = false;
    maxUdf = false;
}

WellSensor::~WellSensor()
{
}

const char* WellSensor::GetSensorType() const
{
    return sensorType;
}

const char* WellSensor::GetClassName() const
{
    return className;
}

double WellSensor::GetMinSensorData() const
{
    return minData;
}

double WellSensor::GetMaxSensorData() const
{
    return maxData;
}

const char* WellSensor::GetDisplayName() const
{
    return displayName;
}

const char* WellSensor::GetUnitInfo() const
{
    return unitInfo;
}

const char* WellSensor::GetUnitAbbrev() const
{
    return unitAbbrev;
}

const char* WellSensor::GetDataGenAlg() const
{
    return dataGenAlg;
}

const char* WellSensor::GetLinkSenType() const
{
    return linkSentype;
}

double WellSensor::GetCurrentData() const
{
    return currentData;
}

double WellSensor::GetStepData() const
{
    return step;
}

bool WellSensor::GetMinUdf() const
{
    return minUdf;
}

bool WellSensor::GetMaxUdf() const
{
    return maxUdf;
}

AlgorithmStrategy* WellSensor::GetAlgorithm() const
{
    return algorithm_;
}

void WellSensor::SetCurrentData(const double data)
{
    currentData = data;
}

auto WellSensor::SetSensorType(const char* SensorType) -> void
{
    strcpy_s(sensorType, SensorType);
}

void WellSensor::SetClassName(const char* class_name)
{
    strcpy_s(className, class_name);
}

void WellSensor::SetMinSensorData(const double data_value)
{
    minData = data_value;
}

void WellSensor::SetMaxSensorData(const double data_value)
{
    maxData = data_value;
}

void WellSensor::SetDisplayName(const char* name)
{
    strcpy_s(displayName, name);
}

void WellSensor::SetUnitInfo(const char* Unit_Info)
{
    strcpy_s(unitInfo, Unit_Info);
}

void WellSensor::SetUnitAbbrev(const char* unit_abbrev)
{
    strcpy_s(unitAbbrev, unit_abbrev);
}

void WellSensor::SetDataGenAlg(const char* data_gen)
{
    strcpy_s(dataGenAlg, data_gen);
}

void WellSensor::SetLinkSenType(const char* link_sen_type)
{
    strcpy_s(linkSentype, link_sen_type);
}

void WellSensor::SetStepData(const double _step)
{
    step = _step;
}

void WellSensor::SetMinUdf(const bool udf)
{
    minUdf = udf;
}

void WellSensor::SetMaxUdf(const bool udf)
{
    maxUdf = udf;
}

void WellSensor::SetAlgorithm(AlgorithmStrategy* algorithm)
{
    algorithm_ = algorithm;
}