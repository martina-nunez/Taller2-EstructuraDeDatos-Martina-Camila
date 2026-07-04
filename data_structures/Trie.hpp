

#ifndef TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA_TRIE_H
#define TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA_TRIE_H
#include "NodeTrie.hpp"


class Trie {
    private:
    NodeTrie *root;
    int tenerI(char letra);
public:
    Trie();
    void agregar();
    Cancion* buscar();

};



#endif //TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA_TRIE_H
