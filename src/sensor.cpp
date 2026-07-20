#include "sensor.h"
#include <sstream>

Sensor::Sensor(std::string& filename) : file(filename) {
    if(!file.is_open()) {
        throw std::runtime_error("could not open sensor data file: " + filename);
    }
}

std::optional<SensorReading> Sensor::readNext() {
    std::string line;
    if(!std::getline(file, line)) {
        return std::nullopt;
    }
    std::istringstream iss(line);
    SensorReading reading;

    iss >> reading.objID >> reading.x >> reading.y >> reading.timestamp;
    return reading;
}
