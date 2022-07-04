#include "SensorReader.h"

#include "WellSensor.h"

typedef std::chrono::time_point<std::chrono::system_clock, std::chrono::seconds> time_point;

SensorReader::SensorReader()
{
    timeInterval = 5;
    nextTime = std::chrono::time_point_cast<time_point::duration>(std::chrono::system_clock::now() + std::chrono::seconds(timeInterval));
}

SensorReader::~SensorReader()
{
}

void SensorReader::PrintSensorData(WellClass* m_pSelectedHead)
{
    auto currentTime = std::chrono::system_clock::now();
    WellClass* temp = m_pSelectedHead;
    
    if(nextTime >= currentTime)
    {
        while (temp != nullptr)
        {
            
        }
    }
}

