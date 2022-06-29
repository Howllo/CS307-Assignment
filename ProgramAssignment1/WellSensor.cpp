#include "WellSensor.h"

WellSensor::WellSensor()
{
    sensorType = sensor_none;
    sensorData = 0;
}

WellSensor::~WellSensor()
{
}

float WellSensor::GetSensorData() const
{
    return sensorData;
}

SensorType WellSensor::GetSensorType() const
{
    return sensorType;
}

void WellSensor::SetSensorData(float DataValue)
{
    sensorData = DataValue;
}

void WellSensor::SetSensorType(SensorType Type)
{
    sensorType = Type;
}
