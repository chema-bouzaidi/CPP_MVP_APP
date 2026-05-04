#include "Attribute.h"
//constructeur
Attribute::Attribute(string id, sting name, string unit){
    this->attributeId =id;
    this->name = name;
    this->unit = unit;
}

//getter
string Attribute::getAttributeId(){
    return attributeId;
}
string Attribute:: getName(){
       return name;
}

string Attribute::getUnit(){
    return unit;
}