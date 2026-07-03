#include "Cancion.hpp"
#include <iostream>

using namespace std;

Cancion::Cancion(int id, std::string nombre, std::string artista, std::string album, int anio, int duracion, std::string ubicacion){
        this->id = id;
        this->nombre = nombre;
        this->artista = artista;
        this->album = album;
        this->anio = anio;
        this->duracion = duracion;
        this->ubicacion = ubicacion;  
        this->reproducciones = 0; 
};

int Cancion::getId(){
    return id;
}

string Cancion::getNombre(){
    return nombre;
}

string Cancion::getArtista(){
    return artista;
}

string Cancion::getAlbum(){
    return album;
}

int Cancion::getAnio(){
    return anio;
}

int Cancion::getDuracion(){
    return duracion;
}

string Cancion::getUbicacion(){
    return ubicacion;
}

int Cancion::getReproducciones(){
    return reproducciones;
}

void Cancion::setReproducciones(int cantidad){
    this->reproducciones = cantidad;
    cout << "reproducciones totales:" << reproducciones << endl;
}