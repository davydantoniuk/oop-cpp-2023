#ifndef STOS_H
#define STOS_H

#include <stdexcept>

template <typename T>
class stos
{
private:
    T *data;
    int maxSize;
    int topIndex;

public:
    stos(int size = 1000) : maxSize(size), topIndex(-1)
    {
        data = new T[maxSize];
    }

    ~stos()
    {
        delete[] data;
    }

    void push(const T &element)
    {
        if (topIndex == maxSize - 1)
        {
            throw std::runtime_error("przekroczenia dla stosu");
        }

        data[++topIndex] = element;
    }

    T pop()
    {
        if (topIndex == -1)
        {
            throw std::runtime_error("stos pusty");
        }

        return data[topIndex--];
    }

    bool isEmpty() const
    {
        return topIndex == -1;
    }

    int size() const
    {
        return topIndex + 1;
    }

    int max_size() const
    {
        return maxSize;
    }

    T top() const
    {
        if (topIndex == -1)
        {
            throw std::runtime_error("stos pusty");
        }

        return data[topIndex];
    }
};

#endif // STOS_H
