#ifndef NODOPILA_H
#define NODOPILA_H

template <typename T>
class NodoPila
{
private:
    T dato;
    NodoPila *siguiente;

public:
    NodoPila(const T &dato) : dato(dato), siguiente(nullptr) {}

    T getDato() const
    {
        return dato;
    }

    NodoPila *getSiguiente() const
    {
        return siguiente;
    }

    void setSiguiente(NodoPila *siguiente)
    {
        this->siguiente = siguiente;
    }
};

#endif // NODOPILA_H
