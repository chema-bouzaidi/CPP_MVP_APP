#include "Measurement.h"
Measurement::Measurement(time_t timestamp,string sensorId,string asstributeId, float value){
    this->timestamp = timestamp:
    this->sensorID = sensorId;
    this->attributeID = attributeId;

}

float Measurement::getValue() {
    return value;
}

time_t Measurement::getTimestamp() {
    return timestamp;
}

string Measurement::getSensorId() {
    return sensorID;
}

string Measurement::getAttributeId() {
    return attributeID;
}