#ifndef DATAPILA_H
#define DATAPILA_H

#include <string>

class DataPila
{
private:
    std::string correoEmisor;
    std::string correoReceptor; // Nuevo atributo para almacenar el correo del receptor

public:
    // Constructor actualizado para incluir el correo del receptor
    DataPila(const std::string &correoEmisor, const std::string &correoReceptor)
        : correoEmisor(correoEmisor), correoReceptor(correoReceptor) {}

    // Getter para el correo del emisor
    std::string getCorreoEmisor() const
    {
        return correoEmisor;
    }

    // Nuevo getter para el correo del receptor
    std::string getCorreoReceptor() const
    {
        return correoReceptor;
    }
};

#endif // DATAPILA_H
