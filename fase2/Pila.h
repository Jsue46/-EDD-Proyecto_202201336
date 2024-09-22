#ifndef PILA_H
#define PILA_H

#include "NodoPila.h"
#include <stdexcept>

template <typename T>
class Pila
{
private:
    NodoPila<T> *cima;

public:
    Pila() : cima(nullptr) {}

    void push(const T &dato)
    {
        NodoPila<T> *nuevoNodo = new NodoPila<T>(dato);
        nuevoNodo->setSiguiente(cima);
        cima = nuevoNodo;
    }

    T pop()
    {
        if (cima != nullptr)
        {
            NodoPila<T> *temp = cima;
            T dato = cima->getDato();
            cima = cima->getSiguiente();
            delete temp;
            return dato;
        }
        throw std::runtime_error("La pila está vacía");
    }

    T top() const
    {
        if (cima != nullptr)
        {
            return cima->getDato();
        }
        throw std::runtime_error("La pila está vacía");
    }

    bool estaVacia() const
    {
        return cima == nullptr;
    }

    bool contiene(const std::string &correoEmisor) const
    {
        NodoPila<T> *actual = cima;
        while (actual != nullptr)
        {
            if (actual->getDato().getCorreoEmisor() == correoEmisor)
            {
                return true;
            }
            actual = actual->getSiguiente();
        }
        return false;
    }

    ~Pila()
    {
        while (!estaVacia())
        {
            pop();
        }
    }
};

#endif // PILA_H
