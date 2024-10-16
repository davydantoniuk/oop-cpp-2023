#ifndef PILKA_H
#define PILKA_H

#include "przedmiot.h"
#include <iostream>
using namespace std;

class pilka : public przedmiot {
private:
    int srednica;

public:
    pilka(string nazwa, double price, int niczba, int kod, int diametr)
        : przedmiot(nazwa, price, niczba, kod)
        {
            this->srednica=srednica;
        }

    int getSrednica() const {
        return srednica;
    }

    string getOpis() const override {
        return "Kod: " + to_string(getKod()) + ", Nazva: " + getNazwa() +
               ", Srednica: " + to_string(srednica) + " sm";
    }
};

#endif //NAMIOT_H
