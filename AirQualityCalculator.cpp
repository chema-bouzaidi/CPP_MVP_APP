#include "AirQualityCalculator.h"

AirQualityCalculator::AirQualityCalculator() : atmoIndex(0) {}

AirQualityCalculator::~AirQualityCalculator() {}

int AirQualityCalculator::computeATMO(const std::vector<Measurement>& measurements) {
    if (measurements.empty()) return 0;

    float sum = 0;
    for (const auto& m : measurements) {
        sum += m.getValue();
    }
    return static_cast<int>(sum / measurements.size());
}

float AirQualityCalculator::computeAverageQuality(const Coordinates&, float, const Period&) {
    // TODO: filtrer les mesures selon zone + période
    return 0.0;
}

float AirQualityCalculator::computeImprovement(const Period&, const Period&) {
    // TODO: différence entre deux périodes
    return 0.0;
}

float AirQualityCalculator::computeCleanedRadius(const Coordinates&) {
    // TODO: calcul réel avec cleaners
    return 0.0;
}

int AirQualityCalculator::produceIndicator(float, float, const std::string&) {
    // TODO: interpolation spatiale
    return 0;
}