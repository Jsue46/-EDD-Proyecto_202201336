#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "NodoListaDoble.h"
#include <iostream>
using namespace std;

class ListaDoble
{
private:
    NodoListaDoble *cabeza;
    NodoListaDoble *cola;

public:
    ListaDoble() : cabeza(nullptr), cola(nullptr) {}

    // Insertar una nueva publicación al final de la lista
    void insertarFinal(const Publicacion &publicacion)
    {
        NodoListaDoble *nuevoNodo = new NodoListaDoble(publicacion);
        if (!cabeza)
        {
            cabeza = nuevoNodo;
            cola = nuevoNodo;
        }
        else
        {
            cola->setSiguiente(nuevoNodo);
            nuevoNodo->setAnterior(cola);
            cola = nuevoNodo;
        }
    }

    // Imprimir todas las publicaciones
    void imprimirPublicaciones() const
    {
        NodoListaDoble *temp = cabeza;
        while (temp)
        {
            cout << "Correo: " << temp->getPublicacion().getCorreoUsuario() << endl;
            cout << "Contenido: " << temp->getPublicacion().getContenido() << endl;
            cout << "Fecha: " << temp->getPublicacion().getFecha() << endl;
            cout << "Hora: " << temp->getPublicacion().getHora() << endl;
            cout << "-----------------------------" << endl;
            temp = temp->getSiguiente();
        }
    }

    // Eliminar todas las publicaciones
    void eliminarTodos()
    {
        while (cabeza)
        {
            NodoListaDoble *temp = cabeza;
            cabeza = cabeza->getSiguiente();
            delete temp;
        }
        cola = nullptr;
    }

    // Obtener el tamaño de la lista
    int getSize() const
    {
        int count = 0;
        NodoListaDoble *temp = cabeza;
        while (temp)
        {
            count++;
            temp = temp->getSiguiente();
        }
        return count;
    }

    // Obtener una publicación por su índice
    NodoListaDoble *getNodoPorIndice(int indice) const
    {
        NodoListaDoble *temp = cabeza;
        int count = 0;
        while (temp && count < indice)
        {
            temp = temp->getSiguiente();
            count++;
        }
        return temp;
    }

    ~ListaDoble()
    {
        eliminarTodos();
    }
};

#endif // LISTADOBLE_H
