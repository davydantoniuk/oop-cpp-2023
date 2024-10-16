#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include <sstream>
#include <array>
using namespace std;
array<int, 3> ParsePesel(string &pesel)
{
    int year = stoi(pesel.substr(0, 2));
    int month = stoi(pesel.substr(2, 2));
    int day = stoi(pesel.substr(4, 2));
    if (month > 80)
    {
        year += 1800;
        month -= 80;
    }
    else if (month > 60)
    {
        year += 2200;
        month -= 60;
    }
    else if (month > 40)
    {
        year += 2100;
        month -= 40;
    }
    else if (month > 20)
    {
        year += 2000;
        month -= 20;
    }
    else
    {
        year += 1900;
    }
    array<int, 3> PeselArray = {year, month, day};
    return PeselArray;
}

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
class firma
{
public:
    vector<pracownik *> pracownicy;
    vector<wspolpracownik *> wspolpracownicy;
    void wczytaj(string pracownicyplik, string wspolpracownicyplik)
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
    list<czlowiek *> urodziny(int _day, int _month)
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
};

void zapisz_do_pliku(const list<czlowiek *> &my_list, const string &nazwa, const firma &f)
{
    fstream wiadomosci;
    wiadomosci.open(nazwa, ios::out);
    if (wiadomosci.is_open())
    {
        stringstream ss;

        for (auto ptr : my_list)
        {
            string opiekun;
            for (auto chel : f.pracownicy)
            {
                if (ptr->getOpiekun() == chel->getID())
                {
                    opiekun = chel->getEmail();
                }
            }
            string pesel = ptr->getPesel();
            array<int, 3> PeselArray = ParsePesel(pesel);
            ss << opiekun << ";\t" << ptr->getEmail() << ";\t" << PeselArray[0] << "-" << PeselArray[1] << "-" << PeselArray[2] << ";\t" << ptr->getOpiekun() << endl;
        }
        string list_str = ss.str();
        wiadomosci << list_str << endl;
        wiadomosci.close();
    }
}

int main()
{
    firma f;
    f.wczytaj("pracownicy.txt", "wspolpracownicy.txt");
    list<czlowiek *> jubilaci = f.urodziny(5, 2);
    zapisz_do_pliku(jubilaci, "wiadomosci.txt", f);
    return 0;
}