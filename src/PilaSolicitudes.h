#ifndef PILASOLICITUDES_H
#define PILASOLICITUDES_H

#include <stack>
#include "DataPila.h"

class PilaSolicitudes
{
private:
    stack<DataPila> pila;

public:
    void push(const DataPila &solicitud)
    {
        pila.push(solicitud);
    }

    bool contiene(const string &correoReceptor) const
    {
        stack<DataPila> copia = pila;
        while (!copia.empty())
        {
            if (copia.top().getCorreoEmisor() == correoReceptor)
                return true;
            copia.pop();
        }
        return false;
    }
};

#endif // PILASOLICITUDES_H
