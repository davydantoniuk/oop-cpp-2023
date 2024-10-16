#include <iostream>
#include <string>
#include "pesel.h"
pesel::pesel()
{
}
void pesel::setPesel(string PESEL)
{
    parse_pesel(PESEL);
}
pesel::pesel(string PESEL)
{
    parse_pesel(PESEL);
}
string pesel::getData() const
{
    return data;
}
bool pesel::getPlec() const
{
    return gender;
}
string pesel::operator()() const
{
    return number;
}
void pesel::parse_pesel(const string &pesel)
{
    if (pesel.size() != 11)
    {
        return;
    }
    for (char c : pesel)
    {
        if (!isdigit(c))
        {
            return;
        }
    }
    int year = stoi(pesel.substr(0, 2));
    int month = stoi(pesel.substr(2, 2));
    int day = stoi(pesel.substr(4, 2));
    int plec = stoi(pesel.substr(9, 1));
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
    if (month < 1 || month > 12)
    {
        return;
    }
    if (day < 1 || day > 31)
    {
        return;
    }
    if (month == 2 && day > 29)
    {
        return;
    }
    if (month == 2 && day == 29 && (year % 4 != 0 || (year % 100 == 0 && year % 400 != 0)))
    {
        return;
    }
    int weights[] = {1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    int sum = 0;
    for (int i = 0; i < 10; i++)
    {
        sum += weights[i] * (pesel[i] - '0');
    }
    int checksum = (10 - (sum % 10)) % 10;
    if (checksum != pesel[10] - '0')
    {
        return;
    }
    string _month = month < 10 ? '0' + to_string(month) : to_string(month);
    string _day = day < 10 ? '0' + to_string(day) : to_string(day);
    data = to_string(year) + "-" + _month + "-" + _day;
    number = pesel;
    gender = plec % 2 == 0 ? false : true;
}