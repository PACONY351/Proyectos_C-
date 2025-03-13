
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
void opInsertar();
void opMostrar();

// MAIN
int main(){
    seleccionMenu(opcionesMenu());
    return 0;
}

// FUNCIONES
int opcionesMenu(){
    int opcion = 0;
    std::cout<<"|-------------MENU-------------|"<<std::endl;
    std::cout<<"1. Insertar elementos en la cola"<<std::endl;
    std::cout<<"2. Mostrar elementos de la cola"<<std::endl;
    std::cout<<"3. Salir"<<std::endl;
    std::cout<<"|-------------MENU--------------|"<<std::endl;
    do{
        std::cout<<"Opcion: ";
        std::cin>>opcion;
    }while(opcion < 1 || opcion > 3);
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

