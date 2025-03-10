/* 
    PUNTEROS
&n = La direccion
*n = La variable para declarar
*/

#include<iostream>

int main(){

    int numero, *dir_numero;

    numero = 100;
    dir_numero = &numero;

    std::cout<<"Numero: "<<*dir_numero<<std::endl;
    std::cout<<"Direccion: "<<dir_numero<<std::endl;

    return 0;
}