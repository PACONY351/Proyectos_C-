#include<iostream>
#include<stdlib.h>

//  STRUCT 
struct Nodo{
    char letra;
    Nodo *siguiente;
};

// GLOBAL
Nodo *frente = NULL;
Nodo *fin = NULL;

// PROTOTIP
void insertarCola(Nodo *&, Nodo *&, int);
void mostrarCola();
void suprimirCola();
bool cola_vacioa(Nodo *);
// OPTIONS

// MAIN
int main(){

    return 0;
}
 // FUNTIONS
void instertarCola(Nodo *&frente, Nodo *&fin, int n){
    Nodo *aux = new Nodo();
    aux -> letra = n;
    aux -> siguiente = NULL;

    if(cola_vacia(frente)){
        frente = aux;
    }else{
        fin -> 
    }

}

bool cola_vacia(Nodo *frente){
    return (frente == NULL) ? true : false;
}





