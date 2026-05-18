CXX      = g++
CXXFLAGS = -std=c++11 -Wall -Wextra \
           -I. -ITypeUtil -IModel -Icontroleur -IVue

SRCS = main.cpp \
       TypeUtil/TimeStamp.cpp \
       TypeUtil/Coordinates.cpp \
       TypeUtil/Period.cpp \
       Model/User.cpp \
       Model/Admin.cpp \
       Model/Agency.cpp \
       Model/PrivateIndividual.cpp \
       Model/Sensor.cpp \
       Model/PrivateSensor.cpp \
       Model/Measurement.cpp \
       Model/Attribute.cpp \
       Model/Cleaner.cpp \
       Model/Provider.cpp \
       Model/AirQualityCalculator.cpp \
       Model/Statistics.cpp \
       Model/Modele.cpp \
       controleur/Authentifieur.cpp \
       controleur/ControleurAdmin.cpp \
       controleur/ControleurAgence.cpp \
       controleur/ControleurEntreprise.cpp \
       controleur/ControleurActeurPrive.cpp \
       Vue/InterfaceUtilisateur.cpp

TARGET = airwatcher

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(TARGET) $(TARGET).exe

.PHONY: all clean
