/* 
    PUNTEROS
    
    &n = La direccion

    *n = La variable para declarar, 
         y para mostar la direccion de la 
         variable tipo puntero


*/

#include<iostream>
#include<stdlib.h>  //  Libreria para new y delete

//  PROTOTIPOS
void menuPuntero();
void seleccion(int);
//  OPCIONES DE MENU
void parImpar();
void primoNoPrimo();
void arreglos();
void arreglosParImpar();
void arreglosNumMenorMayor();
void direccionMemoria();
void intercambioMemoria(float*, float*);  
void arregloDeMaximo();
void hallarMaximo(int *, int);  
void ordenarArreglo();
void numeroDeVocales();
void matrizConPunteros();
void sumaMatrices();
void punteroEstructura();
void punteroEstructura2();

// ESTRUCTURAS
struct Persona{
    char nombre[30];
    int edad;
}persona, *puntero_persona = &persona;

struct Alumno{
    char nombre[30];
    int edad;
    float promedio;
}alumno, *puntero_alumno = &alumno;

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
    std::cout<<"5 - Arreglos Numero Menor Mayor"<<std::endl;
    std::cout<<"6 - Direccion de Memoria"<<std::endl;
    std::cout<<"7 - Arreglo de Maximo"<<std::endl;
    std::cout<<"8 - Ordenar Arreglo"<<std::endl;
    std::cout<<"9 - Numero de Vocales"<<std::endl;
    std::cout<<"10 - Matriz con Punteros"<<std::endl;
    std::cout<<"11 - Suma de Matrices"<<std::endl;
    std::cout<<"12 - Puntero Estructura"<<std::endl;
    std::cout<<"13 - Puntero Estructura 2"<<std::endl;
    do{
        std::cout<<"Opcion: ";std::cin>>opcion;
    }while(opcion < 0 || opcion > 13);
    seleccion(opcion);
}

void seleccion(int opcion){
    switch(opcion){
        case 0:
            break;
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
        case 6:
            direccionMemoria();
            break;
        case 7: 
            arregloDeMaximo();
            break;
        case 8:
            ordenarArreglo();
            break;
        case 9:
            numeroDeVocales();
            break;
        case 10:
            matrizConPunteros();
            break;
        case 11:
            sumaMatrices();
            break;
        case 12:
            punteroEstructura();
            break;
        case 13:
            punteroEstructura2();
            break;    
        default:
            std::cout<<"Elige una opcion valida de 0-13"<<std::endl;
            menuPuntero();
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

void direccionMemoria(){
    float num1,num2;
    std::cout<<"Digite un numero: ";
    std::cin>>num1;
    std::cout<<"Digite otro numero: ";
    std::cin>>num2;

    intercambioMemoria(&num1, &num2);

    std::cout<<"El nuevo valor del primer numero es: "<<num1<<std::endl;
    std::cout<<"Su direccion de memoria es: "<<&num1<<std::endl;
    std::cout<<"El nuevo valor del segundo numero es: "<<num2<<std::endl;
    std::cout<<"Su direccion de memoria es: "<<&num2<<std::endl;
}

void intercambioMemoria(float *dir_num1, float *dir_num2){
    float aux;  

    aux = *dir_num1;
    *dir_num1 = *dir_num2;
    *dir_num2 = aux;
}

void arregloDeMaximo(){
    int nElementos = 5;
    int numeros[5] = {1,2,3,4,5};
    int *dir_numeros = numeros;

    hallarMaximo(dir_numeros, nElementos);
}

void hallarMaximo(int *dir_numeros, int nElementos){
    int mayor;
    mayor = *dir_numeros;
    for(int i = 0; i < nElementos; i++){
        *dir_numeros++;
        if(*dir_numeros > mayor ){
            mayor = *dir_numeros;
        }else{
            mayor = mayor;
        }
    }
} 

void ordenarArreglo(){
    int nElemento, *elemento, aux;

    std::cout<<"Digite el numero de elementos: ";
    std::cin>>nElemento;

    elemento = new int[nElemento];

    for(int i = 0; i < nElemento; i++){
        std::cout<<"Digite el elemento "<<i+1<<": ";
        std::cin>>*(elemento+i); //elemento[i]
    }

    for(int i = 0; i < nElemento; i++){
        for(int j = 0; j < nElemento-1; j++){
            if((elemento+j) > (elemento+j+1)){
                aux = *(elemento+j);
                *(elemento+j) = *(elemento+j+1);
                *(elemento+j+1) = aux;
            }
        }
    }

    std::cout<<"Orden ascendente: ";
    for(int i = 0; i < nElemento; i++){
        std::cout<<*(elemento+i)<<" ";
    }

}

void numeroDeVocales(){
    char palabra[30], *dir_palabra;
    int cont = 0;

    std::cout<<"Digite una palabra: ";
    std::cin.getline(palabra, 30, '\n');

    dir_palabra = palabra;

    while(*dir_palabra){
        switch(*dir_palabra){
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                cont++;
                break;
        }
        dir_palabra++;
    }

    std::cout<<"La palabra tiene: "<<cont<<" vocales"<<std::endl;
}

void matrizConPunteros(){
    int **puntero_matriz, nFilas, nColumnas;

    std::cout<<"Digite el numero de filas: ";
    std::cin>>nFilas;
    std::cout<<"Digite el numero de columnas: ";
    std::cin>>nColumnas;

    puntero_matriz = new int*[nFilas]; //Reservando memoria para las filas
    for(int i = 0; i < nFilas; i++){
        puntero_matriz[i] = new int[nColumnas]; //Reservando memoria para las columnas
    }

    std::cout<<"\nDigitando elementos de la matriz"<<std::endl;
    for(int i = 0; i < nFilas; i++){
        for(int j = 0; j < nColumnas; j++){
            std::cout<<"Digite un numero ["<<i<<"]["<<j<<"]: ";
            std::cin>>*(*(puntero_matriz+i)+j);
        }
    }

    std::cout<<"\nMostrando la matriz"<<std::endl;
    for(int i = 0; i < nFilas; i++){
        for(int j = 0; j < nColumnas; j++){
            std::cout<<*(*(puntero_matriz+i)+j)<<" ";
        }
        std::cout<<"\n";
    }
}

void sumaMatrices(){
    int **puntero_matriz1, **puntero_matriz2, nFilas, nCol;

    std::cout<<"Digite el numero de filas: ";
    std::cin>>nFilas;
    std::cout<<"Digite el numero de columnas: ";
    std::cin>>nCol;

    //  Reservando memoria para la matriz 1
    puntero_matriz1 = new int*[nFilas];
    for(int i = 0; i < nFilas; i++){
        puntero_matriz1[i] = new int[nCol];
    }

    std::cout<<"\nDigitando elementos de la matriz 1"<<std::endl;
    for(int i = 0; i < nFilas; i++){
        for(int j = 0; j < nCol; j++){
            std::cout<<"Digite un numero ["<<i<<"]["<<j<<"]: ";
            std::cin>>*(*(puntero_matriz1+i)+j);
        }
    }

    //  Reservando memoria para la matriz 2
    puntero_matriz2 = new int*[nFilas];
    for(int i = 0; i < nFilas; i++){
        puntero_matriz2[i] = new int[nCol];
    }

    std::cout<<"\nDigitando elementos de la matriz 2"<<std::endl;
    for(int i = 0; i < nFilas; i++){
        for(int j = 0; j < nCol; j++){
            std::cout<<"Digite un numero ["<<i<<"]["<<j<<"]: ";
            std::cin>>*(*(puntero_matriz2+i)+j);
        }
    }

    //  Suma de las matrices
    for(int i = 0; i < nFilas; i++){
        for(int j = 0; j < nCol; j++){
            *(*(puntero_matriz1+i)+j) += *(*(puntero_matriz2+i)+j);
        }
    }

    std::cout<<"\nMostrando la matriz suma"<<std::endl;
    for(int i = 0; i < nFilas; i++){
        for(int j = 0; j < nCol; j++){
            std::cout<<*(*(puntero_matriz1+i)+j)<<" ";
        }
        std::cout<<"\n";
    }
}

void punteroEstructura(){
    std::cout<<"Digite su nombre: ";
    std::cin.getline(puntero_persona->nombre, 30, '\n');
    std::cout<<"Digite su edad: ";
    std::cin>>puntero_persona->edad;

    std::cout<<"\nNombre: "<<puntero_persona->nombre<<std::endl;
    std::cout<<"Edad: "<<puntero_persona->edad<<std::endl;

}

void punteroEstructura2(){
    for(int i = 0; i < 3; i++){
        std::cin.ignore();
        std::cout<<"Digite su nombre: ";
        std::cin.getline((puntero_alumno+i)->nombre, 30, '\n');
        std::cout<<"Digite su edad: ";
        std::cin>>(puntero_alumno+i)->edad;
        std::cout<<"Digite su promedio: ";
        std::cin>>(puntero_alumno+i)->promedio;
    }

    std::cout<<"La calificacion mas alta es de: "<<std::endl;
    float mayor = 0;
    int pos;
    for(int i = 0; i < 3; i++){
        if((puntero_alumno+i)->promedio > mayor){
            mayor = (puntero_alumno+i)->promedio;
            pos = i;
        }
    }

    std::cout<<"Nombre: "<<(puntero_alumno+pos)->nombre<<std::endl;
    std::cout<<"Edad: "<<(puntero_alumno+pos)->edad<<std::endl;
    std::cout<<"Promedio: "<<(puntero_alumno+pos)->promedio<<std::endl;


}
//  FIN DE CODIGO