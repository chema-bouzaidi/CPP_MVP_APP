#ifndef AIRQUALITYCALCULATOR_H
#define AIRQUALITYCALCULATOR_H

#include <list>
#include <string>
#include "Measurement.h"
#include "Sensor.h"
#include "Cleaner.h"
#include "../TypeUtil/Coordinates.h"
#include "../TypeUtil/Period.h"

class AirQualityCalculator
{
public:
    AirQualityCalculator();
    ~AirQualityCalculator();

    // Compute ATMO index (1–10) from a set of measurements
    int computeATMO(const std::list<Measurement*>& measurements) const;

    // Average ATMO index for all sensors within radius (km) of center during period
    float computeAverageQuality(const std::list<Sensor*>& sensors,
                                const std::list<Measurement*>& allMeasurements,
                                const Coordinates& center, float radius,
                                const Period& period) const;

    // Air quality improvement (ATMO difference) due to a cleaner
    float computeCleanerImpact(const Cleaner& cleaner,
                               const std::list<Sensor*>& sensors,
                               const std::list<Measurement*>& allMeasurements) const;

    // Effective cleaned radius (km) around a cleaner
    float computeCleanedRadius(const Cleaner& cleaner,
                               const std::list<Sensor*>& sensors,
                               const std::list<Measurement*>& allMeasurements) const;

private:
    int getIndiceO3(float val) const;
    int getIndiceNO2(float val) const;
    int getIndiceSO2(float val) const;
    int getIndicePM10(float val) const;

    // Collect measurements for a specific sensor within a period
    std::list<Measurement*> filterMeasurements(
        const std::list<Measurement*>& all,
        const std::string& sensorId,
        const Period& period) const;
};

#endif // AIRQUALITYCALCULATOR_H
