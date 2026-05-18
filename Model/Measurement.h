#ifndef MEASUREMENT_H
#define MEAASUREMENT_H

#include <string>
#include <ctime>
#include TimeStamp.h

using namespace std;

class Measurement {
    private :
        time_t timestamp;
        string sensorID;
        string attributeID;
        float value;
    public :
        //constructeur 
        Measurement(time_t timestamp,string sensorId, string attributeId,float value);
        float getValue();
        string getTimestamp();
        string getSensorId();
        string getAttributeId();
};
#endif
