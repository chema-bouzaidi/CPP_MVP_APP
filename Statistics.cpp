#include "Statistics.h"
#include <iostream>

Statistics::Statistics(const Coordinates& c, float r, const Period& p, int m)
    : center(c), radius(r), period(p), mode(m) {}

void Statistics::generate() {
    // ici ton appelle AirQualityCalculator
    // selon mode (moyenne, amélioration, etc.)
}

void Statistics::display() const {
    std::cout << "Statistics:\n";
    std::cout << "Radius: " << radius << std::endl;
    std::cout << "Mode: " << mode << std::endl;
}