#include "Reproductor.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

bool Reproductor::existeArchivo(std::string nombreArchivo){
    ifstream arch(nombreArchivo);
    return arch.is_open();
} 

void Reproductor::cargarDatos(){
    ifstream arch("status.cfg");

    if(!arch.is_open()){
        cout<<"error"<<endl;
        //error e abrir el archivo
        return;
    }

    string linea;
    while (getline(arch, linea)){
        stringstream ss(linea);

        string atributo, elemento;

        getline(ss, atributo, ':');
        getline(ss, elemento);

        

        if(atributo == "Estado"){
            this->estado = elemento;
        } else if(atributo == "Cancion"){
            this->cancionActual = elemento;
        } else if(atributo == "Artista"){
            this->artista = elemento;
        }else if(atributo == "Repeticion"){
            this->repeticion = elemento;
        } else if(atributo == "Aleatorio"){
            if(elemento == "true" || elemento == "True"){
                    this->aleatorio = true;
                } else {
                    this->aleatorio = false;
                }
        }
    }
}

void Reproductor::guardarDatos(std::string estado, std::string cancionActual, std::string artista, std::string repeticion, bool aleatorio){
    ofstream arch("status.cfg");
    arch<<"Estado:"<< estado << endl;
    arch<<"Cancion:"<< cancionActual << endl;
    arch<<"Artista:"<<artista <<endl;
    arch<<"Repeticion:"<< repeticion << endl;
    arch<<"Aleatorio:"<< aleatorio << endl;
    cout<<"datos guardados"<<endl;
}

void Reproductor::crearDefault(){
    ofstream arch("status.cfg");
    this->estado = "Reproduccion detenida";
    arch<<"Estado:"<< estado <<endl;
    arch<<"Cancion:"<<endl;
    arch<<"Artista:"<<endl;
    arch<<"Repeticion:"<<endl;
    arch<<"Aleatorio:"<<endl; 
}

string Reproductor::getEstado(){
    return estado;
}

string Reproductor::getCancionActual(){
    return cancionActual;
}

string Reproductor::getRepeticion(){
    return repeticion;
}

bool Reproductor::getAleatorio(){
    return aleatorio;
}

string Reproductor::getArtista(){
    return artista;
}

string Reproductor::getAlbum(){
    return album;
}

int Reproductor::getAnio(){
    return anio;
}

void Reproductor::setEstado(std::string estado){
    this->estado = estado;
}

void Reproductor::setCancionActual(std::string cancionActual){
    this->cancionActual = cancionActual;
}

void Reproductor::setRepeticion(std::string repeticion){
    this->repeticion = repeticion;
}

void Reproductor::setAleatorio(bool aleatorio){
    this->aleatorio = aleatorio;
}

void Reproductor::setArtista(std::string artista){
    this->artista = artista;
}

void Reproductor::setAlbum(std::string album){
    this->album = album;
}
void Reproductor::setAnio(int anio){
    this->anio = anio;
}
