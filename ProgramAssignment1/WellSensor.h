#pragma once

enum SensorType { sensor_none, hole_depth, bit_depth, flow_out, rate_of_penetration, pump_penetration, torque_max, mud_pit_volume, casing_pressure };

class WellSensor
{
    float sensorData;
    SensorType sensorType;
public:
    WellSensor();
    ~WellSensor();

    // Getters
    float GetSensorData() const;
    SensorType GetSensorType() const;

    // Setters
    void SetSensorData(float DataValue);
    void SetSensorType(SensorType Type);
};
