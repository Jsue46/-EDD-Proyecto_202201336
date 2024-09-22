#ifndef NODOPUBLICACION_H
#define NODOPUBLICACION_H

#include "Publicacion.h"

class NodoPublicacion
{
public:
    Publicacion publicacion; // Objeto de tipo Publicacion
    NodoPublicacion *siguiente; // Puntero al siguiente nodo
    NodoPublicacion *anterior;  // Puntero al nodo anterior

    // Constructor
    NodoPublicacion(const Publicacion &publi) : publicacion(publi), siguiente(nullptr), anterior(nullptr) {}
};

#endif // NODOPUBLICACION_H
