#ifndef MENU_H
#define MENU_H

#pragma once
#include <fstream>
#include <iostream>
#include "ListaSimple.h"
#include "datosMatriz.h"
#include "Pila.h"
#include "DataPila.h"
#include "ListaSolicitudesEnviadas.h"
#include "json.hpp"
#include "Publicacion.h"      
#include "NodoPublicacion.h"  
#include "ListaPublicaciones.h"  

//#include <nlohmann/json.hpp/src>
//#include <nlohmann/json.hpp/src>
//#include <nlohmann/json.hpp>
//#include <nlohmann/json.hpp/src>
//#include <nlohmann/json.hpp>


//#include <nlohmann/json.hpp>
using json = nlohmann::json;


using namespace std;


class Menu
{
private:
    ListaSimple listaUsuarios;
    NodoListaSimple *usuarioActual; // Puntero al nodo del usuario actual
    ListaPublicaciones listaPublicaciones; // Para almacenar las publicaciones
    NodoPublicacion *publicacionActual;     // Puntero al nodo de la publicación actual


public:
    Menu() : usuarioActual(nullptr) {}

    void Display();

    // Funciones auxiliares para manejar las opciones del menú
    void cargarUsuariosDesdeJSON();
    void cargarPublicacionesDesdeJSON();
    void mostrarMenu();
    void mostrarMenuAdmin();
    bool manejarOpcionesAdmin(int opcionAdmin); // Nueva función para manejar opciones del admin
    void mostrarMenuUsuario();
    void enviarSolicitud();
    bool manejarSubMenuUsuario(int opcionUsuario); 
    int iniciarSesion();                         
    void registrarse();
    void eliminarCuenta(); 
    void mostrarInformacion();
    void enviarSolicitudes(); 
    void verSolicitudes();    
    void aceptarSolicitud();  
    void rechazarSolicitud(); 
    void salir();
};

void Menu::cargarPublicacionesDesdeJSON()
{
    string path;
    cout << "Direccion del archivo: ";
    getline(cin >> ws, path);  // Asegura que se lea el path correctamente.

    ifstream archivo(path);
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo. Verifique el path e intente nuevamente." << endl;
        return;
    }

    json datosJSON;
    try {
        archivo >> datosJSON;
    } catch (json::parse_error &e) {
        cout << "Error al parsear el archivo JSON: " << e.what() << endl;
        archivo.close();
        return;
    }

    for (const auto &item : datosJSON)
    {
        // Verificar que los campos existan antes de acceder a ellos
        if (item.contains("correo") && item.contains("contenido") && 
            item.contains("fecha") && item.contains("hora"))
        {
            string correo = item["correo"];
            string contenido = item["contenido"];
            string fecha = item["fecha"];
            string hora = item["hora"];

            // Crear una nueva publicación y agregarla a la lista de publicaciones
            Publicacion nuevaPublicacion(correo, contenido, fecha, hora);
            listaPublicaciones.agregarPublicacion(nuevaPublicacion);
        }
        else
        {
            cout << "Advertencia: El formato del archivo JSON es incorrecto o faltan campos." << endl;
        }
    }

    archivo.close();
    cout << "Carga masiva de publicaciones exitosa." << endl;

    // Imprimir las publicaciones cargadas
    NodoPublicacion* actual = listaPublicaciones.getCabeza();
    int indice = 1;
    while (actual != nullptr)
    {
        cout << "Publicación " << indice << ": " << endl;
        cout << "Correo: " << actual->publicacion.getCorreoUsuario() << endl;
        cout << "Contenido: " << actual->publicacion.getContenido() << endl;
        cout << "Fecha: " << actual->publicacion.getFecha() << endl;
        cout << "Hora: " << actual->publicacion.getHora() << endl;
        cout << "-------------------------------" << endl;
        actual = actual->siguiente;
        indice++;
    }
}


void Menu::cargarUsuariosDesdeJSON()
{
    string path;
    cout << "Direccion del archivo";
    getline(cin >> ws, path);  // Esto asegura que se lea el path correctamente.

    ifstream archivo(path);
    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo. Verifique el path e intente nuevamente." << endl;
        return;
    }

    json datosJSON;
    try {
        archivo >> datosJSON;
    } catch (json::parse_error &e) {
        cout << "Error al parsear el archivo JSON: " << e.what() << endl;
        archivo.close();
        return;
    }

    for (const auto &item : datosJSON)
    {
        // Asegurarse de que los campos existen en cada objeto JSON antes de acceder a ellos
        if (item.contains("nombres") && item.contains("apellidos") && 
            item.contains("fecha_de_nacimiento") && item.contains("correo") && 
            item.contains("contraseña"))
        {
            string nombres = item["nombres"];
            string apellidos = item["apellidos"];
            string fechaNacimiento = item["fecha_de_nacimiento"];
            string correo = item["correo"];
            string contrasena = item["contraseña"];

            // Crear un nuevo usuario y agregarlo a la lista de usuarios
            datosMatriz nuevoUsuario(nombres, apellidos, fechaNacimiento, correo, contrasena);
            listaUsuarios.agregarUsuario(nuevoUsuario);
        }
        else
        {
            cout << "Advertencia: El formato del archivo JSON es incorrecto o faltan campos." << endl;
        }
    }

    archivo.close();
    cout << "Carga masiva de usuarios exitosa." << endl;

    // Imprimir los datos de los usuarios cargados
    int size = listaUsuarios.getSize();
    for (int i = 0; i < size; i++)
    {
        NodoListaSimple *usuario = listaUsuarios.getNodoPorIndice(i);
        if (usuario)
        {
            cout << "Usuario " << (i + 1) << ": " << endl;
            cout << "Nombres: " << usuario->getDatos().getNombres() << endl;
            cout << "Apellidos: " << usuario->getDatos().getApellidos() << endl;
            cout << "Fecha de Nacimiento: " << usuario->getDatos().getFechaNacimiento() << endl;
            cout << "Correo: " << usuario->getDatos().getCorreo() << endl;
            cout << "Contraseña: " << usuario->getDatos().getContrasena() << endl;
            cout << "-------------------------------" << endl;
        }
    }
}


// Funciones auxiliares para manejar las opciones del menú
void Menu::mostrarMenu()
{
    cout << " ================== Interfaz ==================" << endl;
    cout << " 1. Iniciar sesion                        " << endl;
    cout << " 2. Registrarse                           " << endl;
    cout << " 3. Informacion                           " << endl;
    cout << " 4. Salir                                 " << endl;
    cout << "Seleccione una opcion a realizar           " << endl;
    cout << " ==============================================" << endl;
    
}

void Menu::mostrarMenuAdmin()
{
    cout << " ============== MODULO ADMINISTRADOR ==============" << endl;
    cout << " 1. Carga de usuarios                     " << endl;
    cout << " 2. Carga de relaciones                   " << endl;
    cout << " 3. Carga de publicaciones                " << endl;
    cout << " 4. Gestionar usuarios                    " << endl;
    cout << "    a. Eliminar usuarios                  " << endl;
    cout << " 5. Reportes                              " << endl;
    cout << " 6. Salir                                 " << endl;
    cout << "Selecciona una opcion a realizar" << endl;
    cout << " ================================================" << endl;
    
}

bool Menu::manejarOpcionesAdmin(int opcionAdmin)
{
    switch (opcionAdmin)
    {
    case 1:
        
        cargarUsuariosDesdeJSON();
        cout << "--------------------------------" << endl;
        break;
    case 2:
        
        cout << "------" << endl;
        break;
    case 3:
        cout << "En Progreso" << endl;
        break;
    case 4:
    {
        cout << "Gestionar usuarios:" << endl;
        cout << "a) Eliminar usuarios" << endl;
        char subOpcionAdmin;
        cin >> subOpcionAdmin;
        if (subOpcionAdmin == 'a' || subOpcionAdmin == 'A')
        {
            int size = listaUsuarios.getSize();
            for (int i = 0; i < size; i++)
            {
                NodoListaSimple *usuario = listaUsuarios.getNodoPorIndice(i);
                if (usuario)
                {
                    cout << i + 1 << ") " << usuario->getDatos().getCorreo() << endl;
                }
            }
            cout << size + 1 << ") Eliminar todos" << endl;
            cout << "Seleccione un usuario para eliminar: ";
            int seleccion;
            cin >> seleccion;
            if (seleccion == size + 1)
            {
                listaUsuarios.eliminarTodos();
                cout << "Todos los usuarios han sido eliminados." << endl;
            }
            else if (seleccion > 0 && seleccion <= size)
            {
                listaUsuarios.eliminarNodoPorIndice(seleccion - 1);
                cout << "Usuario eliminado." << endl;
            }
            else
            {
                cout << "Seleccion no valida." << endl;
            }
        }
        else
        {
            cout << "Opcion no valida." << endl;
        }
        break;
    }
    case 5:
        cout << "No dio tiempo aux" << endl;
        break;
    case 6:
        return false; // Indica que se debe salir del módulo administrador
    default:
        cout << "Opcion no valida." << endl;
        break;
    }
    return true; // Continuar en el módulo administrador
}

void Menu::mostrarMenuUsuario()
{
    cout << " =============== MODULO USUARIO ================" << endl;
    cout << " 1. Perfil                                 " << endl;
    cout << "    a. Ver perfil                          " << endl;
    cout << "    b. Eliminar cuenta                     " << endl;
    cout << " 2. Solicitudes                            " << endl;
    cout << "    a. Ver solicitudes                     " << endl;
    cout << "       1. Aceptar                          " << endl;
    cout << "       2. Rechazar                         " << endl;
    cout << "    b. Enviar                              " << endl;
    cout << " 3. Publicaciones                          " << endl;
    cout << "    a. Ver todas                           " << endl;
    cout << "    b. Crear                               " << endl;
    cout << "    c. Eliminar                            " << endl;
    cout << " 4. Reportes                               " << endl;
    cout << " 5. Salir                                  " << endl;
    cout << " seleccione opcion a realizar xd" << endl;
    cout << " ==============================================" << endl;
   
}

void Menu::enviarSolicitud()
{
    if (!usuarioActual)
    {
        cout << "Debe iniciar sesion para enviar solicitudes de amistad." << endl;
        return;
    }

    int size = listaUsuarios.getSize();
    vector<NodoListaSimple *> usuariosDisponibles;

    // Listar todos los usuarios excepto el usuario actual
    cout << "Posibles Amigos:" << endl;
    for (int i = 0; i < size; i++)
    {
        NodoListaSimple *usuario = listaUsuarios.getNodoPorIndice(i);
        if (usuario && usuario != usuarioActual)
        {
            usuariosDisponibles.push_back(usuario);
            cout << usuariosDisponibles.size() << ") " << usuario->getDatos().getCorreo() << endl;
        }
    }

    if (usuariosDisponibles.empty())
    {
        cout << "Aun no hay usuarios" << endl;
        return;
    }

    cout << "Seleccione el número del usuario al que desea enviar la solicitud: ";
    int seleccion;
    cin >> seleccion;

    if (seleccion > 0 && seleccion <= usuariosDisponibles.size())
    {
        NodoListaSimple *receptor = usuariosDisponibles[seleccion - 1];

        // Verificar que el usuario no tenga una solicitud pendiente de este emisor
        if (receptor->getPilaSolicitudes().contiene(usuarioActual->getDatos().getCorreo()))
        {
            cout << "No se ha podido mandar la solicitud a " << receptor->getDatos().getCorreo() << " porque ya tiene una solicitud pendiente." << endl;
            return;
        }

        // Verificar que no haya una solicitud enviada anteriormente al mismo usuario
        if (usuarioActual->getListaSolicitudesEnviadas().contiene(receptor->getDatos().getCorreo()))
        {
            cout << "Ya envio una solicitud a este usuario anteriormente." << endl;
            return;
        }

        // Enviar solicitud
        DataPila solicitud(usuarioActual->getDatos().getCorreo(), receptor->getDatos().getCorreo());
        receptor->getPilaSolicitudes().push(solicitud);
        usuarioActual->getListaSolicitudesEnviadas().agregarSolicitud(solicitud);

        cout << "Solicitud de amistad enviada a " << receptor->getDatos().getCorreo() << " correctamente." << endl;
    }
    else
    {
        cout << "Seleccion no valida." << endl;
    }
}

void Menu::verSolicitudes()
{
    if (!usuarioActual)
    {
        cout << "Debe iniciar sesion para ver las solicitudes de amistad." << endl;
        return;
    }

    if (usuarioActual->getPilaSolicitudes().estaVacia())
    {
        cout << "No tiene solicitudes de amistad pendientes." << endl;
        return;
    }

    cout << "Solicitudes de amistad recibidas:" << endl;
    Pila<DataPila> &solicitudes = usuarioActual->getPilaSolicitudes();
    Pila<DataPila> solicitudesTemp;

    while (!solicitudes.estaVacia())
    {
        DataPila solicitud = solicitudes.pop();
        cout << solicitud.getCorreoEmisor() << endl; // Corregido a getCorreoEmisor
        solicitudesTemp.push(solicitud);
    }

    // Devolver las solicitudes a la pila original
    while (!solicitudesTemp.estaVacia())
    {
        solicitudes.push(solicitudesTemp.pop());
    }
}

void Menu::aceptarSolicitud()
{
    if (!usuarioActual)
    {
        cout << "Debe iniciar sesion para aceptar solicitudes de amistad." << endl;
        return;
    }

    if (usuarioActual->getPilaSolicitudes().estaVacia())
    {
        cout << "No tiene solicitudes de amistad pendientes." << endl;
        return;
    }

    cout << "Solicitudes de amistad recibidas:" << endl;
    Pila<DataPila> &solicitudes = usuarioActual->getPilaSolicitudes();
    Pila<DataPila> solicitudesTemp;
    int contador = 0;

    while (!solicitudes.estaVacia())
    {
        DataPila solicitud = solicitudes.pop();
        solicitudesTemp.push(solicitud);
        cout << ++contador << ") " << solicitud.getCorreoEmisor() << endl;
    }

    // Devolver las solicitudes a la pila original
    while (!solicitudesTemp.estaVacia())
    {
        solicitudes.push(solicitudesTemp.pop());
    }

    cout << "Seleccione el número de la solicitud que desea aceptar: ";
    int seleccion;
    cin >> seleccion;

    if (seleccion > 0 && seleccion <= contador)
    {
        // Aceptar solicitud (Eliminar de la pila)
        Pila<DataPila> nuevaPila;
        for (int i = 1; i <= contador; i++)
        {
            DataPila solicitud = solicitudes.pop();
            if (i != seleccion)
            {
                nuevaPila.push(solicitud);
            }
            else
            {
                // Aquí puedes agregar la lógica para agregar al amigo
                cout << "Solicitud de amistad de " << solicitud.getCorreoEmisor() << " aceptada." << endl;
            }
        }

        // Devolver las solicitudes no aceptadas a la pila original
        while (!nuevaPila.estaVacia())
        {
            solicitudes.push(nuevaPila.pop());
        }
    }
    else
    {
        cout << "Seleccion no valida." << endl;
    }
}

void Menu::rechazarSolicitud()
{
    if (!usuarioActual)
    {
        cout << "Debe iniciar sesion para rechazar solicitudes de amistad." << endl;
        return;
    }

    if (usuarioActual->getPilaSolicitudes().estaVacia())
    {
        cout << "No tiene solicitudes de amistad pendientes." << endl;
        return;
    }

    cout << "Solicitudes de amistad recibidas:" << endl;
    Pila<DataPila> &solicitudes = usuarioActual->getPilaSolicitudes();
    Pila<DataPila> solicitudesTemp;
    int contador = 0;

    while (!solicitudes.estaVacia())
    {
        DataPila solicitud = solicitudes.pop();
        solicitudesTemp.push(solicitud);
        cout << ++contador << ") " << solicitud.getCorreoEmisor() << endl;
    }

    // Devolver las solicitudes a la pila original
    while (!solicitudesTemp.estaVacia())
    {
        solicitudes.push(solicitudesTemp.pop());
    }

    cout << "Seleccione el número de la solicitud que desea rechazar: ";
    int seleccion;
    cin >> seleccion;

    if (seleccion > 0 && seleccion <= contador)
    {
        // Rechazar solicitud (Eliminar de la pila)
        Pila<DataPila> nuevaPila;
        for (int i = 1; i <= contador; i++)
        {
            DataPila solicitud = solicitudes.pop();
            if (i != seleccion)
            {
                nuevaPila.push(solicitud);
            }
            else
            {
                cout << "Solicitud de amistad de " << solicitud.getCorreoEmisor() << " rechazada." << endl;
            }
        }

        // Devolver las solicitudes no rechazadas a la pila original
        while (!nuevaPila.estaVacia())
        {
            solicitudes.push(nuevaPila.pop());
        }
    }
    else
    {
        cout << "Seleccion no válida." << endl;
    }
}

//////
bool Menu::manejarSubMenuUsuario(int opcionUsuario)
{
    switch (opcionUsuario)
    {
    case 1:
        cout << "Perfil:" << endl;
        cout << "a) Ver perfil" << endl;
        cout << "b) Eliminar cuenta" << endl;
        cout << "Seleccione una opcion: ";
        char opcionPerfil;
        cin >> opcionPerfil;
        if (opcionPerfil == 'a' || opcionPerfil == 'A')
        {
            // Lógica para ver perfil
            cout << "Mostrando perfil del usuario..." << endl;
            if (usuarioActual)
            
            {
                cout << "Nombres: " << usuarioActual->getDatos().getNombres() << endl;
                cout << "Apellidos: " << usuarioActual->getDatos().getApellidos() << endl;
                cout << "Correo: " << usuarioActual->getDatos().getCorreo() << endl;
            }
            else
            {
                cout << "No ha iniciado sesion." << endl;
            }
        }
        else if (opcionPerfil == 'b' || opcionPerfil == 'B')
        {
            // Lógica para eliminar cuenta
            if (usuarioActual)
            {
                eliminarCuenta();
                cout << "Cuenta eliminada correctamente." << endl;
                usuarioActual = nullptr;
                return false; // Salir del módulo usuario
            }
            else
            {
                cout << "No ha iniciado sesion." << endl;
            }
        }
        break;
    case 2:
        cout << "Solicitudes:" << endl;
        cout << "a) Ver solicitudes" << endl;
        cout << "   i) Aceptar" << endl;
        cout << "   j) Rechazar" << endl;
        cout << "b) Enviar" << endl;
        cout << "Seleccione una opcion: ";
        char opcionSolicitudes;
        cin >> opcionSolicitudes;
        if (opcionSolicitudes == 'a' || opcionSolicitudes == 'A')
        {
            cout << "Ver solicitudes:" << endl;
            if (usuarioActual)
            {
                Pila<DataPila> &solicitudes = usuarioActual->getPilaSolicitudes();
                if (solicitudes.estaVacia())
                {
                    cout << "No tiene solicitudes de amistad pendientes." << endl;
                }
                else
                {
                    Pila<DataPila> solicitudesTemp;
                    int contador = 0;

                    while (!solicitudes.estaVacia())
                    {
                        DataPila solicitud = solicitudes.pop();
                        solicitudesTemp.push(solicitud);
                        cout << ++contador << ") " << solicitud.getCorreoEmisor() << endl;
                    }

                    // Devolver las solicitudes a la pila original
                    while (!solicitudesTemp.estaVacia())
                    {
                        solicitudes.push(solicitudesTemp.pop());
                    }

                    cout << "1. Aceptar" << endl;
                    cout << "2. Rechazar" << endl;
                    cout << "Seleccione una opcion: ";
                    char opcionVerSolicitudes;
                    cin >> opcionVerSolicitudes;
                    if (opcionVerSolicitudes == '1' )
                    {
                        aceptarSolicitud();
                    }
                    else if (opcionVerSolicitudes == '2')
                    {
                        rechazarSolicitud();
                    }
                }
            }
            else
            {
                cout << "No ha iniciado sesion." << endl;
            }
        }
        else if (opcionSolicitudes == 'b' || opcionSolicitudes == 'B')
        {
            enviarSolicitud();
        }
        break;
    case 3:
        // Lógica para manejar publicaciones
        break;
    case 4:
        // Lógica para manejar reportes
        break;
    case 5:
        return false; // Salir del módulo usuario
    default:
        cout << "Opcion no valida." << endl;
    }
    return true; // Mantenerse en el módulo usuario
}

int Menu::iniciarSesion()
{
    string correo, contrasena;

    cout << "Ingrese su correo: ";
    cin >> correo;
    cout << "Ingrese su contrasena: ";
    cin >> contrasena;

    if (correo == "admin@gmail.com" && contrasena == "EDD2S2024")
    {
        cout << "Bienvenido Administrador" << endl;
        return 2; // 2 representa al administrador
    }
    else
    {
        NodoListaSimple *usuario = listaUsuarios.buscarPorCorreo(correo);
        if (usuario != nullptr && usuario->getDatos().getContrasena() == contrasena)
        {
            cout << "Inicio de sesion como usuario exitoso." << endl;
            usuarioActual = usuario;
            return 1; // 1 representa al usuario
        }
    }

    cout << "Credenciales incorrectas. Intente de nuevo." << endl;
    return 0; // 0 representa el fallo en el inicio de sesión
}

void Menu::registrarse()
{
    string nombres, apellidos, fechaNacimiento, correo, contrasena;

    cout << "Ingrese sus nombres: ";
    cin.ignore(); // Ignorar el salto de línea pendiente
    getline(cin, nombres);
    cout << "Ingrese sus apellidos: ";
    getline(cin, apellidos);
    cout << "Ingrese su fecha de nacimiento Formato(dia/mes/año): ";
    getline(cin, fechaNacimiento);
    cout << "Ingrese su correo: ";
    getline(cin, correo);

    // Verificar si el correo ya está registrado
    NodoListaSimple *usuarioExistente = listaUsuarios.buscarPorCorreo(correo);
    if (usuarioExistente != nullptr)
    {
        cout << "Correo en Uso" << endl;
        return;
    }

    cout << "Ingrese su contrasena: ";
    getline(cin, contrasena);

    datosMatriz nuevoUsuario(nombres, apellidos, fechaNacimiento, correo, contrasena);
    listaUsuarios.agregarUsuario(nuevoUsuario);

    cout << "Registro exitoso." << endl;
}

void Menu::eliminarCuenta()
{
    if (usuarioActual)
    {
        string correo = usuarioActual->getDatos().getCorreo();
        listaUsuarios.eliminarPorCorreo(correo);
        cout << "Cuenta eliminada " << endl;
        usuarioActual = nullptr; // Reiniciar el puntero del usuario actual
    }
}

void Menu::mostrarInformacion()
{
    cout << "Estuardo Josué Vaquiax Reyes" << endl;
    cout << "202201336" << endl;
    cout << "Estructura de Datos" << endl;
    cout << "Seccion: A" << endl;
}

void Menu::salir()
{
    cout << "Vuelve Pronto!" << endl;
}

// Función principal del menú
void Menu::Display()
{
    bool continuar = true;
    while (continuar)
    {
        mostrarMenu();
        int opcion;
        cin >> opcion;

        switch (opcion)
        {
        case 1:
        {
            int tipoUsuario = iniciarSesion();
            if (tipoUsuario == 1)
            {
                // Usuario
                bool continuarUsuario = true;
                while (continuarUsuario)
                {
                    mostrarMenuUsuario();
                    int opcionUsuario;
                    cin >> opcionUsuario;
                    continuarUsuario = manejarSubMenuUsuario(opcionUsuario);
                }
            }
            else if (tipoUsuario == 2)
            {
                // Administrador
                bool continuarAdmin = true;
                while (continuarAdmin)
                {
                    mostrarMenuAdmin();
                    int opcionAdmin;
                    cin >> opcionAdmin;
                    continuarAdmin = manejarOpcionesAdmin(opcionAdmin);
                }
            }
            break;
        }
        case 2:
            registrarse();
            break;
        case 3:
            mostrarInformacion();
            break;
        case 4:
            salir();
            continuar = false;
            break;
        default:
            cout << "Opcion no valida. Intente de nuevo." << endl;
            break;
        }
    }
}

#endif // Menu_H
