#include "Coordinates.h"
#include <cmath>

Coordinates & Coordinates::operator=(const Coordinates& c)
{
    if (this != &c) { latitude = c.latitude; longitude = c.longitude; }
    return *this;
}

Coordinates::Coordinates(const Coordinates& c)
    : latitude(c.latitude), longitude(c.longitude) {}

Coordinates::Coordinates() : latitude(0.0f), longitude(0.0f) {}

Coordinates::Coordinates(float lat, float lon) : latitude(lat), longitude(lon) {}

Coordinates::~Coordinates() {}

float Coordinates::getLatitude() const  { return latitude; }
float Coordinates::getLongitude() const { return longitude; }

float Coordinates::distanceTo(const Coordinates& c) const
{
    // 1 degree latitude ≈ 111 km, 1 degree longitude ≈ 77 km (France)
    float dy = (latitude  - c.latitude)  * 111.0f;
    float dx = (longitude - c.longitude) * 77.0f;
    return std::sqrt(dx*dx + dy*dy);
}
