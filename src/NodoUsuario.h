#ifndef NODOUSUARIO_H
#define NODOUSUARIO_H

#include "Usuario.h"

class NodoUsuario
{
private:
    Usuario usuario;
    NodoUsuario *siguiente;

public:
    NodoUsuario(const Usuario &usuario) : usuario(usuario), siguiente(nullptr) {}

    NodoUsuario *getSiguiente()
    {
        return siguiente;
    }

    void setSiguiente(NodoUsuario *siguiente)
    {
        this->siguiente = siguiente;
    }

    Usuario &getUsuario()
    {
        return usuario;
    }
};

#endif // NODOUSUARIO_H