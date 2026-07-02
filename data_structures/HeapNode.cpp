#include "HeapNode.hpp"

HeapNode::HeapNode(){
    cancion = nullptr;
}

HeapNode::HeapNode(Cancion* cancion){
    this->cancion = cancion;
}

Cancion* HeapNode::getCancion(){
    return cancion;
}

void HeapNode::setCancion(Cancion* cancion){
    this->cancion = cancion;
}

