#include "Statistics.h"
#include <iostream>
#include <iomanip>

Statistics::Statistics(const Coordinates& c, float r, const Period& p,
                       int m, float res, const std::string& desc)
    : center(c), radius(r), period(p), mode(m), result(res), description(desc) {}

Statistics::Statistics()
    : radius(0), mode(0), result(0), description("") {}

float       Statistics::getResult() const      { return result; }
std::string Statistics::getDescription() const { return description; }

void Statistics::display() const
{
    std::cout << "--- Statistics ---\n";
    std::cout << "  " << description << "\n";
    std::cout << "  Result : " << std::fixed << std::setprecision(2) << result << "\n";
    std::cout << "  Radius : " << radius << " km\n";
    std::cout << "  Center : (" << center.getLatitude()
              << ", " << center.getLongitude() << ")\n";
    std::cout << "  Period : " << period.getStartDate().toString()
              << " -> " << period.getEndDate().toString() << "\n";
}
