/****************************************
*
*	File: WellSensor.h
*	Author: Tony A. Hardiman Jr.
*	Purpose: Holder file for all the function that the class will be using. This is the superclass.
*	Assignment: Programming Assignment 1
*	Declaration: This program is entirely my own work.
*
****************************************/

#pragma once

enum SensorType { sensor_none, hole_depth, bit_depth, flow_out, rate_of_penetration, pump_penetration, torque_max, mud_pit_volume, casing_pressure };

class WellSensor
{
    double minData;
    double maxData;
    char unitInfo[28];
    char unitAbbrev[10];
    char displayName[8];
    SensorType sensorType;
    WellSensor* next;
public:
    WellSensor();
    ~WellSensor();

    // Getters
    double GetMinSensorData() const;
    double GetMaxSensorData() const;
    const char* GetUnitInfo() const;
    const char* GetUnitAbbrev() const;
    const char* GetDisplayName() const;
    SensorType GetSensorType() const;
    
    // Setters
    void SetMinSensorData(double DataValue);
    void SetMaxSensorData(double DataValue);
    void SetUnitInfo(char* Unit_Info);
    void SetUnitAbbrev(char* Unit_Abbrev);
    void SetDisplayName(char* Name);
    void SetSensorType(SensorType Type);
};
