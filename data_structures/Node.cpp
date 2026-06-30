#include "Node.hpp"
#include "../classes/Cancion.hpp"

Node::Node(Cancion* value){
    this->value = value;
    this->next = nullptr;
    this->prev = nullptr;
}

Cancion* Node::getValue(){ 
    return this->value;
}

Node* Node::getNext(){
    return this->next;
}

Node* Node::getPrev(){
    return this->prev;
}


void Node::setValue(Cancion* value){
    this->value = value;
}

void Node::setNext(Node* next){
    this->next = next;
}

void Node::setPrev(Node* prev){
    this->prev = prev;
}

Node::~Node(){

}
