#include "SistemaImpl.hpp"
#include "../classes/Cancion.hpp"
#include "../data_structures/List.hpp"
#include "../data_structures/Node.hpp"
#include "../classes/Reproductor.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

void SistemaImpl::cargarMusica(){
    ifstream archivo("music_source.txt");//abrir el archivo donde estan las canciones

    if(!archivo){//ver si el archivo existe
        cout<<"Error"<<endl;
        return;
    }
    
    string linea;//leer las lineas
    while (getline(archivo, linea)){
        if(linea.empty()){
            continue;
        }
        stringstream sStream(linea);
        //declarar las variables que estan en las linea 
        string numUnico, nombre, artista, album, anioCancion, duracionSegundos, ubicacion;

        getline(sStream, numUnico, ',');
        getline(sStream, nombre, ',');
        getline(sStream, artista, ',');
        getline(sStream, album, ',');
        getline(sStream, anioCancion, ',');
        getline(sStream, duracionSegundos, ',');
        getline(sStream, ubicacion);

        int id = stoi(numUnico);
        int anio = stoi(anioCancion);
        int duracion = stoi(duracionSegundos);

        //se crea la cancion, con las variables de recien
        Cancion* cancion = new Cancion(id, nombre, artista, album, anio, duracion, ubicacion);
        lista.insertLast(cancion);
        totalCanciones++;
    }
    archivo.close();
}

void SistemaImpl::mostrarMenu(){
    limpiarConsola();

    string estado = r.getEstado();
    if(listaVacia){
        cout << "Lista vacia" << endl;
    }else{
        if(aleatorio){
            if(estado == "Reproduciendo"){
            cout << estado << "(S - " << r.getRepeticion() << "):" << r.getCancionActual() <<endl;
            cout << "Artista: "<< r.getArtista() <<endl;
            cout << "Album: "<< r.getAlbum() << "[" << r.getAnio() << "]" <<endl;    
            }else {
            cout << estado <<endl;
            }
        }else{
            if(estado == "Reproduciendo"){
            cout << estado << "(" << r.getRepeticion() << "):" << r.getCancionActual() << endl;
            cout << "Artista: "<< r.getArtista() << endl;
            cout << "Album: "<< r.getAlbum() << "[" << r.getAnio() << "]" << endl;    
            }else {
            cout << estado << endl;
            }
        }
    }

    if(actual->getPrev() == nullptr){
        if(aleatorio){
            cout << "\nOpciones:" << endl;
            cout << "W - Reproducir/Pausar" << endl;
            cout << "E - Pista siguiente" << endl;
            cout << "R - Repeticion (Desactivado/Repetir una/Repetir todas)" << endl;
            cout << "A - Ver lista de reproduccion actual" << endl;
            cout << "L - Listado de canciones" << endl;
            cout << "F - Buscar canciones" << endl;
            cout << "T - Top 10 Artistas y Canciones" << endl;
            cout << "X - Salir" << endl;
            cout << "Ingrese Opcion: ";
        } else{
            cout<<"\nOpciones:"<<endl;
            cout<<"W - Reproducir/Pausar"<<endl;
            cout<<"E - Pista siguiente"<<endl;
            cout<<"S - Activar/Desactivar modo aleatorio"<<endl;
            cout<<"R - Repeticion (Desactivado/Repetir una/Repetir todas)"<<endl;
            cout<<"A - Ver lista de reproduccion actual"<<endl;
            cout<<"L - Listado de canciones"<<endl;
            cout << "F - Buscar canciones" << endl;
            cout << "T - Top 10 Artistas y Canciones" << endl;
            cout<<"X - Salir"<<endl;
            cout<<"Ingrese Opcion: ";
        }
        
    } else{
        if(aleatorio){
            cout<<"\nOpciones:"<<endl;
            cout<<"W - Reproducir/Pausar"<<endl;
            cout<<"Q - Pista anterior"<<endl;
            cout<<"E - Pista siguiente"<<endl;
            cout<<"R - Repeticion (Desactivado/Repetir una/Repetir todas)"<<endl;
            cout<<"A - Ver lista de reproduccion actual"<<endl;
            cout<<"L - Listado de canciones"<<endl;
            cout << "F - Buscar canciones" << endl;
            cout << "T - Top 10 Artistas y Canciones" << endl;
            cout<<"X - Salir"<<endl;
            cout<<"Ingrese Opcion: ";
        } else{
            cout<<"\nOpciones:"<<endl;
            cout<<"W - Reproducir/Pausar"<<endl;
            cout<<"Q - Pista anterior"<<endl;
            cout<<"E - Pista siguiente"<<endl;
            cout<<"S - Activar/Desactivar modo aleatorio"<<endl;
            cout<<"R - Repeticion (Desactivado/Repetir una/Repetir todas)"<<endl;
            cout<<"A - Ver lista de reproduccion actual"<<endl;
            cout<<"L - Listado de canciones"<<endl;
            cout << "F - Buscar canciones" << endl;
            cout << "T - Top 10 Artistas y Canciones" << endl;
            cout<<"X - Salir"<<endl;
            cout<<"Ingrese Opcion: ";
        }   
    }    
}

char SistemaImpl::obtenerOpcion(){
    char opcion;//pedir la opcion con la que hay que trabajar
    cin >> opcion;
    opcion = toupper(opcion);//hacer que todas las opciones que se ingresen esten en mayusculas
   
    while(opcion != 'W' && opcion != 'Q' && opcion != 'E' && opcion != 'S' && opcion != 'R' && opcion != 'A' && opcion != 'L' && opcion != 'F' && opcion != 'T' && opcion != 'X'){
        cout<<"Opcion no disponible, seleccione otra Opcion: ";//control de error, para que solo se puedan ingresar las opciones validas
        cin >> opcion;
        opcion = toupper(opcion);
    }
    return opcion;
}

void SistemaImpl::inicializar(){
    cargarMusica();
    actual = lista.getStart();
    if(!r.existeArchivo("status.cfg")){
        r.crearDefault();
    } else {
        r.cargarDatos();
        Node* aux= lista.getStart();
        while(aux != nullptr){
            if(aux->getValue()->getNombre() == r.getCancionActual()){
                actual= aux;
                break;
            }
        aux= aux->getNext();
        }
    }
}

void SistemaImpl::trabajar(char opcion){
    switch(opcion){
        case 'W': //reproducir pausar
            r.setRepeticion("D");    
            opcionW();
            break;
        case 'Q': // cancion anterior
            listaVacia = false;
            opcionQ();
            break;
        case 'E': //cancion siguiente
            opcionE();
            break;
        case 'S': // modo aleatorio
            opcionS();
            break;
        case 'R': //repeticion (desactivado, una, todas)
            opcionR();
            break;
        case 'A': // lista actual
            opcionA();
            break;
        case 'L': //lista completa
            opcionL();
            break;
        case 'X': //salir
            opcionX();
            break;
        case 'F':
            opcionF();
            break;
        case 'T':
            opcionT();
            break;
    }        
}

void SistemaImpl::opcionW(){
    if(r.getEstado() == "En pausa" || r.getEstado() == "Reproduccion detenida"){
        r.setEstado("Reproduciendo");
        if(actual != nullptr) {//siempre pasa, porque en inicializar se incia actual con el getStart()   
            r.setCancionActual(actual->getValue()->getNombre());
            r.setArtista(actual->getValue()->getArtista());
            r.setAlbum(actual->getValue()->getAlbum());
            r.setAnio(actual->getValue()->getAnio());
            int reproducciones = actual->getValue()->getReproducciones();
            actual->getValue()->setReproducciones(reproducciones + 1);
        }   
    } else if(r.getEstado() == "Reproduciendo"){
        r.setEstado("En pausa");
    } 
}

void SistemaImpl::opcionQ(){
    if(lista.isEmpty()){
        return;
    }
    if(r.getEstado() == "Reproduciendo"){
        if(r.getRepeticion() == "R1"){//cuando se repitne una vez
            if(actual !=  nullptr){
                r.setCancionActual(actual->getValue()->getNombre());
                r.setArtista(actual->getValue()->getArtista());
                r.setAlbum(actual->getValue()->getAlbum());
                r.setAnio(actual->getValue()->getAnio());
            }

        }else if(r.getRepeticion() == "RA"){ //cuando se repiten todas
            if(actual != nullptr && actual->getPrev() != nullptr){
                actual = actual->getPrev();
            }else{
                actual = lista.getStart();
                if(aleatorio){
                    mezclarCanciones(totalCanciones);
                    actual = lista.getStart();
                }
            }
        } else{
            if(actual != nullptr && actual->getPrev() != nullptr){
            actual = actual->getPrev();

            r.setCancionActual(actual->getValue()->getNombre());
            r.setArtista(actual->getValue()->getArtista());
            r.setAlbum(actual->getValue()->getAlbum());
            r.setAnio(actual->getValue()->getAnio());
            }
        }
        int reproducciones = actual->getValue()->getReproducciones();
        actual->getValue()->setReproducciones(reproducciones + 1);
        }
}

void SistemaImpl::opcionE(){
    if(lista.isEmpty()){
        return;
    }
    if(r.getEstado() == "Reproduciendo"){
        if(r.getRepeticion() == "R1"){//cuando se repitne una vez
            if(actual !=  nullptr){
                r.setCancionActual(actual->getValue()->getNombre());
                r.setArtista(actual->getValue()->getArtista());
                r.setAlbum(actual->getValue()->getAlbum());
                r.setAnio(actual->getValue()->getAnio());
            }

        }else if(r.getRepeticion() == "RA"){ //cuando se repiten todas
            if(actual != nullptr && actual->getNext() != nullptr){
                actual = actual->getNext();
            }else{
                actual = lista.getStart();
                if(aleatorio){
                    mezclarCanciones(totalCanciones);
                    actual = lista.getStart();
                }
            }

        }else{
            if(actual != nullptr && actual->getNext() != nullptr){
                actual = actual->getNext();
                r.setCancionActual(actual->getValue()->getNombre());
                r.setArtista(actual->getValue()->getArtista());
                r.setAlbum(actual->getValue()->getAlbum());
                r.setAnio(actual->getValue()->getAnio());
            }else{
                listaVacia = true;
            }
        }
        int reproducciones = actual->getValue()->getReproducciones();
        actual->getValue()->setReproducciones(reproducciones + 1);
    }  
}
    

void SistemaImpl::opcionS(){
    if(aleatorio == false){
        aleatorio = true;
        mezclarCanciones(totalCanciones);
        actual = lista.getStart();
    }
}

void SistemaImpl::opcionR(){
    int opcionRep;
    cout<< "Opciones: " << endl;
    cout<< "1. Repetir una" << endl;
    cout<< "2. Repetir todas" << endl;
    if(repeticion){
        cout<< "0. Desactivar repeticion" << endl;
    }
    cin >> opcionRep;
    while(opcionRep != 1 && opcionRep != 2 && opcionRep != 0){
        cout<<"Ingrese otra opcion: ";
        cin >> opcionRep;
    }
    if(opcionRep == 1){ //que se repita una sola vez
        r.setRepeticion("R1");
        repeticion = true;
    }else if(opcionRep == 2){ //que se repitan todas
        r.setRepeticion("RA");
        repeticion = true;
    }else if(opcionRep == 0){ //no se repiten osea esta desactivado
        r.setRepeticion("D");
        repeticion = false;
    }
}

void SistemaImpl::opcionA(){
    limpiarConsola();
    bool saltar = true;
    cout << "\nActual (" << r.getRepeticion() << "): " << r.getCancionActual() << " - " << r.getArtista() << endl;
    cout << "\nLista de reproduccon actual:" << endl;

    if(actual->getNext() != nullptr){
        Node* aux = actual->getNext();//comenzar con la cancion que va despues de la actual
        if(aux == nullptr){
            cout << "Lista vacia" << endl;
        } else{
            for(int i = 1; aux != nullptr; i++){
                cout << i << ". " << aux->getValue()->getNombre() << " - " << aux->getValue()->getArtista() << endl;
                aux = aux->getNext();
            }
        }
    }
    
    cout << "\nOpciones: " <<endl;
    cout << "S<num> - Saltar a la cancion seleccionada" << endl;
    cout << "V - Volver al menu principal" << endl;
    cout << "Ingrese una opcion: ";
    string opcion;
    cin >> opcion;

    if(opcion[0] != 's' && opcion[0] != 'S' && opcion != "v" && opcion != "V"){
        cout << "Opcion invalida" << endl;
        return;
    }
    
    if(opcion[0] == 's' || opcion[0] == 'S'){
        if(opcion.size() <= 1){
            cout << "Opción inválida" << endl;
            return;
        } else{
            int posicion = stoi(opcion.substr(1));//toma lo que viene despues de la s
            seleccionarCancion(posicion, saltar);
            return;    
        }
        
    } else if(opcion == "v" || opcion == "V"){
        return;
    }
}

void SistemaImpl::opcionL(){
    limpiarConsola();
    cout << "\nActual (" << r.getRepeticion() << "): " << r.getCancionActual() << " - " << r.getArtista() << endl;
    lista.printList();
    menuL();
}

void SistemaImpl::opcionX(){
    string estado = r.getEstado();
    string cancion = r.getCancionActual();
    string artista = r.getArtista();
    bool aleatorio = r.getAleatorio();
    string repeticion = r.getRepeticion();
    
    r.guardarDatos(estado, cancion, artista, repeticion, aleatorio);
}

void SistemaImpl::mezclarCanciones(int total){
    for (int i = 0; i < total ; i++){
        int a = rand() % total;

        Node* node1 = lista.getStart();
        Node* node2 = lista.getStart();

        for(int k = 0 ; k<i ; k++){
            node1 = node1->getNext();
        }

        for(int b = 0 ; b<a ; b++){
            node2 = node2->getNext();
        }

        Cancion* aux = node1->getValue();
        node1->setValue(node2->getValue());
        node2->setValue(aux);
    }
    
}

void SistemaImpl::menuL(){
    bool saltar = false;
    cout << "\nOpciones:" << endl;
    cout << "R<num> - Reproducir cancion seleccionada" << endl;
    cout << "A<num> - Agregar cancion seleccionada al final de la lista de reproduccion actual" << endl;
    cout << "N - Agregar cancion al registro de canciones" << endl;
    cout << "D<num> - Eliminar cancion seleccionada" << endl;
    cout << "V - volver al menu principal" << endl;

    cout << "Ingrese una opcion: ";
    string opcion;
    cin >> opcion;
    while(opcion[0] != 'R' && opcion[0] != 'r' && opcion[0] != 'A' && opcion[0] != 'a' && opcion != "N" && opcion != "n" && 
            opcion[0] != 'D' && opcion[0] != 'd' && opcion != "V" && opcion != "v"){
        cout << "Ingrese otra opcion: ";
        cin >> opcion;
    }
    
    if(opcion[0] == 'r' || opcion[0] == 'R'){//si la opcion es r
        int posicion = stoi(opcion.substr(1));//toma lo que viene despues de la s
        seleccionarCancion(posicion, saltar);
        return;

    }else if(opcion[0] == 'a' || opcion[0] == 'A'){//si la opcion es a
        int posicion = stoi(opcion.substr(1));

        Node* aux = lista.getStart();
        int contador = 1;
        
        while(aux != nullptr && contador < posicion){
            aux = aux->getNext();
            contador++;
        }

        if(aux != nullptr){
            Cancion* original = aux->getValue();
            Cancion* copia = new Cancion(original->getId(), original->getNombre(), original->getArtista(), original->getAlbum(), original->getAnio(), original->getDuracion(), original->getUbicacion());
            lista.remove(posicion);
            lista.insertLast(copia);   
        
            cout << "Cancion agregada con exito" <<endl;
        }
        return;

    }else if(opcion == "n" || opcion == "N"){
        agregarCancionArchivo();
        return;

    }else if(opcion[0] == 'd' || opcion[0] == 'D'){
        if(opcion.size() <= 1){
            cout << "Opción inválida" << endl;
            return;
        }
        int posicion = stoi(opcion.substr(1));
        
        Node* aux = lista.getStart();
            int contador = 1;
            int id;
        
        while(aux != nullptr && contador < posicion){
            aux = aux->getNext();
            contador++;            
        }

        if(aux != nullptr){
            id = aux->getValue()->getId();
        }
        lista.remove(posicion);
        eliminarCancionArchivo(id);
        return;

    }else if(opcion == "v" || opcion == "V"){
        return;
    }
}

void SistemaImpl::seleccionarCancion(int indice, bool saltar){
    if(lista.isEmpty()){
        return;
    }else{
        Node* aux;
        if(saltar){
            if(actual->getNext() != nullptr){
                aux = actual->getNext();
            }
            return;
        }else{
            aux = lista.getStart();
        }
        
        int contador = 1;
        while(aux != nullptr && contador < indice){
            aux = aux->getNext();
            contador++;
        }

        if(aux != nullptr){
            actual= aux;

            r.setEstado("Reproduciendo");
            r.setCancionActual(actual->getValue()->getNombre());
            r.setArtista(actual->getValue()->getArtista());
            r.setAlbum(actual->getValue()->getAlbum());
            r.setAnio(actual->getValue()->getAnio());
        
        }else{
            cout << "Posicion invalida" << endl;
        }
    }
 }

void SistemaImpl::eliminarCancionArchivo(int id){
    ifstream lectura("music_source.txt");
    ofstream nuevo("nuevo.txt");

    if(!lectura || !nuevo){
        cout << "Error con los archivos" << endl;//control
        return;
    }
    
    string linea;
    while(getline(lectura, linea)){
        stringstream sStream(linea);
        string idLectura;
        getline(sStream, idLectura, ',');

        int idElim = stoi(idLectura);

        if(idElim != id){
            nuevo << linea << endl;
        }
    }

    lectura.close();
    nuevo.close();

    remove("music_source.txt");//eliminaa el archivo anterior
    rename("nuevo.txt", "music_source.txt");//renombra el archivo nuevo como el anterior
}

void SistemaImpl::agregarCancionArchivo(){
    string nombre;
    string artista;
    string album;
    string aniostd;
    string tiempostd;
    string ruta;

    cin.ignore();//limpiar los residuos de info
    cout << "Ingrese el nombre de la cancion: ";
    getline(cin, nombre);
    cout << "Ingrese el nombre del artista: ";
    getline(cin, artista);
    cout << "Ingrese el nombre del album: ";
    getline(cin, album);
    cout << "Ingrese el anio de lanzamiento: ";
    getline(cin, aniostd);
    int anio = stoi(aniostd);
    cout << "Ingrese la duracion en segundos: ";
    getline(cin, tiempostd);
    int tiempo = stoi(tiempostd);
    cout << "Ingrese la ruta: ";
    getline(cin, ruta);

    Node* aux = lista.getStart();
    int mayor = 0;
    while(aux != nullptr){
        if(aux->getValue()->getId() > mayor){
            mayor = aux->getValue()->getId();
        }
        aux = aux->getNext();
    }
    int id = mayor + 1;

    ofstream archivo("music_source.txt", ios::app);
    archivo << id << "," << nombre << "," << artista << "," << album << "," << anio << "," << tiempo << "," << ruta << endl;
    
    Cancion* cancion = new Cancion(id, nombre, artista, album, anio, tiempo, ruta);
    lista.insertLast(cancion);
    
    archivo.close();
}

void SistemaImpl::limpiarConsola(){
    system("cls");
}

void SistemaImpl::opcionF(){
    cout << "\nBusqueda de canciones" << endl;
    cout << "\nBuscar canciones que contengan:";
    string buscar;
    cin.ignore();
    getline(cin,buscar);

    if(buscar == ""){
        return;
    }
    //funcion de busqueda po rcoincidencias

    cout << "Busqueda de canciones" << endl;
    cout << "\nBuscar canciones que contienen " << buscar << endl;
    //opciones que contengan la palabra

    cout << "\nOpciones:" << endl; 
    cout << "R<num> - Reproducir canción seleccionada" << endl;
    cout << "A<num> - Agregar canción seleccionada al final de la lista de reproducción actual" << endl; 
    cout << "F - Repetir búsqueda con un texto diferente" << endl;
    cout << "V - Volver al menú principal" << endl;
    cout << "\nIngrese una opcion: ";
    string opcion;
    cin >> opcion;
}

void SistemaImpl::opcionT(){
    limpiarConsola();
    cout << "Ranking TOP" << endl;
    cout << "\nC - Top 10 canciones mas escuchadas" << endl;
    cout << "A - Top 10 artistas mas escuchados" << endl;
    cout << "X - Salir" << endl;
    cout << "\nIngrese una opcion: ";

    char opcion;
    cin.ignore();
    cin >> opcion;
    opcion = toupper(opcion);
    while(opcion != 'C' && opcion != 'A'){
        return;//vuelve al menu principal con todo lo demas, incluyendo la x
    }

    if(opcion == 'C'){
        mostrarCancionesMasEscuchadas();
        cout << "\nOpciones:" << endl;
        cout << "R<num> - Reproducir cancion seleccionada" << endl;
        cout << "A<num> - Agregar cancion seleccionada al final de la lista de reproduccion actual" << endl;
        cout << "A - Top 10 artistas mas escuchados" << endl;
        cout << "V - Volver al menu principal" << endl;
        cout << "\nIngrese una opcion: ";

    } else if(opcion == 'A'){
        mostrarArtistasMasEscuchados();
        cout << "\nOpciones:" << endl;
        cout << "S<num> - Mostrar canciones del artista" << endl;
        cout << "C - Top 10 canciones maas escuchadas" << endl;
        cout << "V - Volver al menu principal" << endl;
        cout << "\nIngrese una opcion: ";

    }
}

void SistemaImpl::mostrarCancionesMasEscuchadas(){//arbol heap
    limpiarConsola();
    cout << "Ranking TOP 10 canciones mas escuchadas:\n" << endl;
    //imprimir las canciones mas escuchadas
}

void SistemaImpl::mostrarArtistasMasEscuchados(){//arbol heap
    limpiarConsola();
    cout << "Ranking TOP 10 artustas mas escuchados:\n" << endl;
    //imprimir los artistas mas escuchados
}