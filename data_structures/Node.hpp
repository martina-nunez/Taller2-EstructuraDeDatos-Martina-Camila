#pragma once
#include "../classes/cancion.hpp"

class Node {
private:
    Cancion* value;
    Node* next;
    Node* prev;
public:
    Node(Cancion* value);
    Cancion* getValue();
    Node* getNext();
    Node* getPrev();
    void setValue(Cancion* value);
    void setNext(Node* next);
    void setPrev(Node* prev);
    ~Node();
};