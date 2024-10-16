#ifndef PRZEDMIOT_H
#define PRZEDMIOT_H

#include <iostream>
using namespace std;
class przedmiot {
private:
    string nazwa;
    double price;
    int liczba;
    int kod;

public:
    przedmiot(string nazwa, double price, int liczba, int kod)
    {
        this->nazwa=nazwa;
        this->price=price;
        this->liczba=liczba;
        this->kod=kod;
    }

    string getNazwa() const {
        return nazwa;
    }

    double getPrice() const {
        return price;
    }

    int getLiczba() const {
        return liczba;
    }

    int getKod() const {
        return kod;
    }

    virtual string getOpis() const = 0;
};

#endif //PRZEDMIOT_H
