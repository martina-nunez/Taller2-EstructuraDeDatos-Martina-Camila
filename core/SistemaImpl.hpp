#pragma once
#include "Sistema.hpp"
#include "../classes/Reproductor.hpp"
#include "../data_structures/List.hpp"
#include <string>

class SistemaImpl : public Sistema {
private:
    List lista;
    Reproductor r;
    Node* actual;
    int totalCanciones;
    bool aleatorio = false;
    bool repeticion = false;
    bool listaVacia = false;
    
public:
    void inicializar();      
    void cargarMusica();
    void mostrarMenu();
    char obtenerOpcion();
    void trabajar(char opcion);
    void opcionW();
    void opcionQ();
    void opcionE();
    void opcionS();
    void opcionR();
    void opcionA();
    void opcionL();
    void opcionX();
    void mezclarCanciones(int total);
    void menuL();
    void seleccionarCancion(int indice, bool saltar);
    void eliminarCancionArchivo(int posicion);
    void agregarCancionArchivo();
    void limpiarConsola();
};