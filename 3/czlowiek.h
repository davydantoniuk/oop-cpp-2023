#ifndef CZLOWIEK_H
#define CZLOWIEK_H
#include <iostream>
#include <string>
using namespace std;
class czlowiek
{
private:
    string imie;
    string nazwisko;
    string pesel;
    string email;

public:
    czlowiek(string imie, string nazwisko, string pesel, string email)
    {
        this->imie = imie;
        this->nazwisko = nazwisko;
        this->pesel = pesel;
        this->email = email;
    }
    string getPesel() const
    {
        return pesel;
    }
    string getImie() const
    {
        return imie;
    }
    string getNazwisko() const
    {
        return nazwisko;
    }
    string getEmail() const
    {
        return email;
    }
    virtual int getOpiekun() const = 0;
};
#endif