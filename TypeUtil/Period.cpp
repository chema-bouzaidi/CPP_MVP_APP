#include "Period.h"

Period & Period::operator=(const Period& p)
{
    if (this != &p) { startDate = p.startDate; endDate = p.endDate; }
    return *this;
}

Period::Period(const Period& p) : startDate(p.startDate), endDate(p.endDate) {}

Period::Period() : startDate(""), endDate("") {}

Period::Period(TimeStamp start, TimeStamp end) : startDate(start), endDate(end) {}

Period::~Period() {}

TimeStamp Period::getStartDate() const { return startDate; }
TimeStamp Period::getEndDate() const   { return endDate; }

bool Period::contains(const TimeStamp& t) const
{
    return (startDate <= t) && (t <= endDate);
}

bool Period::contains(const TimeStamp& tStart, const TimeStamp& tEnd) const
{
    return (startDate <= tStart) && (endDate >= tEnd);
}

bool Period::overlaps(const Period& other) const
{
    return (startDate <= other.endDate) && (endDate >= other.startDate);
}
