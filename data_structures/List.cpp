#include <iostream>
#include "List.hpp"
#include "../classes/Cancion.hpp"
using namespace std;

List::List() {
    this->start = nullptr;
}

Node* List::getStart(){
    return start;
}

void List::insertFirst(Cancion* value) {
    Node* nuevo = new Node(value);
    nuevo->setNext(this->start);
    if(this->start != nullptr){
        this->start->setPrev(nuevo);
    }
    this->start = nuevo;
}

void List::insertLast(Cancion* value) {
    if (this->start == nullptr) {
        this->start = new Node(value);
        return;
    }
    Node* cursor = this->start;
    while (cursor->getNext() != nullptr) {
        cursor = cursor->getNext();
    }
    Node* nuevo = new Node(value);

    cursor->setNext(nuevo);
    nuevo->setPrev(cursor);
}


Node* List::getFirst() {
    if (this->start == nullptr){
        return 0;
    } 
    return this->start;
}

Node* List::getLast() {
    if (this->start == nullptr) {
        return 0;
    }
    Node* cursor = this->start;
    while (cursor->getNext() != nullptr) {
        cursor = cursor->getNext();
    }
    return cursor;
}

bool List::isEmpty() {
    return this->start == nullptr;
}

void List::clear() {
    Node* cursor = this->start;
    while (cursor != nullptr) {
        Node* temp = cursor;
        cursor = cursor->getNext();
        delete temp;
    }
    this->start = nullptr;
}

List::~List() {
    this->clear();
}

void List::printList(){
    Node* cursor = this->start;

    if(cursor == nullptr){
        cout<<"Lista vacía"<<endl;
        return;
    }
    cout << "Canciones registradas:" << endl;
    while (cursor != nullptr) {
        Cancion* c = cursor->getValue();
        cout << c->getId() << ". " << c->getNombre() << " - " << c->getArtista() << endl;
        cursor = cursor->getNext();
    }
}

void List::remove(int indice){
    if(this->start == nullptr){
        return;
    }
    Node* aux = this->start;
    int contador = 1;
    while(aux != nullptr && contador < indice){
        aux = aux->getNext();
        contador++;
    }

    if(aux == nullptr){
        return;
    } else if(aux->getPrev() == nullptr){//es la primera cancion de la lista
        this->start = aux->getNext();
        this->start->setPrev(nullptr);
    } else{
        Node* prev = aux->getPrev();
        Node* next = aux->getNext();

        prev->setNext(next);
        if(next != nullptr){
            next->setPrev(prev);
        }
    }

    delete aux; 

        
}