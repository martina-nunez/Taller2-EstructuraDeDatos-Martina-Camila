#include "Sistema.hpp"
#include "SistemaImpl.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

int main(){
    Sistema* sistema = new SistemaImpl();   
    sistema->inicializar();
    
    char opcion;
    do{
        sistema->mostrarMenu();
        opcion = sistema->obtenerOpcion(); 
        sistema->trabajar(opcion);
    } while(opcion != 'X');
    
    delete sistema;
    return 0;
};