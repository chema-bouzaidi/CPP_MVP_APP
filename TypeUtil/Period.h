#if !defined(PERIOD_H)
#define PERIOD_H

#include "TimeStamp.h"

class Period
{
public:
    Period & operator=(const Period& p);
    Period(const Period& p);
    Period();
    Period(TimeStamp start, TimeStamp end);
    virtual ~Period();

    TimeStamp getStartDate() const;
    TimeStamp getEndDate() const;

    bool contains(const TimeStamp& t) const;
    bool contains(const TimeStamp& tStart, const TimeStamp& tEnd) const;
    bool overlaps(const Period& other) const;

protected:
    TimeStamp startDate;
    TimeStamp endDate;
};

#endif // PERIOD_H
