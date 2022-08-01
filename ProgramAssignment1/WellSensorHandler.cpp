/****************************************
*
*	File: WellSensorHandler.cpp
*	Author: Tony A. Hardiman Jr.
*	Purpose: To do stuff.
*	Assignment: Programming Assignment 1
*	Declaration: This program is entirely my own work.
*
****************************************/

#include "WellSensorHandler.h"
#include <random>
#include "FOLLOWLINK_IFCHANGED.h"
#include "FOLLOWLINK_IFGREATER.h"
#include "OilFieldDataParser.h"
#include "RAND_MIN2MAX.h"
#include "STEPDEC_MAX2MIN.h"
#include "STEPINC_MIN2MAX.h"
#include "WellSensor.h"

WellSensorHandler::WellSensorHandler(std::vector<std::string*>* senTypes, OilFieldDataParser* parser, WellClass* owner)
{
    owning_object_ = owner;
    m_pHead = nullptr;
    SeedGen = 0;
    sensorReader = new SensorReader();
    NumberOfSensors = owner->numberSensor;

    // Create Sensors
    CreateSensorFromXML(senTypes, parser);
    
    // Set the total number of sensors.
    GetTotalNumberOfSensor();
}

WellSensorHandler::~WellSensorHandler()
{
    delete sensorReader;
    
    // Delete all the sensor in the linked list
    const WellSensor* sensorNow = m_pHead;
    const WellSensor* sensor_next = nullptr;
    while(sensorNow != nullptr)
    {
        sensor_next = sensorNow->next;
        delete sensorNow;
        sensorNow = sensor_next;
    }
}

void WellSensorHandler::CreateSensorFromXML(std::vector<std::string*>* senTypes, OilFieldDataParser* parser)
{
    // Create a map.
    CreateUserMap(senTypes);
    
    for(int i = 0; i < NumberOfSensors; i++)
    {
        WellSensor* sensor = new WellSensor();
        char sensorType[64] = "";
        strcpy_s(sensorType, (*senTypes)[i]->c_str());
        char className[64] = "";
        char displayName[64] = "";
        double minData = 0;
        double maxData = 0;
        double step = 0.;
        char unitInfo[64] = "";
        char unitAbbrev[64] = "";
        char dataGenAlg[64] = "";
        char linkSenType[64] = "";
        bool minUdf = false;
        bool maxUdf = false;
        
        parser->getSensorData(sensorType, className, displayName, &minData, &minUdf,
            &maxData, &maxUdf, &step, unitInfo, unitAbbrev, dataGenAlg, linkSenType);
        
        sensor->SetSensorType(sensorType);
        sensor->SetClassName(className);
        sensor->SetDisplayName(displayName);
        sensor->SetMinSensorData(minData);
        sensor->SetMaxSensorData(maxData);
        sensor->SetUnitInfo(unitInfo);
        sensor->SetUnitAbbrev(unitAbbrev);
        sensor->SetStepData(step);
        sensor->SetDataGenAlg(dataGenAlg);
        sensor->SetLinkSenType(FindWellSensor(linkSenType));
        sensor->SetMinUdf(minUdf);
        sensor->SetMaxUdf(maxUdf);
        SetSensorAlgorithm(sensor);
        
        AddWellSensor(sensor);
    }
}

bool WellSensorHandler::DeleteSensor(const char* SensorName)
{
    WellSensor* temp = m_pHead;
    WellSensor* back = nullptr;
    
    while(temp != nullptr)
    {
        if(strcmp(SensorName, temp->GetDisplayName()) == 0)
        {
            if(temp == m_pHead)
            {
                m_pHead = temp->next;
                temp->next = nullptr;
                delete temp;
                return true;
            }

            back->next = temp->next;
            temp->next = nullptr;
            delete temp;
            return true;
        }
        back = temp;
        temp = temp->next;
    }
    return false;
}

void WellSensorHandler::GetTotalNumberOfSensor()
{
    const WellSensor* temp = m_pHead;
    NumberOfSensors = 0;
    while(temp != nullptr)
    {
        NumberOfSensors++;
        temp = temp->next;
    }
}

void WellSensorHandler::printSensorData()
{
    WellSensor* temp = m_pHead;
    while(temp != nullptr)
    {
        if(temp->isSelected)
        {
            temp->ChangeSensorData();
            std::cout << "Sensor Name:\t" << temp->GetDisplayName() << std::endl;
            std::cout << "Unit Info:\t" << temp->GetUnitInfo() << std::endl;
            std::cout << "Current Data:\t"<< temp->GetCurrentData() << " " << temp->GetUnitAbbrev() << std::endl << std::endl;
        }
        temp = temp->next;
    }
}

void WellSensorHandler::SetWellSensorSelect(const char* Name, SensorSelection selection) const
{
    WellSensor* temp = m_pHead;

    while(temp != nullptr)
    {
        if(strcmp(temp->GetSensorType(), Name) == 0)
        {
            if(selection == sensor_add)
            {
                temp->isSelected = true;
            }
            else if(selection == sensor_remove)
            {
                temp->isSelected = false;
            }
            return;
        }
        temp = temp->next;
    }
}


WellSensor* WellSensorHandler::GetWellSensorsList() const
{
    return m_pHead;
}

void WellSensorHandler::AddWellSensor(WellSensor* sensor)
{
    WellSensor* temp = m_pHead;
    
    if(m_pHead == nullptr)
    {
        m_pHead = sensor;
        return;
    }
    
    while(temp != nullptr)
    {
        if(temp->next == nullptr)
        {
            temp->next = sensor;
            return;
        }
        temp = temp->next;
    }
}

SensorReader* WellSensorHandler::GetSensorReader() const
{
    return sensorReader;
}

void WellSensorHandler::SelectSensor()
{
    char userSelection = ' ';
    std::cout << "What do want to do to sensors? (A for Add | R for Remove)" << std::endl;
    std::cout << "Select: ";
    std::cin >> userSelection;
    if(userSelection == 'A' || userSelection == 'a')
    {
        sensorReader->SelectSensor(NumberOfSensors, m_pHead, this, sensor_add, userChoiceMap);
    }
    else if(userSelection == 'R' || userSelection == 'r')
    {
        sensorReader->SelectSensor(NumberOfSensors, m_pHead, this, sensor_remove, userChoiceMap);
    }
}

int WellSensorHandler::GetTotalNumberOfSensor() const
{
    return NumberOfSensors;
}

void WellSensorHandler::CallSensorReaderSelect()
{
    sensorReader->SelectSensor(NumberOfSensors, m_pHead, this, sensor_add, userChoiceMap);
}

void WellSensorHandler::SetSensorAlgorithm(WellSensor* Sensor)
{
    if(strcmp(Sensor->GetDataGenAlg(), "RAND_MIN2MAX") == 0)
    {
        Sensor->SetAlgorithm(new RAND_MIN2MAX());
        return;
    }

    if(strcmp(Sensor->GetDataGenAlg(), "STEPINC_MIN2MAX") == 0)
    {
        Sensor->SetAlgorithm(new STEPINC_MIN2MAX());
        return;
    }

    if(strcmp(Sensor->GetDataGenAlg(), "STEPDEC_MAX2MIN") == 0)
    {
        Sensor->SetAlgorithm(new STEPDEC_MAX2MIN());
        return;
    }

    if(strcmp(Sensor->GetDataGenAlg(), "FOLLOWLINK_IFGREATER") == 0)
    {
        Sensor->SetAlgorithm(new FOLLOWLINK_IFGREATER());
        return;
    }
    
    if(strcmp(Sensor->GetDataGenAlg(), "FOLLOWLINK_IFCHANGED") == 0)
    {
        Sensor->SetAlgorithm(new FOLLOWLINK_IFCHANGED());
    }
}

WellSensor* WellSensorHandler::FindWellSensor(const char* sensorType) const
{
    WellSensor* temp = m_pHead;
    while(temp != nullptr)
    {
        if(strcmp(temp->GetSensorType(), sensorType) == 0)
        {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

void WellSensorHandler::CreateUserMap(std::vector<std::string*>* senTypes)
{
    for(int i = 0; i < senTypes->size(); i++)
    {
        userChoiceMap.insert({(i + 1), (*senTypes)[i]->c_str()});
    }
}