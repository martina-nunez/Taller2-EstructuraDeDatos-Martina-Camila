#include "Heap.hpp"
#include "HeapNode.hpp"

Heap::Heap(int cancionesTotales){
    cantidad = 0;
    heap = new HeapNode[cancionesTotales];
}

bool Heap::isEmpty(){
    if(cantidad == 0) return false;
    return true;
}

void Heap::insert(Cancion* cancion){

}

HeapNode Heap::getMayor(){
    return heap[0];
}

void Heap::removeMayor(){
    if(isEmpty()) return;

    heap[0] = heap[cantidad-1];
    cantidad--;

    int padre = 0;
    int hijoIzq, hijoDer;
    while(true){
        hijoIzq = 2 * padre + 1;
        hijoDer = 2 * padre + 2;
        int mayor = padre;
        
        if(hijoIzq < cantidad && heap[hijoIzq].getCancion()->getReproducciones() > heap[mayor].getCancion()->getReproducciones()){
                mayor = hijoIzq;
        } 
        if(hijoDer < cantidad && heap[hijoDer].getCancion()->getReproducciones() > heap[mayor].getCancion()->getReproducciones()){
                mayor = hijoDer;
        }
           
        if(mayor == padre) break;

        HeapNode aux = heap[padre];
        heap[padre] = heap[mayor];
        heap[mayor] = aux;

        padre = mayor;
    }
}

Heap::~Heap(){
    
}
