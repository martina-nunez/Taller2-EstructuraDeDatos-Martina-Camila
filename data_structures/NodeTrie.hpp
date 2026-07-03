

#ifndef TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA_NODETRIE_H
#define TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA_NODETRIE_H
#include "Cancion.hpp"
#include "Node.hpp"

struct NodeTrie {
private:

    NodeTrie* children[27];
    bool f;
    Cancion* cancion;
public:
    NodeTrie();
    NodeTrie* getChildren(int i);
    void setChildren(int i, NodeTrie* n);
    Cancion* getCancion();

};



#endif //TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA_NODETRIE_H
