#pragma once
#include <string>

class Cancion{
private:
    int id;
    std::string nombre;
    std::string artista;
    std::string album;
    int anio;
    int duracion;
    std::string ubicacion;
    int reproducciones;    

public:
    
    Cancion(int id, std::string nombre, std::string artista,
        std::string album, int anio, int duracion,
        std::string ubicacion);
    
    int getReproducciones();
    void setReproducciones(int cantidad);

    int getId();
    std::string getNombre();
    std::string getArtista();
    std::string getAlbum();
    int getAnio();
    int getDuracion();
    std::string getUbicacion();

};