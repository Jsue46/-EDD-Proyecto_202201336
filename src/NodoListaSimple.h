#ifndef NODOLISTASIMPLE_H
#define NODOLISTASIMPLE_H

#include "datosMatriz.h"
#include "Pila.h"
#include "ListaSolicitudesEnviadas.h"
#include "DataPila.h" // Asegúrate de incluir DataPila

class NodoListaSimple
{
private:
    datosMatriz datos;
    NodoListaSimple *siguiente;
    Pila<DataPila> pilaSolicitudes; // Asegúrate de que se use Pila como plantilla
    ListaSolicitudesEnviadas listaSolicitudesEnviadas;

public:
    NodoListaSimple(const datosMatriz &datos);
    NodoListaSimple *getSiguiente() const;
    void setSiguiente(NodoListaSimple *siguiente);
    datosMatriz getDatos() const;
    Pila<DataPila> &getPilaSolicitudes(); // Asegúrate de que se use Pila como plantilla
    ListaSolicitudesEnviadas &getListaSolicitudesEnviadas();
    ~NodoListaSimple();
};

#endif // NODOLISTASIMPLE_H