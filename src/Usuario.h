#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include "ListaSimple.h"
#include "Pila.h"

class Usuario
{
private:
    std::string nombres;
    std::string apellidos;
    std::string fechaNacimiento;
    std::string correo;
    std::string contrasena;
    ListaSimple solicitudesEnviadas; // Lista de solicitudes enviadas
    Pila solicitudesRecibidas;       // Pila de solicitudes recibidas

public:
    Usuario(const std::string &nombres, const std::string &apellidos, const std::string &fechaNacimiento, const std::string &correo, const std::string &contrasena)
        : nombres(nombres), apellidos(apellidos), fechaNacimiento(fechaNacimiento), correo(correo), contrasena(contrasena) {}

    // Getters
    std::string getNombres() const { return nombres; }
    std::string getApellidos() const { return apellidos; }
    std::string getFechaNacimiento() const { return fechaNacimiento; }
    std::string getCorreo() const { return correo; }
    std::string getContrasena() const { return contrasena; }

    ListaSimple &getSolicitudesEnviadas() { return solicitudesEnviadas; }
    Pila &getSolicitudesRecibidas() { return solicitudesRecibidas; }

    // Setters
    void setNombres(const std::string &nombres) { this->nombres = nombres; }
    void setApellidos(const std::string &apellidos) { this->apellidos = apellidos; }
    void setFechaNacimiento(const std::string &fechaNacimiento) { this->fechaNacimiento = fechaNacimiento; }
    void setCorreo(const std::string &correo) { this->correo = correo; }
    void setContrasena(const std::string &contrasena) { this->contrasena = contrasena; }
};

#endif // USUARIO_H