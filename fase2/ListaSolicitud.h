

#endif // LISTASOLICITUDES_H
#ifndef LISTASOLICITUD_H
#define LISTASOLICITUD_H
#include "NodoListaSimple.h"

class ListaSolicitudes
{
private:
    NodoListaSimple *primerNodo; // Puntero al primer nodo de la lista

public:
    ListaSolicitudes() : primerNodo(nullptr) {} // Constructor que inicializa la lista vacía

    // Método para añadir una solicitud al final de la lista
    void insertarSolicitud(const datosMatriz &nuevaSolicitud)
    {
        NodoListaSimple *nuevoElemento = new NodoListaSimple(nuevaSolicitud);
        if (primerNodo == nullptr) // Si la lista está vacía, el nuevo nodo será el primero
        {
            primerNodo = nuevoElemento;
        }
        else // De lo contrario, recorre hasta el último nodo y añade el nuevo nodo
        {
            NodoListaSimple *temp = primerNodo;
            while (temp->getSiguiente() != nullptr)
            {
                temp = temp->getSiguiente();
            }
            temp->setSiguiente(nuevoElemento);
        }
    }

    // Método para comprobar si la lista contiene una solicitud para un receptor específico
    bool buscar(const string &correoDestino) const
    {
        NodoListaSimple *nodoActual = primerNodo;
        while (nodoActual != nullptr)
        {
            if (nodoActual->getDatos().getCorreoEmisor() == correoDestino) // Compara con el correo emisor
            {
                return true;
            }
            nodoActual = nodoActual->getSiguiente(); // Avanza al siguiente nodo
        }
        return false; // Si no se encuentra, devuelve false
    }

    // Destructor que libera todos los nodos de la lista
    ~ListaSolicitudes()
    {
        while (primerNodo != nullptr)
        {
            NodoListaSimple *temp = primerNodo;
            primerNodo = primerNodo->getSiguiente();
            delete temp;
        }
    }
};

#endif // LISTASOLICITUDES_H
