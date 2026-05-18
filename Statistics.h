#ifndef STATISTICS_H
#define STATISTICS_H

#include "Coordinates.h"
#include "Period.h"

class Statistics {
private:
    Coordinates center;
    float radius;
    Period period;
    int mode;

public:
    Statistics(const Coordinates& c, float r, const Period& p, int m);

    void generate();
    void display() const;
};

#endif