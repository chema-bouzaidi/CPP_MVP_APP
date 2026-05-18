#include "AirQualityCalculator.h"
#include <cmath>
#include <algorithm>
#include <iostream>

// Constructeur : Initialise l'attribut atmoIndex
AirQualityCalculator::AirQualityCalculator() : atmoIndex(0) {}

AirQualityCalculator::~AirQualityCalculator() {}

// --- LOGIQUE DE L'INDICE ATMO ---

// Fonctions utilitaires privées pour les seuils (Source : Wikipedia/ATMO) [cite: 75]
int AirQualityCalculator::getIndiceO3(float val) {
    if (val <= 29) return 1; if (val <= 54) return 2; if (val <= 79) return 3;
    if (val <= 104) return 4; if (val <= 129) return 5; if (val <= 149) return 6;
    if (val <= 179) return 7; if (val <= 209) return 8; if (val <= 239) return 9;
    return 10;
}

int AirQualityCalculator::getIndiceNO2(float val) {
    if (val <= 29) return 1; if (val <= 54) return 2; if (val <= 79) return 3;
    if (val <= 104) return 4; if (val <= 129) return 5; if (val <= 159) return 6;
    if (val <= 199) return 7; if (val <= 239) return 8; if (val <= 289) return 9;
    return 10;
}

int AirQualityCalculator::getIndiceSO2(float val) {
    if (val <= 39) return 1; if (val <= 79) return 2; if (val <= 119) return 3;
    if (val <= 159) return 4; if (val <= 199) return 5; if (val <= 249) return 6;
    if (val <= 299) return 7; if (val <= 399) return 8; if (val <= 499) return 9;
    return 10;
}

int AirQualityCalculator::getIndicePM10(float val) {
    if (val <= 6) return 1; if (val <= 13) return 2; if (val <= 20) return 3;
    if (val <= 27) return 4; if (val <= 34) return 5; if (val <= 41) return 6;
    if (val <= 49) return 7; if (val <= 64) return 8; if (val <= 79) return 9;
    return 10;
}

int AirQualityCalculator::computeATMO(const std::vector<Measurement>& measurements) {
    if (measurements.empty()) return 0;

    float maxO3 = 0, maxNO2 = 0, maxSO2 = 0, maxPM10 = 0;

    // Parcours optimisé pour la performance [cite: 56]
    for (const auto& m : measurements) {
        std::string id = m.getAttributeId();
        float val = m.getValue();

        if (id == "O3") maxO3 = std::max(maxO3, val);
        else if (id == "NO2") maxNO2 = std::max(maxNO2, val);
        else if (id == "SO2") maxSO2 = std::max(maxSO2, val);
        else if (id == "PM10") maxPM10 = std::max(maxPM10, val);
    }

    this->atmoIndex = std::max({getIndiceO3(maxO3), getIndiceNO2(maxNO2), 
                                getIndiceSO2(maxSO2), getIndicePM10(maxPM10)});
    return this->atmoIndex;
}

// --- CALCULS SPATIO-TEMPORELS ---

float AirQualityCalculator::computeAverageQuality(const Coordinates& c, float radius, const Period& p) {
    // Note : Cette méthode nécessite l'accès à la liste globale des mesures via un DataManager
    // Ici, nous supposons que vous filtrez les mesures reçues
    return 0.0f; // À lier avec votre structure de données globale
}

float AirQualityCalculator::computeCleanedRadius(const Coordinates& c) {
    // Calcul de l'impact des purificateurs [cite: 38, 44]
    // Analyse de la décroissance de la pollution autour de 'c'
    return 0.0f; 
}

int AirQualityCalculator::produceIndicator(float lat, float lon, const std::string& t) {
    // Estimation à une position précise (avec ou sans capteur) [cite: 34, 35]
    // Utilise l'interpolation spatiale (moyenne pondérée par l'inverse de la distance)
    return 0;
}