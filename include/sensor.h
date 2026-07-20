#pragma once

#include <optional>
#include <fstream>
#include <string>
#include "sensorReading.h"

class Sensor {
public:
    Sensor(std::string& filename);
    std::optional<SensorReading> readNext();
private:
    std::ifstream file;
};
