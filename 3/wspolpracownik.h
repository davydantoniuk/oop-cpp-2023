#ifndef WSPOLPRACOWNIK_H
#define WSPOLPRACOWNIK_H
#include "czlowiek.h"
class wspolpracownik : public czlowiek
{
private:
    int id_pracownika_odpowiedzialnego;

public:
    wspolpracownik(string imie, string nazwisko, string pesel, string email,
                   int id_opiekun)
        : czlowiek(imie, nazwisko, pesel, email), id_pracownika_odpowiedzialnego(id_opiekun) {}

    int getOpiekun() const override
    {
        return id_pracownika_odpowiedzialnego;
    }
};
#endif