#include "WellSensorHandler.h"
#include <random>
#include "OilFieldDataParser.h"
#include "WellSensor.h"

WellSensorHandler::WellSensorHandler(char* Well_ID, OilFieldDataParser* parser, int numberSensor)
{
    m_pHead = nullptr;
    SeedGen = 0;
    
    for(int i = 0; i < numberSensor; i++)
    {
        WellSensor* sensor = new WellSensor();
        char sensorType[64] = "";
        char className[64] = "";
        char displayName[64] = "";
        double minData = 0;
        double maxData = 0;
        char unitInfo[64] = "";
        char unitAbbrev[64] = "";
        
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
    WellSensor* sensor_next = nullptr;
    
    while(sensorNow != nullptr)
    {
        sensor_next = sensorNow->next;
        delete sensorNow;
        sensorNow = sensor_next;
    }
}

void WellSensorHandler::printSensorData()
{
    const WellSensor* temp = m_pHead;
    ChangeSensorData();
    while(temp != nullptr)
    {
        if(temp->isSelected)
        {
            std::cout << "Sensor Name:\t" << temp->GetDisplayName() << endl;
            std::cout << "Unit Info:\t" << temp->GetUnitInfo() << endl;
            std::cout << "Current Data:\t"<< temp->GetCurrentData() << " " << temp->GetUnitAbbrev() << endl << endl;
        }
        temp = temp->next;
    }
}

void WellSensorHandler::SelectSensor(int Sensor , SensorSelection selection)
{
    switch(Sensor)
    {
        case 1:
            SetWellSensorSelect("BIT_DEPTH", selection);
            break;
        case 2:
            SetWellSensorSelect("HOLE_DEPTH", selection);
            break;
        case 3:
            SetWellSensorSelect("RATE_OF_PENETRATION", selection);
            break;
        case 4:
            SetWellSensorSelect("PUMP_PRESSURE", selection);
            break;
        case 5:
            SetWellSensorSelect("CASING_PRESSURE", selection);
            break;
        case 6:
            SetWellSensorSelect("FLOW_OUT", selection);
            break;
        case 7:
            SetWellSensorSelect("TORQUE_MAX", selection);
            break;
        case 8:
            SetWellSensorSelect("MUD_PIT_VOLUME", selection);
            break;
        default:
            break;
    }
}

void WellSensorHandler::ChangeSensorData()
{
    WellSensor* temp = m_pHead;
    while(temp != nullptr)
    {
        //Infinite Power
        if(SeedGen == LONG_MAX)
            SeedGen = 0;
        
        double MaxData = 0;
        double MinData = 0;
        if(strcmp(temp->GetClassName(), "SensorBitDepth") == 0 || strcmp(temp->GetClassName(), "SensorHoleDepth") == 0)
        {
            MinData = temp->GetMinSensorData();
            MaxData = 7000;
        }
        else
        {
            MinData = temp->GetMinSensorData(); 
            MaxData = temp->GetMaxSensorData();
        }

        // Randomize
        default_random_engine totalRand(SeedGen);
        uniform_int_distribution<int> RandomNum(((int)MinData), ((int)MaxData));
        temp->SetCurrentData(RandomNum(totalRand));
        temp = temp->next;
        SeedGen++;
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