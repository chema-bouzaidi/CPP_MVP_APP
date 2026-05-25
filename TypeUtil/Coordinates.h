#if !defined(COORDINATES_H)
#define COORDINATES_H

class Coordinates
{
public:
    Coordinates & operator=(const Coordinates& c);
    Coordinates(const Coordinates& c);
    Coordinates();
    Coordinates(float lat, float lon);
    virtual ~Coordinates();

    float getLatitude() const;
    float getLongitude() const;
    float distanceTo(const Coordinates& c) const;

protected:
    float latitude;
    float longitude;
};

#endif // COORDINATES_H
