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
    char sensorType[28];
    char className[28];
    double minData;
    double maxData;
    char displayName[28];
    char unitInfo[28];
    char unitAbbrev[28];
    
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
    
    // Setters
    void SetSensorType(char* SensorType);
    void SetClassName(char* ClassName);
    void SetDisplayName(char* Name);
    void SetMinSensorData(double DataValue);
    void SetMaxSensorData(double DataValue);
    void SetUnitInfo(char* Unit_Info);
    void SetUnitAbbrev(char* Unit_Abbrev);
};
