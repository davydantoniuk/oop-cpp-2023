#include <sstream>
#include <fstream>
#include "firma.h"
#include "pesel.h"
using namespace std;
void firma::wczytaj(const string pracownicyplik, const string wspolpracownicyplik)
{
    fstream file;
    file.open(pracownicyplik, ios::in);
    if (file.is_open())
    {
        string line;
        getline(file, line);
        while (getline(file, line))
        {

            istringstream iss(line);
            int id, id_szefa;
            string imie, nazwisko, email, date, pesel;

            if (iss >> id >> imie >> nazwisko >> pesel >> email >> date >> id_szefa)
            {
                pracownicy.push_back(new pracownik(imie, nazwisko, pesel, email, id, id_szefa, date));
            }
            else
            {
                cerr << "Failed to parse line: " << line << endl;
            }
        }
        file.close();
    }
    fstream file1;
    file1.open(wspolpracownicyplik, ios::in);
    if (file1.is_open())
    {
        string line;
        getline(file1, line);
        while (getline(file1, line))
        {
            istringstream iss(line);
            int id_szefa;
            string imie, nazwisko, email, pesel;

            if (iss >> imie >> nazwisko >> pesel >> email >> id_szefa)
            {
                wspolpracownicy.push_back(new wspolpracownik(imie, nazwisko, pesel, email, id_szefa));
            }
            else
            {
                cerr << "Failed to parse line: " << line << endl;
            }
        }
        file1.close();
    }
}
list<czlowiek *> firma::urodziny(int _day, int _month)
{
    list<czlowiek *> result;

    for (const auto &pracownik : pracownicy)
    {
        string pesel = pracownik->getPesel();
        array<int, 3> PeselArray = ParsePesel(pesel);
        if (_month == PeselArray[1] && _day == PeselArray[2])
        {
            result.push_back(pracownik);
        }
    }
    for (const auto &wspolpracownik : wspolpracownicy)
    {

        string pesel = wspolpracownik->getPesel();
        array<int, 3> PeselArray = ParsePesel(pesel);
        if (_month == PeselArray[1] && _day == PeselArray[2])
        {
            result.push_back(wspolpracownik);
        }
    }
    return result;
}