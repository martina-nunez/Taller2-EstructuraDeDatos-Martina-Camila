#pragma once
#include "HeapNode.hpp"

class Heap{
    private:
        HeapNode* heap;
        int cantidad;
        
    public:
        Heap(int cancionesTotales);
        bool isEmpty();
        void insert(Cancion* cancion);
        HeapNode getMayor();
        void removeMayor();
        ~Heap();
};