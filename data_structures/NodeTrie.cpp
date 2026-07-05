
#include "NodeTrie.hpp"
NodeTrie::NodeTrie() {
    f = false;
    for (int i = 0; i < 27; i++) {
        children[i] = nullptr;
    }
}
NodeTrie* NodeTrie::getChild(int i) {
    return children[i];
}
void NodeTrie::setChild(int i, NodeTrie* n) {
    children[i] = n;
}

void NodeTrie::agregarCancion(Cancion *c) {
    canciones.agregar(c);
}
CancionTrie* NodeTrie::getCancion() {
    return canciones;
}