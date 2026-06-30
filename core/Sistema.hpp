#pragma once
#include "../classes/Reproductor.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

class Sistema{
public:
    virtual void inicializar() = 0;
    virtual void cargarMusica() = 0;
    virtual void mostrarMenu() = 0;
    virtual char obtenerOpcion() = 0;
    virtual void trabajar(char opcion) = 0;
    virtual ~Sistema() = default;
        
};