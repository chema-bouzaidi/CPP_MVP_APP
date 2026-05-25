#include "Sensor.h"

Sensor & Sensor::operator=(const Sensor& s)
{
    if (this != &s)
    {
        sensorId     = s.sensorId;
        latitude     = s.latitude;
        longitude    = s.longitude;
        isFunctional = s.isFunctional;
    }
    return *this;
}

Sensor::Sensor(const Sensor& s)
    : sensorId(s.sensorId), latitude(s.latitude),
      longitude(s.longitude), isFunctional(s.isFunctional) {}

Sensor::Sensor(std::string id, float lat, float lon)
    : sensorId(id), latitude(lat), longitude(lon), isFunctional(true) {}

Sensor::Sensor()
    : sensorId(""), latitude(0.0f), longitude(0.0f), isFunctional(true) {}

Sensor::~Sensor() {}

std::list<Measurement> Sensor::getMeasurements(const Period& periode) const
{
    std::list<Measurement> result;
    for (Measurement* m : measurements)
    {
        if (periode.contains(m->getTimestamp()))
            result.push_back(*m);
    }
    return result;
}

Coordinates Sensor::getPosition() const
{
    return Coordinates(latitude, longitude);
}

std::string Sensor::getSensorId() const    { return sensorId; }
bool        Sensor::getIsFunctional() const { return isFunctional; }

void Sensor::markDefective()
{
    isFunctional = false;
}

void Sensor::addMeasurement(Measurement* m)
{
    measurements.push_back(m);
}
