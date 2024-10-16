#ifndef PESEL_H
#define PESEL_H
#include <iostream>
#include <array>
#include <string>
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
#endif