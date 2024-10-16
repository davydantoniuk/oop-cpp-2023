#ifndef LISTA_H
#define LISTA_H
#include <iostream>
using namespace std;

// -------------------------------------------------
// najpierw klasy
// -------------------------------------------------

template <class T>
class lista
// klasa opisująca listę dwukierunkową
{
public:
    lista();
    lista(const lista<T> &other);     // konstruktor kopiujący
    lista(lista<T> &&other) noexcept; // konstruktor przypisania
    lista(const initializer_list<T> &D);
    virtual ~lista();
    class iterator;
    void push_back(const T &);
    iterator erase(iterator);
    iterator begin() const;
    iterator end() const;
    size_t size() const;
    lista<T> &operator=(const lista<T> &);
    lista<T> &operator=(lista<T> &&) noexcept;

private:
    iterator __front, __back;
};

template <class T>
class lista<T>::iterator
// iterator dla klasy lista
{
public:
    friend class lista<T>;
    lista<T>::iterator &operator++();
    bool operator!=(iterator);
    T &operator*();

private:
    class elem_listy;
    elem_listy *__p = nullptr;
};

template <class T>
class lista<T>::iterator::elem_listy
// pomocnicza klasa, która opisuje obiekt przechowujący właściwą
// wartość oraz iteratory do poprzedniego i następnego elementu
{
public:
    T v;
    iterator next, prev;
};

// -------------------------------------------------
// realizacje (też w pliku nagłówkowym, ze względu na to, że klasa jest
// szablonowa
// -------------------------------------------------

// klasa lista

template <class T>
typename lista<T>::iterator lista<T>::erase(lista<T>::iterator x)
{
    // metoda klasy lista, która usuwa wskazywany element
    if (x != end())
    {
        auto N = x.__p->next;
        auto P = x.__p->prev;

        delete (x.__p);

        if (P != end())
        {
            // a więc usuwany nie był pierwszy
            P.__p->next = N;
        }
        else
        {
            // był pierwszy
            __front = N;
        }
        if (N != end())
            // usuwany nie był ostatni
            N.__p->prev = P;
        else
            // usuwany był ostatni
            __back = P;

        return N;
    }
    else
        return end();
}

template <class T>
typename lista<T>::iterator lista<T>::begin() const
{
    return __front;
}

template <class T>
T &lista<T>::iterator::operator*()
{
    return __p->v;
}

template <class T>
typename lista<T>::iterator lista<T>::end() const
{
    return iterator();
}

template <class T>
lista<T>::~lista()
{
    auto x = begin();
    while (x != end())
    {
        x = erase(x);
    }
}

template <class T>
lista<T>::lista()
{
}

// konstruktor kopiujący
template <class T>
lista<T>::lista(const lista<T> &other)
{
    for (auto x : other)
    {
        push_back(x);
    }
}
// konstruktor przypisania
template <class T>
lista<T>::lista(lista<T> &&other) noexcept
{
    __front = other.__front;
    __back = other.__back;
    other.__front = end();
    other.__back = end();
}

template <class T>
size_t lista<T>::size() const
{
    size_t result = 0;
    for (auto x : *this)
    {
        ++result;
    }
    return result;
}

template <class T>
void lista<T>::push_back(const T &v)
{
    typename iterator::elem_listy *e = new typename iterator::elem_listy();
    e->v = v;
    e->prev = __back;
    e->next = end();
    typename lista<T>::iterator it;
    it.__p = e;
    if (__back != end())
    {
        __back.__p->next = it;
    }
    __back = it;
    if (!(__front != end()))
        __front = __back;
}

// klasa lista<T>::iterator

template <class T>
typename lista<T>::iterator &lista<T>::iterator::operator++()
{
    if (this->__p != nullptr)
        *this = __p->next;
    return *this;
}

template <class T>
bool lista<T>::iterator::operator!=(lista<T>::iterator x)
{
    return this->__p != x.__p;
}

template <class T>
lista<T> &lista<T>::operator=(const lista<T> &other)
{
    if (this != &other)
    {
        auto x = begin();
        while (x != end())
        {
            x = erase(x);
        }
        for (auto e : other)
        {
            push_back(e);
        }
    }
    return *this;
}

template <class T>
lista<T> &lista<T>::operator=(lista &&other) noexcept
{
    if (&other != this)
    {
        __front = other.__front;
        __back = other.__back;

        other.__front = end();
        other.__back = end();
    }
    return *this;
}

template <class T>
lista<T>::lista(const initializer_list<T> &D)
{
    for (auto x : D)
    {
        push_back(x);
    }
}
#endif // LISTA_H
