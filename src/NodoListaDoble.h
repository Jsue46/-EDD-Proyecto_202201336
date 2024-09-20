#ifndef NODOLISTADOBLE_H
#define NODOLISTADOBLE_H

#include "Publicacion.h" // Asegúrate de tener una clase Publicacion que contenga los datos de la publicación

class NodoListaDoble
{
private:
    Publicacion publicacion;
    NodoListaDoble *siguiente;
    NodoListaDoble *anterior;

public:
    NodoListaDoble(const Publicacion &publicacion)
        : publicacion(publicacion), siguiente(nullptr), anterior(nullptr) {}

    NodoListaDoble *getSiguiente() const
    {
        return siguiente;
    }

    void setSiguiente(NodoListaDoble *siguiente)
    {
        this->siguiente = siguiente;
    }

    NodoListaDoble *getAnterior() const
    {
        return anterior;
    }

    void setAnterior(NodoListaDoble *anterior)
    {
        this->anterior = anterior;
    }

    Publicacion getPublicacion() const
    {
        return publicacion;
    }

    ~NodoListaDoble() {}
};

#endif // NODOLISTADOBLE_H
