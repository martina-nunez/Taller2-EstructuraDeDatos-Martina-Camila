#pragma once
#include "Sistema.hpp"
#include "../classes/Reproductor.hpp"
#include "../data_structures/List.hpp"
#include <iostream>
#include"../data_structures/Heap.hpp"

class SistemaImpl : public Sistema {
private:
    List lista;
    List listaAux;
    Reproductor r;
    Node* actual;
    int totalCanciones;
    bool aleatorio = false;
    bool repeticion = false;

    std::string artistasTop[10];
    int cantArtistasTop = 0;
    Cancion* cancionesTop[10];
    int cantCancionesTop = 0;
    

    
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
    void guardarReproducciones();
    void mezclarCanciones(int total);
    void menuL();
    void seleccionarCancion(int indice, bool saltar);
    void eliminarCancionArchivo(int posicion);
    void agregarCancionArchivo();
    void limpiarConsola();
    void opcionF();
    void opcionT();
    void topCanciones();
    void topArtistas();
    void subOpcionC();
    void subOpcionA();
    void subOpcionS(int numero);
};