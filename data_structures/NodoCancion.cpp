
#include "NodoCancion.hpp"
NodoCancion::NodoCancion(Nodo* nodo) {
    this->nodo = nodo;
    siguiente = nullptr;
}

Node *NodoCancion::getNodo() {
    return nodo;
}
void NodoCancion::setNodo(Node* nodo) {
    this->nodo = nodo;
}
void NodoCancion::setSiguiente(Node* siguiente) {
    this->siguiente = siguiente;
}
NodoCancion* NodoCancion::getSiguiente() {
    return siguiente;
}
