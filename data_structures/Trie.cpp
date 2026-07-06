

#include "Trie.hpp"
using namespace std;
Trie::Trie() {
    root = new NodeTrie();
}

int Trie::tenerI(char letra) {
    letra = tolower(letra);
    if (letra>='a' && letra<='z') {
        return letra - 'a';
    }
    return -1;

}

void Trie::agregarP(string letra, Node* node) {
    NodeTrie* actual = root;
    for (char l : letra) {
        int ind = tenerI(l);
        if (ind == -1) {
            continue;
        }
        if (actual->getChildren(ind)== nullptr) {
            actual->setChildren(ind, new NodeTrie());
        }
        actual = actual->getChildren(ind);
        actual->getCancionTrie()->agregar(node);
    }
    actual->setFin(true);
}
void Trie::agregar(Node* nodo) {
    string nombre = nodo->getValue()->getNombre();
    string artista = nodo->getValue()->getArtista();
    for (int i = 0; i < nombre.size(); i++) {
        agregarP(artista.substr(i), nodo);
    }

}
CancionTrie* Trie::buscar(string p) {
    Trie* actual = root;
    for (char l : p) {
        int ind = tenerI(l);
        if (ind == -1) {
            continue;
        }
        if (actual->getChildren(ind)== nullptr) {
            return nullptr;
        }
        actual = actual->getChildren(ind);
    }
    return actual->getCancionTrie();
}
