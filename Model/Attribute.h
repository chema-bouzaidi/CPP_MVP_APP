#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>

class Attribute
{
private:
    std::string attributeId;
    std::string name;
    std::string unit;
public:
    Attribute(std::string id, std::string name, std::string unit);
    Attribute();

    std::string getAttributeId() const;
    std::string getName() const;
    std::string getUnit() const;
};

#endif // ATTRIBUTE_H
