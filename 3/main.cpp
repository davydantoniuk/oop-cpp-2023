#include "firma.h"
#include "firma.cpp"
using namespace std;

void zapisz_do_pliku(const list<czlowiek *> &my_list, const string &nazwa, const firma &f)
{
    fstream wiadomosci;
    wiadomosci.open(nazwa, ios::out);
    if (wiadomosci.is_open())
    {
        stringstream ss;

        for (auto czlowiek_email : my_list)
        {
            string opiekun;
            for (auto pracowmik_email : f.pracownicy)
            {
                if (czlowiek_email->getOpiekun() == pracowmik_email->getID())
                {
                    opiekun = pracowmik_email->getEmail();
                }
            }
            string pesel = czlowiek_email->getPesel();
            array<int, 3> PeselArray = ParsePesel(pesel);
            ss << opiekun << ";\t" << czlowiek_email->getEmail() << ";\t" << PeselArray[0] << "-" << PeselArray[1] << "-" << PeselArray[2] << ";" << endl;
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