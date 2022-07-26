#include "WellSensorHandler.h"
#include <random>

#include "FOLLOWLINK_IFCHANGED.h"
#include "FOLLOWLINK_IFGREATER.h"
#include "OilFieldDataParser.h"
#include "RAND_MIN2MAX.h"
#include "STEPDEC_MAX2MIN.h"
#include "STEPINC_MIN2MAX.h"
#include "WellSensor.h"

WellSensorHandler::WellSensorHandler(char* Well_ID, OilFieldDataParser* parser, int numberSensor)
{
    m_pHead = nullptr;
    SeedGen = 0;
    sensorReader = new SensorReader();
    NumberOfSensors = numberSensor;

    // Create Sensors
    CreateSensorFromXML(Well_ID, parser);
    
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

void WellSensorHandler::CreateSensorFromXML(char* Well_ID, OilFieldDataParser* parser)
{
    for(int i = 0; i < NumberOfSensors; i++)
    {
        WellSensor* sensor = new WellSensor();
        char sensorType[64] = "";
        char className[64] = "";
        char displayName[64] = "";
        double minData = 0;
        double maxData = 0;
        double step;
        char unitInfo[64] = "";
        char unitAbbrev[64] = "";
        char dataGenAlg[64] = "";
        char linkSenType[64] = "";
        bool minUdf;
        bool maxUdf;
        
        parser->getSensorData(sensorType, className, displayName, &minData, &minUdf,
            &maxData, &maxUdf, &step, unitInfo, unitAbbrev, dataGenAlg, linkSenType);
        
        sensor->SetSensorType(sensorType);
        sensor->SetClassName(className);
        sensor->SetDisplayName(displayName);
        sensor->SetMinSensorData(minData);
        sensor->SetMaxSensorData(maxData);
        sensor->SetUnitInfo(unitInfo);
        sensor->SetUnitAbbrev(unitAbbrev);
        
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


//TODO: Rework this. Need to be dynamic.
void WellSensorHandler::UserInputProcessor(int Sensor, SensorSelection selection)
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

void WellSensorHandler::SelectSensor(const char* Well_ID)
{
    char userSelection = ' ';
    std::cout << "What do want to do to sensors? (A for Add | R for Remove)" << std::endl;
    std::cout << "Select: ";
    std::cin >> userSelection;
    if(userSelection == 'A' || userSelection == 'a')
    {
        sensorReader->SelectSensor(NumberOfSensors, m_pHead, this, sensor_add);
    }
    else if(userSelection == 'R' || userSelection == 'r')
    {
        sensorReader->SelectSensor(NumberOfSensors, m_pHead, this, sensor_remove);
    }
}

int WellSensorHandler::GetTotalNumberOfSensor() const
{
    return NumberOfSensors;
}

void WellSensorHandler::CallSensorReaderSelect()
{
    sensorReader->SelectSensor(NumberOfSensors, m_pHead, this, sensor_add);
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
