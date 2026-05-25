#ifndef STATISTICS_H
#define STATISTICS_H

#include <string>
#include "../TypeUtil/Coordinates.h"
#include "../TypeUtil/Period.h"

class Statistics
{
private:
    Coordinates center;
    float       radius;
    Period      period;
    int         mode;
    float       result;
    std::string description;

public:
    Statistics(const Coordinates& c, float r, const Period& p,
               int mode, float result, const std::string& desc);
    Statistics();

    float       getResult() const;
    std::string getDescription() const;
    void        display() const;
};

#endif // STATISTICS_H
