#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include "NodoListaSimple.h"
#include <iostream>
using namespace std;

class ListaSimple
{
private:
    NodoListaSimple *cabeza;

public:
    ListaSimple() : cabeza(nullptr) {}

    void insertarFinal(const datosMatriz &usuario)
    {
        NodoListaSimple *nuevoNodo = new NodoListaSimple(usuario);
        if (!cabeza)
        {
            cabeza = nuevoNodo;
        }
        else
        {
            NodoListaSimple *temp = cabeza;
            while (temp->getSiguiente())
            {
                temp = temp->getSiguiente();
            }
            temp->setSiguiente(nuevoNodo);
        }
    }

    NodoListaSimple *buscarUsuarioPorCorreo(const string &correo)
    {
        NodoListaSimple *temp = cabeza;
        while (temp)
        {
            if (temp->getDatos().getCorreo() == correo)
            {
                return temp;
            }
            temp = temp->getSiguiente();
        }
        return nullptr;
    }

    void agregarUsuario(datosMatriz datos)
    {
        NodoListaSimple *nuevoNodo = new NodoListaSimple(datos);
        if (!cabeza)
        {
            cabeza = nuevoNodo;
        }
        else
        {
            NodoListaSimple *temp = cabeza;
            while (temp->getSiguiente())
            {
                temp = temp->getSiguiente();
            }
            temp->setSiguiente(nuevoNodo);
        }
    }

    NodoListaSimple *buscarPorCorreo(const std::string &correo)
    {
        NodoListaSimple *temp = cabeza;
        while (temp)
        {
            if (temp->getDatos().getCorreo() == correo)
            {
                return temp;
            }
            temp = temp->getSiguiente();
        }
        return nullptr;
    }

    void eliminarPorCorreo(const string &correo)
    {
        if (!cabeza)
            return;

        if (cabeza->getDatos().getCorreo() == correo)
        {
            NodoListaSimple *temp = cabeza;
            cabeza = cabeza->getSiguiente();
            delete temp;
            return;
        }

        NodoListaSimple *temp = cabeza;
        while (temp->getSiguiente() && temp->getSiguiente()->getDatos().getCorreo() != correo)
        {
            temp = temp->getSiguiente();
        }

        if (temp->getSiguiente())
        {
            NodoListaSimple *nodoAEliminar = temp->getSiguiente();
            temp->setSiguiente(nodoAEliminar->getSiguiente());
            delete nodoAEliminar;
        }
    }

    int getSize()
    {
        int count = 0;
        NodoListaSimple *temp = cabeza;
        while (temp)
        {
            count++;
            temp = temp->getSiguiente();
        }
        return count;
    }

    void eliminarTodos()
    {
        while (cabeza)
        {
            NodoListaSimple *temp = cabeza;
            cabeza = cabeza->getSiguiente();
            delete temp;
        }
    }

    void eliminarNodoPorIndice(int indice)
    {
        if (indice == 0 && cabeza)
        {
            NodoListaSimple *temp = cabeza;
            cabeza = cabeza->getSiguiente();
            delete temp;
            return;
        }

        NodoListaSimple *temp = cabeza;
        int count = 0;
        while (temp && count < indice - 1)
        {
            temp = temp->getSiguiente();
            count++;
        }

        if (temp && temp->getSiguiente())
        {
            NodoListaSimple *nodoAEliminar = temp->getSiguiente();
            temp->setSiguiente(nodoAEliminar->getSiguiente());
            delete nodoAEliminar;
        }
    }

    NodoListaSimple *getHead()
    {
        return cabeza;
    }

    void agregarNodo(const datosMatriz &usuario)
    {
        insertarFinal(usuario);
    }

    void eliminarNodo(const string &usuario)
    {
        eliminarPorCorreo(usuario);
    }

    // Nueva función añadida
    NodoListaSimple *getNodoPorIndice(int indice)
    {
        NodoListaSimple *temp = cabeza;
        int count = 0;
        while (temp && count < indice)
        {
            temp = temp->getSiguiente();
            count++;
        }
        return temp;
    }
};

#endif // LISTASIMPLE_H