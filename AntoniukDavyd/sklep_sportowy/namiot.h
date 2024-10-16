#ifndef NAMIOT_H
#define NAMIOT_H

#include "przedmiot.h"
#include <iostream>
using namespace std;

class namiot : public przedmiot {
private:
    int miejsca;

public:
    namiot(string nazva, double price, int niczba, int kod, int miejsca)
        : przedmiot(nazva, price, niczba, kod)
        {
            this->miejsca=miejsca;
        }

    int getMiejsca() const {
        return miejsca;
    }

    string getOpis() const override {
        return "Kod: " + to_string(getKod()) + ", Nazva: " + getNazwa() +
               ", Priznachenist dlia: " + to_string(getLiczba()) + " osób, Miejsca: " +
               to_string(miejsca);
    }

};

#endif //NAMIOT_H

