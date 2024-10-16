#include <iostream>
#include "stos.h"

using namespace std;

int main()
{
    stos<int> A(10);
    A.push(3);
    A.push(5);
    A.push(8);
    cout << "liczba elementow na stosie: " << A.size() << "\n";
    cout << "maksymalna dopuszczalna: " << A.max_size() << "\n";
    while (A.size() > 0)
    {
        cout << "wierzcholek: " << A.top() << "\n";
        A.pop();
    }
    try
    {
        for (int i = 0; i < 60; i++)
            A.push(i);
    }
    catch (exception &e)
    {
        cout << "Problem: " << e.what() << "\n";
    }
    try
    {
        for (int i = 0; i < 60; i++)
            A.pop();
    }
    catch (exception &e)
    {
        cout << "Problem: " << e.what() << "\n";
    }

    return 0;
}
