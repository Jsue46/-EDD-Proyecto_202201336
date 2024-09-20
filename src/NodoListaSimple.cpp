#include "NodoListaSimple.h"

NodoListaSimple::NodoListaSimple(const datosMatriz &datos) : datos(datos), siguiente(nullptr) {}

NodoListaSimple *NodoListaSimple::getSiguiente() const
{
    return siguiente;
}

void NodoListaSimple::setSiguiente(NodoListaSimple *siguiente)
{
    this->siguiente = siguiente;
}

datosMatriz NodoListaSimple::getDatos() const
{
    return datos;
}

Pila<DataPila> &NodoListaSimple::getPilaSolicitudes() // Asegúrate de que se use Pila como plantilla
{
    return pilaSolicitudes;
}

ListaSolicitudesEnviadas &NodoListaSimple::getListaSolicitudesEnviadas()
{
    return listaSolicitudesEnviadas;
}

NodoListaSimple::~NodoListaSimple() {}