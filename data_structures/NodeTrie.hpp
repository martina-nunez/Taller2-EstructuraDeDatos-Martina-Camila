

#ifndef TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA_NODETRIE_H
#define TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA_NODETRIE_H
#include "Cancion.hpp"
#include "Node.hpp"
#include "CancionTrie.hpp"

struct NodeTrie {
private:

    NodeTrie* children[27];
    bool f;
    CancionTrie canciones;
public:
    NodeTrie();
    NodeTrie* getChildren(int i);
    void setChildren(int i, NodeTrie* n);
    void agregarCancion(Cancion* c);
    CancionTrie* getCancionTrie();

};



#endif //TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA_NODETRIE_H
