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
#include "AlgorithmStrategy.h"

class WellSensor
{
    char sensorType[64] = "";
    char className[64] = "";
    double minData;
    double maxData;
    double currentData;
    double step;
    char displayName[64] = "";
    char unitInfo[64] = "";
    char unitAbbrev[64] = "";
    char dataGenAlg[64] = "";
    bool minUdf;
    bool maxUdf;
    WellSensor* linkedSensor;
    AlgorithmStrategy* algorithm_;
public:
    WellSensor();
    ~WellSensor();

    // Variable
    bool isSelected;
    WellSensor* next;

    /**
     * \brief Changes the current data within the sensor.
     */
    void ChangeSensorData();
    
    // Getters
    const char* GetSensorType() const;
    const char* GetClassName() const;
    const char* GetDisplayName() const;
    double GetMinSensorData() const;
    double GetMaxSensorData() const;
    const char* GetUnitInfo() const;
    const char* GetUnitAbbrev() const;
    const char* GetDataGenAlg() const;
    WellSensor* GetLinkSenType() const;
    double GetCurrentData() const;
    double GetStepData() const;
    bool GetMinUdf() const;
    bool GetMaxUdf() const;
    AlgorithmStrategy* GetAlgorithm() const;
    
    // Setters
    void SetSensorType(const char* SensorType);
    void SetClassName(const char* class_name);
    void SetDisplayName(const char* name);
    void SetMinSensorData(double data_value);
    void SetMaxSensorData(double data_value);
    void SetUnitInfo(const char* Unit_Info);
    void SetUnitAbbrev(const char* unit_abbrev);
    void SetDataGenAlg(const char* data_gen);
    void SetLinkSenType(WellSensor* link_sen_type);
    void SetCurrentData(double data);
    void SetStepData(double _step);
    void SetMinUdf(bool udf);
    void SetMaxUdf(bool udf);
    void SetAlgorithm(AlgorithmStrategy* algorithm);
};