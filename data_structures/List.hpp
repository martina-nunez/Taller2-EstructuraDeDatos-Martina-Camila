#pragma once
#include "Node.hpp"

class List {
private:
    Node* start;
public:
    List();
    Node* getStart();

    void insertFirst(Cancion* value);
    void insertLast(Cancion* value);
    Node* getFirst();
    Node* getLast();

    void remove(int indice);
    bool isEmpty();
    void clear();
    ~List();

    void printList();
};