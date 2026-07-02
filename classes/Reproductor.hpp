#pragma once
//#include "Cancion.hpp"
#include <string>

class Reproductor{
private:
    std::string estado;
    std::string cancionActual;
    bool aleatorio;  
    std::string nombreArchivo;  
    std::string repeticion;
    
    std::string artista;
    std::string album;
    int anio;
    

public:
    
    bool existeArchivo(std::string nombreArchivo);    
    void cargarDatos();
    void guardarDatos(std::string estado, std::string cancionActual, std::string artista, std::string repeticion, bool aleatorio);
    void crearDefault();

    
    std::string getEstado();
    std::string getCancionActual();
    bool getAleatorio();
    std::string getArtista();
    std::string getAlbum();
    int getAnio();
    std::string getRepeticion();

    void setEstado(std::string estado);
    void setCancionActual(std::string cancionActual);
    void setAleatorio(bool aleatorio);
    void setArtista(std::string artista);
    void setAlbum(std::string album);
    void setAnio(int anio);
    void setRepeticion(std::string repeticion);
};