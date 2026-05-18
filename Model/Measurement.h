#ifndef MEASUREMENT_H
#define MEASUREMENT_H

#include <string>
#include "../TypeUtil/TimeStamp.h"

class Measurement
{
private:
    TimeStamp timestamp;
    std::string sensorId;
    std::string attributeId;
    float value;
public:
    Measurement(const TimeStamp& ts, const std::string& sensorId,
                const std::string& attributeId, float value);
    Measurement();

    TimeStamp   getTimestamp()   const;
    std::string getSensorId()    const;
    std::string getAttributeId() const;
    float       getValue()       const;
};

#endif // MEASUREMENT_H
