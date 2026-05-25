#include "Measurement.h"

Measurement::Measurement(const TimeStamp& ts, const std::string& sId,
                         const std::string& aId, float v)
    : timestamp(ts), sensorId(sId), attributeId(aId), value(v) {}

Measurement::Measurement()
    : timestamp(), sensorId(""), attributeId(""), value(0.0f) {}

TimeStamp   Measurement::getTimestamp()   const { return timestamp; }
std::string Measurement::getSensorId()    const { return sensorId; }
std::string Measurement::getAttributeId() const { return attributeId; }
float       Measurement::getValue()       const { return value; }
