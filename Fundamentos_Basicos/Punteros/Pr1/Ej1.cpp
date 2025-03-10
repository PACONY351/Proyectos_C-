/* 
    PUNTEROS
    
    &n = La direccion

    *n = La variable para declarar, 
         y para mostar la direccion de la 
         variable tipo puntero


*/

#include<iostream>

//  PROTOTIPOS
void menuPuntero();
void seleccion(int);
    //  OPCIONES DE MENU
void parImpar();
void primoNoPrimo();
void arreglos();
void arreglosParImpar();
void arreglosNumMenorMayor();

//  MAIN
int main(){

    menuPuntero();

    return 0;
}


//  FUNCIONES
void menuPuntero(){
    int opcion;
    std::cout<<"Selecciiona una opcion"<<std::endl;
    std::cout<<"0 - Salir"<<std::endl;
    std::cout<<"1 - Par Inpar"<<std::endl;
    std::cout<<"2 - Primo No Primo"<<std::endl;
    std::cout<<"3 - Arreglos"<<std::endl;
    std::cout<<"4 - Arreglos Par Impar"<<std::endl;
    do{
        std::cout<<"Opcion: ";std::cin>>opcion;
    }while(opcion < 0 || opcion > 10);
    seleccion(opcion);
}

void seleccion(int opcion){
    switch(opcion){
        case 1:
            parImpar();
            break;
        case 2:
            primoNoPrimo();
            break;
        case 3:
            arreglos();
            break;
        case 4:
            arreglosParImpar();
            break;
        case 5:
            arreglosNumMenorMayor();
            break;
        default:
            break;  
    }
}

void parImpar(){
    int numero, *dir_numero;
    std::cout<<"Digite un numero entero: ";std::cin>>numero;
    dir_numero = &numero;

    if(*dir_numero % 2 == 0){
        std::cout<<"El numero es par"<<std::endl;
        std::cout<<"La direccion es:"<<*dir_numero<<std::endl;
    }else{
        std::cout<<"El numero es inpar"<<std::endl;
        std::cout<<"La direccion es"<<*dir_numero<<std::endl;
    }
}

void primoNoPrimo(){
    int numero, *dir_numero;
    std::cout<<"Digite un numero entero: ";std::cin>>numero;
    dir_numero = &numero;
    
    bool esPrimo = true;
    if (numero <= 1) {
        esPrimo = false;
    } else {
        for (int i = 2; i <= numero / 2; ++i) {
            if (numero % i == 0) {
                esPrimo = false;
                break;
            }
        }
    }

    if(esPrimo){
        std::cout<<"El numero es primo"<<std::endl;
    }else{
        std::cout<<"El numero no es primo"<<std::endl;
    }
    std::cout<<"Direccion: "<<dir_numero<<std::endl;
}

void arreglos(){
    int numeros[5] = {1,2,3,4,5}, *dir_numeros;
    dir_numeros = numeros;

    for (int i = 0; i < 5; i++){
        std::cout<<"Elemento del vector ["<<i<<"]: "<<*(dir_numeros++)<<std::endl;
    }

    for(int i = 0; i < 5; i++){
        std::cout<<"Direccion de memoria del vector ["<<i+1<<"] : "<<dir_numeros++<<std::endl;
    }
}

void arreglosParImpar(){
    int nElementos;
    
    std::cout<<"Digite el numero de elementos: ";
    std::cin>>nElementos;
    
    int numeros[nElementos], *dir_numeros;
    dir_numeros = numeros;

    for(int i = 0 ; i < nElementos; i++){
        std::cout<<"Digite el elemento "<<i+1<<": "<<std::endl;
        std::cin>>*dir_numeros++;
    }

    dir_numeros = numeros;
    for(int i = 0; i < nElementos; i++){
        if(*dir_numeros % 2 == 0){
            std::cout<<"El numero es par"<<std::endl;
            std::cout<<"La direccion es: "<<dir_numeros++<<std::endl;
        }else{
            std::cout<<"El numero no es Par"<<std::endl;
            std::cout<<"La direccion es: "<<dir_numeros++<<std::endl;
        }
    }
}

void arreglosNumMenorMayor(){
    int nElementos;
    
    std::cout<<"Digite el numero de elementos: ";
    std::cin>>nElementos;

    int numeros[nElementos];
    int *dir_numeros = numeros;

    for(int i = 0; i < nElementos; i++){
        std::cout<<"Digite el elemento "<<i+1<<": ";
        std::cin>>numeros[i];
    }

    dir_numeros = numeros;
    int mayor = *dir_numeros;
    int menor = *dir_numeros;
    int *dir_mayor = dir_numeros;
    int *dir_menor = dir_numeros;

    for(int i = 1; i < nElementos; i++){
        dir_numeros++;
        if(*dir_numeros > mayor){
            mayor = *dir_numeros;
            dir_mayor = dir_numeros;
        }
        if(*dir_numeros < menor){
            menor = *dir_numeros;
            dir_menor = dir_numeros;
        }
    }
    
    std::cout<<"El numero mayor es: "<<mayor<<std::endl;
    std::cout<<"La direccion es: "<<dir_mayor<<std::endl;
    std::cout<<"El numero menor es: "<<menor<<std::endl;
    std::cout<<"La direccion es: "<<dir_menor<<std::endl;
}

