#ifndef SOLICITUDESENVIADAS_H
#define SOLICITUDESENVIADAS_H

#include "DataPila.h" // Asumiendo que DataPila tiene los datos de la solicitud
#include <iostream>

class ListaSolicitudesEnviadas
{
private:
    struct Nodo
    {
        DataPila solicitud;
        Nodo *siguiente;

        Nodo(const DataPila &sol, Nodo *sig = nullptr)
            : solicitud(sol), siguiente(sig) {}
    };
    Nodo *cabeza;

public:
    ListaSolicitudesEnviadas() : cabeza(nullptr) {}

    ~ListaSolicitudesEnviadas()
    {
        while (cabeza)
        {
            Nodo *temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }

    void agregarSolicitud(const DataPila &solicitud)
    {
        Nodo *nuevoNodo = new Nodo(solicitud);
        if (cabeza == nullptr) // Si la lista está vacía, el nuevo nodo es la cabeza
        {
            cabeza = nuevoNodo;
        }
        else // De lo contrario, recorre hasta el último nodo y añade el nuevo nodo
        {
            Nodo *temp = cabeza;
            while (temp->siguiente != nullptr)
            {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
        }
    }

    bool contiene(const std::string &correoReceptor) const
    {
        Nodo *actual = cabeza;
        while (actual)
        {
            if (actual->solicitud.getCorreoReceptor() == correoReceptor)
            {
                return true;
            }
            actual = actual->siguiente;
        }
        return false;
    }

    void eliminarSolicitud(const std::string &correoReceptor)
    {
        Nodo *actual = cabeza;
        Nodo *anterior = nullptr;

        while (actual)
        {
            if (actual->solicitud.getCorreoReceptor() == correoReceptor)
            {
                if (anterior)
                {
                    anterior->siguiente = actual->siguiente;
                }
                else
                {
                    cabeza = actual->siguiente;
                }
                delete actual;
                return;
            }
            anterior = actual;
            actual = actual->siguiente;
        }
    }

    void imprimirSolicitudes() const
    {
        Nodo *actual = cabeza;
        while (actual)
        {
            std::cout << actual->solicitud.getCorreoReceptor() << std::endl;
            actual = actual->siguiente;
        }
    }
};

#endif // LISTASOLICITUDESENVIADAS_H
