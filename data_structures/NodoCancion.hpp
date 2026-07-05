
#ifndef TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA1_LISTCANCIONES_H
#define TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA1_LISTCANCIONES_H
#include "Cancion.hpp"
#include "Node.hpp"


class NodoCancion {
    public:
    Cancion* cancion;
    NodoCancion* sigui;
    NodoCancion(Cancion* c);

};



#endif //TALLER2_ESTRUCTURADEDATOS_MARTINA_CAMILA1_LISTCANCIONES_H
