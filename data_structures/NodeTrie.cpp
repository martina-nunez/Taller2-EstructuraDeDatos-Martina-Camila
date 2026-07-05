
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
CancionTrie* NodeTrie::getCancionTrie() {
    return &canciones;
}
bool NodeTrie::fin() {
    {
        return f;
    }
}
void NodeTrie::setFin(bool f) {
    this->f = f;
}
