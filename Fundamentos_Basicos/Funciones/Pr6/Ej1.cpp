#include<iostream>

//PROTOTIPO DE FUNCION
int pedirDatos();
void datosVec(int);
void imprimirDatos();
//DATOS GLOBALES
int vec[100], tam;
//MAIN
int main(){

	datosVec(pedirDatos());
	imprimirDatos();

	return 0;
}

//FUNCIONES
int pedirDatos(){
	std::cout<<"Digite el tamaño del vector: ";std::cin>>tam;
	return tam;
}
void datosVec(int tam){
	for(int i = 0; i < tam ; i++){
		std::cout<<"Dato numero "<<i+1<<" :";std::cin>>vec[i];
	}
}
void imprimirDatos(){
	std::cout<<"Datos positivos"<<std::endl;
	for(int i=0; i<tam; i++){
		std::cout<<vec[i]<<std::endl;
	}

	std::cout<<"Datos negativos"<<std::endl;
	for(int i = 0; i<tam; i++){
		std::cout<<vec[i] * -1<<std::endl;
	}
}
