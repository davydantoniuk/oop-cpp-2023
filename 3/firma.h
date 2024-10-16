#ifndef FIRMA_H
#define FIRMA_H
#include <vector>
#include <list>
#include "pracownik.h"
#include "wspolpracownik.h"
using namespace std;
class firma
{
public:
    vector<pracownik *> pracownicy;
    vector<wspolpracownik *> wspolpracownicy;
    void wczytaj(string pracownicyplik, string wspolpracownicyplik);
    list<czlowiek *> urodziny(int _day, int _month);
};
#endif