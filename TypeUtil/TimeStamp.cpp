#include "TimeStamp.h"

TimeStamp & TimeStamp::operator=(const TimeStamp& t)
{
    if (this != &t) date = t.date;
    return *this;
}

TimeStamp::TimeStamp(const TimeStamp& t) : date(t.date) {}

TimeStamp::TimeStamp() : date("") {}

TimeStamp::TimeStamp(std::string dateStr) : date(dateStr) {}

TimeStamp::~TimeStamp() {}

std::string TimeStamp::toString() const { return date; }

bool TimeStamp::operator<=(const TimeStamp& t) const { return date <= t.date; }
bool TimeStamp::operator>=(const TimeStamp& t) const { return date >= t.date; }
bool TimeStamp::operator<(const TimeStamp& t) const  { return date <  t.date; }
bool TimeStamp::operator>(const TimeStamp& t) const  { return date >  t.date; }
bool TimeStamp::operator==(const TimeStamp& t) const { return date == t.date; }
