#ifndef TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA1_LISTCANCIONES_H
#define TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA1_LISTCANCIONES_H
#include "Cancion.hpp"
#include "Node.hpp"

class NodoCancion {
    private:
        Node* nodo;
        NodoCancion* siguiente;
    public:
        NodoCancion(Node* nodo);
        Node* getNodo();
        void setNodo(Node* nodo);
        NodoCancion* getSiguiente();
        void setSiguiente(NodoCancion* siguiente);
};

#endif //TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA1_LISTCANCIONES_H