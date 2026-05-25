#if !defined(TIMESTAMP_H)
#define TIMESTAMP_H

#include <string>

class TimeStamp
{
public:
    TimeStamp & operator=(const TimeStamp& t);
    TimeStamp(const TimeStamp& t);
    TimeStamp();
    TimeStamp(std::string dateStr);
    virtual ~TimeStamp();

    std::string toString() const;

    bool operator<=(const TimeStamp& t) const;
    bool operator>=(const TimeStamp& t) const;
    bool operator<(const TimeStamp& t) const;
    bool operator>(const TimeStamp& t) const;
    bool operator==(const TimeStamp& t) const;

protected:
    std::string date;
};

#endif // TIMESTAMP_H
