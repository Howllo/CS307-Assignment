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

class WellSensor
{
    char sensorType[64] = "";
    char className[64] = "";
    double minData;
    double maxData;
    double currentData;
    char displayName[64] = "";
    char unitInfo[64] = "";
    char unitAbbrev[64] = "";
    
public:
    WellSensor();
    ~WellSensor();

    // Variable
    bool isSelected;
    WellSensor* next;
    
    // Getters
    const char* GetSensorType() const;
    const char* GetClassName() const;
    const char* GetDisplayName() const;
    double GetMinSensorData() const;
    double GetMaxSensorData() const;
    const char* GetUnitInfo() const;
    const char* GetUnitAbbrev() const;
    double GetCurrentData() const;
    
    // Setters
    void SetSensorType(char* SensorType);
    void SetClassName(char* ClassName);
    void SetDisplayName(char* Name);
    void SetMinSensorData(double DataValue);
    void SetMaxSensorData(double DataValue);
    void SetUnitInfo(char* Unit_Info);
    void SetUnitAbbrev(char* Unit_Abbrev);
    void SetCurrentData(double Data);
};
