

#include "CancionTrie.hpp"
CancionTrie::CancionTrie() {
    h = nullptr;
    cola = nullptr;
    cant = 0;
}
bool CancionTrie::esVacia() {
    return h == nullptr;
}

int CancionTrie::tamano() {
    return cant;
}
NodoCancion* CancionTrie::geth() {
    return h;
}

void CancionTrie::agregar(Node *nodo) {
    if (nodo == nullptr) {
        return;
    }
    NodoCancion* aux = h;
    while (aux != nullptr) {
        if (aux->getNodo() == nodo) {
            return;
        }
        aux = aux->getSiguiente();
    }
    NodoCancion* aux2 = new NodoCancion(nodo);
    if (h == nullptr) {
        h = aux2;
        cola = aux2;
    } else {
        cola->setSiguiente(aux2);
        cola = aux2;
    }
    cant++;
}

void CancionTrie::limpiar() {
    NodoCancion* aux = h;
    while (aux != nullptr) {
        NodoCancion* aux2 = aux->getSiguiente();
        delete aux;
        aux = aux2;
    }
    h = nullptr;
    cola = nullptr;
    cant = 0;

}
