#if !defined(PRIVATE_SENSOR_H)
#define PRIVATE_SENSOR_H

#include <string>
#include "Sensor.h"

class PrivateSensor : public Sensor
{
public:
    void flagAsUnreliable();
    void removeAbberantData();

    std::string getOwnerId() const;
    bool getIsReliable() const;

    PrivateSensor & operator=(const PrivateSensor& ps);
    PrivateSensor(const PrivateSensor& ps);
    PrivateSensor(std::string sensorId, float latitude, float longitude,
                  std::string ownerId);
    PrivateSensor(std::string sensorId, float latitude, float longitude);
    PrivateSensor();
    virtual ~PrivateSensor();

protected:
    std::string ownerId;
    bool isReliable;
};

#endif // PRIVATE_SENSOR_H
