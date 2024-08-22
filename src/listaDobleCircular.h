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


