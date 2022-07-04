#include "WellSensorHandler.h"
#include "OilFieldDataParser.h"
#include "WellSensor.h"

WellSensorHandler::WellSensorHandler(char* Well_ID, OilFieldDataParser* parser, int &numberSensor)
{
    m_pHead = nullptr;
    
    for(int i = 0; i < numberSensor; i++)
    {
        WellSensor* sensor = new WellSensor();
        char sensorType[28];
        char className[28];
        char displayName[28];
        double minData = 0;
        double maxData = 0;
        char unitInfo[28];
        char unitAbbrev[28];
        
        parser->getSensorData(Well_ID, sensorType, className, displayName, &minData, &maxData, unitInfo, unitAbbrev);

        sensor->SetSensorType(sensorType);
        sensor->SetClassName(className);
        sensor->SetDisplayName(displayName);
        sensor->SetMinSensorData(minData);
        sensor->SetMaxSensorData(maxData);
        sensor->SetUnitInfo(unitInfo);
        sensor->SetUnitAbbrev(unitAbbrev);
        
        AddWellSensor(sensor);
    }
}

WellSensorHandler::~WellSensorHandler()
{
    WellSensor* sensorNow = m_pHead;
    WellSensor* sensorNext = m_pHead->next;
    
    while(sensorNow != nullptr)
    {
        sensorNext = sensorNow->next;
        delete sensorNow;
        sensorNow = sensorNext;
    }
}

void WellSensorHandler::printSensorData()
{
    const WellSensor* temp = m_pHead;
    while(temp != nullptr)
    {
        if(temp->isSelected)
        {
            std::cout << "Unit Info:\t" << temp->GetUnitInfo() << endl;
            std::cout << "Unit Abbreviation:\t" << temp->GetUnitAbbrev() << endl;
            std::cout << "Sensor Name:\t" << temp->GetDisplayName() << endl;
            std::cout << "------------------------Output Data------------------------" << endl;
            std::cout << std::endl << "Min Data\t" << temp->GetMinSensorData() << "\tMax Data:\t" << temp->GetMaxSensorData() << endl;
        }
    }
}

WellSensor* WellSensorHandler::GetWellSensors() const
{
    return m_pHead;
}

void WellSensorHandler::AddWellSensor(WellSensor* sensor)
{
    WellSensor* temp = m_pHead;

    if(m_pHead == nullptr)
    {
        m_pHead = sensor;
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