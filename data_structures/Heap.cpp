#include "Heap.hpp"
#include "HeapNode.hpp"

Heap::Heap(int cancionesTotales){
    cantidad = 0;
    heap = new HeapNode[cancionesTotales];
}

bool Heap::isEmpty(){
    if(cantidad == 0) return true;
    return false;
}

void Heap::insert(Cancion* cancion){
    HeapNode node(cancion);
    heap[cantidad] = node;
    int hijo = cantidad;
    cantidad++;
    int padre = (hijo - 1)/2;

    while(hijo > 0){
        if(isMayor(heap[hijo].getCancion(), heap[padre].getCancion())){
            HeapNode aux = heap[padre];
            heap[padre] = heap[hijo];
            heap[hijo] = aux;    
            hijo = padre;
        }else{
            break;
        }
        padre = (hijo - 1)/2;
    }
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
        
        if(hijoIzq < cantidad && isMayor(heap[hijoIzq].getCancion(), heap[mayor].getCancion())){
                mayor = hijoIzq;
        } 
        if(hijoDer < cantidad && isMayor(heap[hijoDer].getCancion(), heap[mayor].getCancion())){
                mayor = hijoDer;
        }
           
        if(mayor == padre) break;

        HeapNode aux = heap[padre];
        heap[padre] = heap[mayor];
        heap[mayor] = aux;

        padre = mayor;
    }
}

bool Heap::isMayor(Cancion* cancion1, Cancion* cancion2){
    if(cancion1->getReproducciones() > cancion2->getReproducciones()){
        return true;
    }else if(cancion1->getReproducciones() < cancion2->getReproducciones()){
        return false;
    }else if(cancion1->getNombre() < cancion2->getNombre()){
        return true;
    }else if(cancion1->getNombre() > cancion2->getNombre()){
        return false;
    }else if(cancion1->getArtista() < cancion2->getArtista()){
        return true;
    }
    return false;

}

Heap::~Heap(){
    
}
