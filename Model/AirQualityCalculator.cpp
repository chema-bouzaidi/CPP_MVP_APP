#include "AirQualityCalculator.h"
#include <algorithm>
#include <cmath>

AirQualityCalculator::AirQualityCalculator() {}
AirQualityCalculator::~AirQualityCalculator() {}

// ---- ATMO sub-indices -------------------------------------------------------

int AirQualityCalculator::getIndiceO3(float v) const {
    if      (v <= 50)  return 1;
    else if (v <= 100)  return 2;
    else if (v <= 130)  return 3;
    else if (v <= 240) return 4;
    else if (v <= 380) return 5;
    
    return 6;
}
int AirQualityCalculator::getIndiceNO2(float v) const {
    if      (v <= 40)  return 1;
    else if (v <= 90)  return 2;
    else if (v <= 120)  return 3;
    else if (v <= 230) return 4;
    else if (v <= 340) return 5;
    
    return 6;
}
int AirQualityCalculator::getIndiceSO2(float v) const {
    if      (v <= 100)  return 1;
    else if (v <= 200)  return 2;
    else if (v <= 350) return 3;
    else if (v <= 500) return 4;
    else if (v <= 750) return 5;
    
    return 6;
}
int AirQualityCalculator::getIndicePM10(float v) const {
    if      (v <= 20)  return 1;
    else if (v <= 40) return 2;
    else if (v <= 50) return 3;
    else if (v <= 100) return 4;
    else if (v <= 150) return 5;
   
    return 6;
}

// ---- Core ATMO computation --------------------------------------------------

int AirQualityCalculator::computeATMO(const std::list<Measurement*>& meas) const
{
    if (meas.empty()) return 0;
    float maxO3 = 0, maxNO2 = 0, maxSO2 = 0, maxPM10 = 0;
    for (const Measurement* m : meas)
    {
        const std::string& id = m->getAttributeId();
        float v = m->getValue();
        if      (id == "O3")   maxO3   = std::max(maxO3,   v);
        else if (id == "NO2")  maxNO2  = std::max(maxNO2,  v);
        else if (id == "SO2")  maxSO2  = std::max(maxSO2,  v);
        else if (id == "PM10") maxPM10 = std::max(maxPM10, v);
    }
    return std::max({getIndiceO3(maxO3), getIndiceNO2(maxNO2),
                     getIndiceSO2(maxSO2), getIndicePM10(maxPM10)});
}

// ---- Helpers ----------------------------------------------------------------

std::list<Measurement*> AirQualityCalculator::filterMeasurements(
    const std::list<Measurement*>& all,
    const std::string& sensorId,
    const Period& period) const
{
    std::list<Measurement*> result;
    for (Measurement* m : all)
        if (m->getSensorId() == sensorId && period.contains(m->getTimestamp()))
            result.push_back(m);
    return result;
}

// ---- Average quality --------------------------------------------------------

float AirQualityCalculator::computeAverageQuality(
    const std::list<Sensor*>& sensors,
    const std::list<Measurement*>& allMeasurements,
    const Coordinates& center, float radius, const Period& period) const
{
    float total = 0;
    int   count = 0;
    for (Sensor* s : sensors)
    {
        if (!s->getIsFunctional()) continue;
        if (s->getPosition().distanceTo(center) > radius) continue;

        std::list<Measurement*> meas = filterMeasurements(allMeasurements, s->getSensorId(), period);
        if (meas.empty()) continue;

        total += static_cast<float>(computeATMO(meas));
        count++;
    }
    return (count > 0) ? total / static_cast<float>(count) : 0.0f;
}

// ---- Cleaner impact ---------------------------------------------------------

float AirQualityCalculator::computeCleanerImpact(
    const Cleaner& cleaner,
    const std::list<Sensor*>& sensors,
    const std::list<Measurement*>& allMeasurements,
    float radius) const
{
    Coordinates pos(cleaner.getLatitude(), cleaner.getLongitude());

    Period beforePeriod(TimeStamp("2019-01-01 00:00:00"), cleaner.getStartTime());
    Period activePeriod(cleaner.getStartTime(), cleaner.getStopTime());

    float atmoBefore = computeAverageQuality(sensors, allMeasurements, pos, radius, beforePeriod);
    float atmoDuring = computeAverageQuality(sensors, allMeasurements, pos, radius, activePeriod);

    return atmoBefore - atmoDuring;
}

// ---- Cleaned radius ---------------------------------------------------------

float AirQualityCalculator::computeCleanedRadius(
    const Cleaner& cleaner,
    const std::list<Sensor*>& sensors,
    const std::list<Measurement*>& allMeasurements) const
{
    Coordinates pos(cleaner.getLatitude(), cleaner.getLongitude());
    Period beforePeriod(TimeStamp("2019-01-01 00:00:00"), cleaner.getStartTime());
    Period activePeriod(cleaner.getStartTime(), cleaner.getStopTime());

    float prevDiff = 0.0f;
    bool foundSensors = false;
    for (float r = 1.0f; r <= 100.0f; r += 1.0f)
    {
        float before = computeAverageQuality(sensors, allMeasurements, pos, r, beforePeriod);
        float during = computeAverageQuality(sensors, allMeasurements, pos, r, activePeriod);
        if (before == 0.0f && during == 0.0f) continue;
        float diff = before - during;
        if (!foundSensors)
        {
            if (std::abs(diff) < 0.05f) return 0.0f;
            foundSensors = true;
            prevDiff = diff;
        }
        else
        {
            if (std::abs(diff - prevDiff) < 0.05f) return r - 1.0f;
            prevDiff = diff;
        }
    }
    return foundSensors ? 100.0f : 0.0f;
}
