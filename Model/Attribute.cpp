#include "Attribute.h"

Attribute::Attribute(std::string id, std::string n, std::string u)
    : attributeId(id), name(n), unit(u) {}

Attribute::Attribute() : attributeId(""), name(""), unit("") {}

std::string Attribute::getAttributeId() const { return attributeId; }
std::string Attribute::getName() const         { return name; }
std::string Attribute::getUnit() const         { return unit; }
