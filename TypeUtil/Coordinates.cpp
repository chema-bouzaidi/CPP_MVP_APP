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
    // formule de Haversine pour calculer la distance entre deux points sur terrre
    const float R = 6371.0f;  // Rayon de la terre
    const float toRad = 3.14f / 180.0f;

    float lat1 = latitude    * toRad;
    float lat2 = c.latitude  * toRad;
    float dLat = (c.latitude  - latitude)  * toRad;
    float dLon = (c.longitude - longitude) * toRad;

    float a = std::sin(dLat/2) * std::sin(dLat/2)
            + std::cos(lat1)   * std::cos(lat2)
            * std::sin(dLon/2) * std::sin(dLon/2);

    return R * 2* std::atan2(std::sqrt(a), std::sqrt(1.0f - a));
}
