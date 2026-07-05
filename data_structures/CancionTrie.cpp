//
// Created by camil on 7/5/2026.
//

#include "CancionTrie.hpp"
ListaCancionTrie::CancionTrie() {
    h = nullptr;
}
void ListaCancionTrie::agregar(Cancion* c) {
    if (h == nullptr) {
        h = new NodoCancion(c);
    }
    NodoCancion* aux = h;
    while (aux->sigui != nullptr) {
        aux = aux->sigui;
    }
    aux->sigui = h;

}
NodoCancion* ListaCancionTrie::geth() {
    return h;
}