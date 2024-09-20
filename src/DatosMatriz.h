#ifndef DATOSMATRIZ_H
#define DATOSMATRIZ_H

#include <string>
using namespace std;

class datosMatriz
{
public:
    string nombres;
    string apellidos;
    string fechaNacimiento;
    string correo;
    string contrasena;
    string correoEmisor; // Nuevo atributo

    datosMatriz() = default;
    datosMatriz(string nombres, string apellidos, string fechaNacimiento, string correo, string contrasena, string correoEmisor = "")
        : nombres(nombres), apellidos(apellidos), fechaNacimiento(fechaNacimiento), correo(correo), contrasena(contrasena), correoEmisor(correoEmisor) {}

    string getCorreo() const
    {
        return correo;
    }
    string getNombres() const
    {
        return nombres;
    }
    string getApellidos() const
    {
        return apellidos;
    }
    string getFechaNacimiento() const
    {
        return fechaNacimiento;
    }
    string getContrasena() const
    {
        return contrasena;
    }
    string getCorreoEmisor() const
    {
        return correoEmisor;
    }
    void setCorreoEmisor(const string &nuevoCorreoEmisor)
    {
        correoEmisor = nuevoCorreoEmisor;
    }
};

#endif // DATOSMATRIZ_H
