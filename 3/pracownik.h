#ifndef PRACOWNIK_H
#define PRACOWNIK_H
#include "czlowiek.h"
class pracownik : public czlowiek
{
private:
    int m_id;
    int id_przelozony;
    string dataumowy;

public:
    pracownik(string imie, string nazwisko, string pesel, string email,
              int id, int _id_przelozony, string data_umowy)
        : czlowiek(imie, nazwisko, pesel, email),
          m_id(id), id_przelozony(_id_przelozony), dataumowy(data_umowy) {}

    int getID() const
    {
        return m_id;
    }
    string getDataUmowy() const
    {
        return dataumowy;
    }
    int getOpiekun() const override
    {
        return id_przelozony;
    }
};
#endif