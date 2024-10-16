#ifndef PESEL_H
#define PESEL_H
#include <iostream>
#include <string>
using namespace std;
class pesel
{
public:
    pesel();
    void setPesel(string PESEL);
    pesel(string PESEL);
    string getData() const;
    bool getPlec() const;
    string operator()() const;

private:
    string data;
    string number;
    bool gender;
    void parse_pesel(const string &pesel);
};
#endif