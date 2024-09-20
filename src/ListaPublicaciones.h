#ifndef LISTAPUBLICACIONES_H
#define LISTAPUBLICACIONES_H

#include <iostream>
#include <string>

class ListaPublicaciones
{
private:
    struct Publicacion
    {
        std::string autor;
        std::string contenido;
        std::string fecha;

        Publicacion(const std::string &aut, const std::string &cont, const std::string &fec)
            : autor(aut), contenido(cont), fecha(fec) {}
    };

    struct Nodo
    {
        Publicacion publicacion;
        Nodo *siguiente;

        Nodo(const Publicacion &pub, Nodo *sig = nullptr)
            : publicacion(pub), siguiente(sig) {}
    };

    Nodo *cabeza;

public:
    ListaPublicaciones() : cabeza(nullptr) {}

    ~ListaPublicaciones()
    {
        while (cabeza)
        {
            Nodo *temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }

    void agregarPublicacion(const std::string &autor, const std::string &contenido, const std::string &fecha)
    {
        Publicacion nuevaPublicacion(autor, contenido, fecha);
        Nodo *nuevoNodo = new Nodo(nuevaPublicacion);
        if (cabeza == nullptr) // Si la lista está vacía, el nuevo nodo es la cabeza
        {
            cabeza = nuevoNodo;
        }
        else // Añadir el nuevo nodo al final de la lista
        {
            Nodo *temp = cabeza;
            while (temp->siguiente != nullptr)
            {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoNodo;
        }
    }

    void eliminarPublicacion(const std::string &contenido)
    {
        Nodo *actual = cabeza;
        Nodo *anterior = nullptr;

        while (actual)
        {
            if (actual->publicacion.contenido == contenido)
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

    void imprimirPublicaciones() const
    {
        Nodo *actual = cabeza;
        while (actual)
        {
            std::cout << "Autor: " << actual->publicacion.autor
                      << ", Contenido: " << actual->publicacion.contenido
                      << ", Fecha: " << actual->publicacion.fecha << std::endl;
            actual = actual->siguiente;
        }
    }
};

#endif // LISTAPUBLICACIONES_H
