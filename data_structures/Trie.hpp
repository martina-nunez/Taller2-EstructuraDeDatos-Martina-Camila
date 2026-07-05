

#ifndef TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA_TRIE_H
#define TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA_TRIE_H
#include "NodeTrie.hpp"


class Trie {
    private:
    NodeTrie *root;
    int tenerI(char letra);
    void agregarC(string letra,Cancion* c);
public:
    Trie();
    void agregarc();
    CancionTrie* buscar(string letra);
};



#endif //TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA_TRIE_H
