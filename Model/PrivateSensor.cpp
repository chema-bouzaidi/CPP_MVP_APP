#include "PrivateSensor.h"
#include <cmath>
#include <vector>

PrivateSensor & PrivateSensor::operator=(const PrivateSensor& ps)
{
    if (this != &ps)
    {
        Sensor::operator=(ps);
        ownerId    = ps.ownerId;
        isReliable = ps.isReliable;
    }
    return *this;
}

PrivateSensor::PrivateSensor(const PrivateSensor& ps)
    : Sensor(ps), ownerId(ps.ownerId), isReliable(ps.isReliable) {}

PrivateSensor::PrivateSensor(std::string id, float lat, float lon,
                             std::string owner)
    : Sensor(id, lat, lon), ownerId(owner), isReliable(true) {}

PrivateSensor::PrivateSensor(std::string id, float lat, float lon)
    : Sensor(id, lat, lon), ownerId(""), isReliable(true) {}

PrivateSensor::PrivateSensor()
    : Sensor(), ownerId(""), isReliable(true) {}

PrivateSensor::~PrivateSensor() {}

void PrivateSensor::flagAsUnreliable()
{
    isReliable = false;
    isFunctional = false;
}

void PrivateSensor::removeAbberantData()
{
    // Remove measurements beyond 2σ for each attribute
    const std::string attrs[] = {"O3", "NO2", "SO2", "PM10"};
    for (const std::string& attr : attrs)
    {
        std::vector<float> vals;
        for (Measurement* m : measurements)
            if (m->getAttributeId() == attr)
                vals.push_back(m->getValue());

        if (vals.size() < 2) continue;

        float mean = 0;
        for (float v : vals) mean += v;
        mean /= static_cast<float>(vals.size());

        float var = 0;
        for (float v : vals) var += (v - mean) * (v - mean);
        float stddev = std::sqrt(var / static_cast<float>(vals.size()));

        measurements.remove_if([&](Measurement* m) {
            return m->getAttributeId() == attr &&
                   std::abs(m->getValue() - mean) > 2.0f * stddev;
        });
    }
}

std::string PrivateSensor::getOwnerId() const  { return ownerId; }
bool        PrivateSensor::getIsReliable() const { return isReliable; }
