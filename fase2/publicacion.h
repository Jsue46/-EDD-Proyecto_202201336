#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <string>
#include "publicacion.h"
using namespace std;

class Publicacion
{
private:
    string correoUsuario; // Correo del usuario que realiza la publicación
    string contenido;     // Contenido de la publicación
    string fecha;         // Fecha de la publicación
    string hora;          // Hora de la publicación

public:
    // Constructor
    Publicacion(const string &correo, const string &cont, const string &fechaPublicacion, const string &horaPublicacion)
        : correoUsuario(correo), contenido(cont), fecha(fechaPublicacion), hora(horaPublicacion) {}

    // Métodos para obtener los atributos
    string getCorreoUsuario() const { return correoUsuario; }
    string getContenido() const { return contenido; }
    string getFecha() const { return fecha; }
    string getHora() const { return hora; }

    // Métodos para modificar los atributos
    void setCorreoUsuario(const string &correo) { correoUsuario = correo; }
    void setContenido(const string &cont) { contenido = cont; }
    void setFecha(const string &fechaPublicacion) { fecha = fechaPublicacion; }
    void setHora(const string &horaPublicacion) { hora = horaPublicacion; }
};

#endif // PUBLICACION_H

