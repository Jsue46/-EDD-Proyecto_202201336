#include "listaDobleCircular.h"
using namespace std;
// Implementación del destructor
ListaCircularPublicaciones::~ListaCircularPublicaciones() {
    liberarMemoria();
}

// Método para liberar memoria de la lista
void ListaCircularPublicaciones::liberarMemoria() {
    if (pui != nullptr) {
        Publicacion* actual = pui;
        do {
            Publicacion* siguiente = actual->derecho;
            delete actual;
            actual = siguiente;
        } while (actual != pui);
        pui = nullptr;
        puf = nullptr;
    }
}


// Implementación de insertarPublicacion
void ListaCircularPublicaciones::insertarPublicacionD(const std::string& mail, const std::string& content, const std::string& date, const std::string& hour) {
    if (pui == nullptr) {
        pui = new Publicacion;

        pui->contenido = content;
        pui->correo = mail;
        pui->fecha = date;
        pui->hora = hour;

        pui->derecho = pui;
        pui->izquierdo = pui;
        puf = pui;
    } else {
        pua = new Publicacion;

        pua->contenido = content;
        pua->correo = mail;
        pua->fecha = date;
        pua->hora = hour;

        puf->derecho = pua;
        pua->derecho = pui;
        pua->izquierdo = puf;
        puf = pua;
        pui->izquierdo = puf;
    }
}

/