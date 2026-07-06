
#ifndef TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA1_CANCIONTRIE_H
#define TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA1_CANCIONTRIE_H
#include "NodoCancion.hpp"


class CancionTrie {
    private:
    NodoCancion* h;
    NodoCancion* cola;
    int cant;
    public:
    CancionTrie();
    bool esVacia();
    int tamano();
    NodoCancion* geth();
    void agregar(Node* nodo);
    void limpiar();

};



#endif //TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA1_CANCIONTRIE_H
