//
// Created by camil on 7/3/2026.
//

#include "Trie.hpp"
using namespace std;
Trie::Trie() {
    root = new NodeTrie();
}

int Trie::tenerI(char letra) {
    letra = letra - 'a';
    if (letra>='a' && letra<='z') {
        return letra - 'a';
    }
    return -1;

}

void Trie::agregarc() {
    NodeTrie* actual = root;
    for (char l : letra) {
        int ind = tenerI(l);
        if (actual->getChildren(ind)== nullptr) {
            actual->setChildren(ind, new NodeTrie());
        }
        actual = actual->getChildren(ind);
    }


}

Cancion *Trie::buscar() {

}
