#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>

using namespace std;

class Attribute{
    private:
        string attributeID;
        string name;
        string unit;
    
    public :
    //constructeur
    Attribute(string id, string name , string unit);

    // getters 
    string getAttributeId;
    string getName;
    string getUnit;
};

#endif
