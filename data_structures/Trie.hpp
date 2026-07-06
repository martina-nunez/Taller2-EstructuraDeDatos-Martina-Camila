#ifndef TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA_TRIE_H
#define TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA_TRIE_H
#include "NodeTrie.hpp"
#include <string>

class Trie {
    private:
        NodeTrie *root;
        int tenerI(char letra);
        void agregarP(std::string  letra,Node* nodo);
    public:
        Trie();
        void agregar(Node* nodo);
        CancionTrie* buscar(std::string letra);
};

#endif //TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA_TRIE_H