#pragma once
#include "..\classes.\Cancion.hpp"

class HeapNode{
    private:
        Cancion* cancion;
    public:
        HeapNode();
        HeapNode(Cancion* cancion);
        Cancion* getCancion();
        void setCancion(Cancion* cancion);
};
//vaciar heap - recorrer la lista - insertar las canciones- mostrar las primeras 10