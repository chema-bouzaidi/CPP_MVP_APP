#if !defined(SENSOR_H)
#define SENSOR_H

#include <string>
#include <list>
#include "Measurement.h"
#include "../TypeUtil/Period.h"
#include "../TypeUtil/Coordinates.h"

class Sensor
{
public:
    std::list<Measurement> getMeasurements(const Period& periode) const;
    Coordinates getPosition() const;
    std::string getSensorId() const;
    bool getIsFunctional() const;
    void markDefective();
    void addMeasurement(Measurement* m);

    Sensor & operator=(const Sensor& s);
    Sensor(const Sensor& s);
    Sensor(std::string sensorId, float latitude, float longitude);
    Sensor();
    virtual ~Sensor();

protected:
    std::string sensorId;
    float latitude;
    float longitude;
    bool isFunctional;
    std::list<Measurement*> measurements;
};

#endif // SENSOR_H
