
//				COLAS    ---    FIFO
/* 
UNA COLA ES UNA ESTRUCTURA DE DATOS, CARACTERIZADA POR SER UNA SECUENCIA
DE ELEMENTOS EN LA QUE LA OPERACION DE INSERCION SE REALIZA POR UN EXTREMO
Y LA EXTRACCION POR EL OTRO. 

INSERTAR ELEMENTOS EN UNA COLA
1- CREAR ESPACIO EN LA MEMORIA PARA ALMACENAR UN NODO
2- ASIGNAR ESE NUEVO NODO AL DATO QUE QUEREMOS INSERTAR
3- ASIGNAR LOS PUNTERIS FRENTE Y FIN HACIA EL NUEVO NODO

PASO 1: 
CREAR ESPACIO

frente -> NULL;
fin -> NULL;

PASO 2:

nuevo_nodo -> dato = n;
nuevo_nodo -> siguiente = NULL;

PASO 3: 

frente -> NULL;             
fin -> NULL;            

void insertarCola(Nodo *&frente, Nodo *&fin, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo -> dato = n;
    nuevo_nodo -> siguiente = NUUL;

    if(cola_vacia(frente)){
        frente = nuevo_nodo;
    }else{
        fin -> siguiente = nuevo_nodo;
    }

    fin = nuevo_nodo;
}


ELIMINAR ELEMENTOS DE UNA COLA
1- OPTENER EL VALOR DEL NODO
2- CREAR EL NODO AUX Y ASIGNARLE EL FRENTE DE LA COLA
3- ELIMINAR EL NODO DEL FRENTE DE LA COLA


PASO 1:
OPETENER EL VALOR DEL NODO

void suprimirCola(Nodo *&frente, Nodo *&fin, n&){
    n = frente -> dato;
}

PASO 2: 
CREAR EL NODO AUX Y ASIGNARLE EL FRENTE DE LA COLA
Nodo *aux = frente; 

void suprimirCola(Nodo *&frente, Nodo *&fin, n&){
    n = frente -> dato;
    Nodo *aux = frente;
}

PASO 3: 
ELIMINAR EL NODO DEL FRENRE DE LA COLA 

void suprimirCola(Nodo *&frente, Nodo *&fin, n&){
    n = frente -> dato;
    Nodo *aux = frente;

    if(frente == fin){
        frente = NULL;
        fin = NULL;
    }else{
        frente = frente -> siguiente;
    }
    
    delete aux;
}

*/

#include<iostream>
#include<stdlib.h>

// ESTRUCTURAS
struct Nodo{
    int dato;
    Nodo *siguiente;
};

// GLOBALES
Nodo *frente = NULL;
Nodo *fin = NULL;

// PROTOTIPOS 
int opcionesMenu();
void seleccionMenu(int);
void insertarCola(Nodo *&, Nodo *&, int);
bool cola_vacia(Nodo *);
void surpimirColar(Nodo *&, Nodo *&, int &);

// OPCIONES
void opInsertar();
void opMostrar();
void opEliminar();

// MAIN
int main(){
    seleccionMenu(opcionesMenu());
    return 0;
}

// FUNCIONES
int opcionesMenu(){
    int opcion = 0;
    std::cout<<"|---------------MENU---------------|"<<std::endl;
    std::cout<<"| 1. Insertar elementos en la cola |"<<std::endl;
    std::cout<<"| 2. Mostrar elementos de la cola  |"<<std::endl;
    std::cout<<"| 3. Eliminar elementos de la cola |"<<std::endl;
    std::cout<<"| 4. Salir                         |"<<std::endl;
    std::cout<<"|---------------MENU---------------|"<<std::endl;
    do{
        std::cout<<"Opcion: ";
        std::cin>>opcion;
    }while(opcion < 1 || opcion > 4);
    return opcion;
}

void seleccionMenu(int opcion){
    switch(opcion){
        case 1:
            opInsertar();
            break;
        case 2:
            opMostrar();
            break;
        case 3:
            opEliminar();
            break;
        case 4:
            std::cout<<"Saliendo del programa..."<<std::endl;
            exit(0);
            break;
        default:
            std::cout<<"Opcion no valida"<<std::endl;
            break;
    }
}

void insertarCola(Nodo *&frente, Nodo *&fin, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo -> dato = n;
    nuevo_nodo -> siguiente = NULL;

    if(cola_vacia(frente)){
        frente = nuevo_nodo;
    }else{
        fin -> siguiente = nuevo_nodo;
    }

    fin = nuevo_nodo;
}

bool cola_vacia(Nodo *frente){
    return (frente == NULL) ? true : false;
}

void suprimirCola(Nodo *&frente, Nodo *&fin, int &n){
    n = frente -> dato;
    Nodo *aux = frente;

    if(frente == fin){
        frente = NULL;
        fin = NULL;
    }else{
        frente = frente -> siguiente;
    }
    delete aux;
}
// FUNCIONES DE OPCIONES DEL MENU
void opInsertar(){
    int dato;
    std::cout<<"Insertar elementos en la cola"<<std::endl;
    std::cout<<"Prescione 0 para salir"<<std::endl;

    do{
        std::cout<<"Dato: ";
        std::cin>>dato;
        if(dato != 0){
            insertarCola(frente, fin, dato);
        }
    }while(dato != 0);
    std::cout<<"Datos insertados correctamente"<<std::endl;
    
    seleccionMenu(opcionesMenu());
}

void opMostrar(){
    Nodo *aux = frente;
    if(cola_vacia(frente)){
        std::cout<<"La cola esta vacia"<<std::endl;
    }else{
        std::cout<<"Mostrando elementos de la cola"<<std::endl;
        while(aux != NULL){
            std::cout<<"<"<<aux -> dato<<"> ";
            aux = aux -> siguiente;
        }
        std::cout<<std::endl;
    }
    seleccionMenu(opcionesMenu());
}

void opEliminar(){
    int dato;
    std::cout<<"Eliminando toda la cola..."<<std::endl;
    while(frente != NULL){
        suprimirCola(frente,fin,dato);
        std::cout<<"<"<<dato<<"> ";
    }
    std::cout<<""<<std::endl;
    std::cout<<"Cola eliminada."<<std::endl;
    seleccionMenu(opcionesMenu());
}
