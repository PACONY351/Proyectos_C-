#include<iostream>

//PROTOTIPO DE FUNCIÓN
void pedirDatos();
void imprimirRes();

//DATOS GLOBALES
int vec[100],tam;

//MAIN
int main (){

	pedirDatos();
	imprimirRes();

	return 0;
}

//FUNCIONES
void pedirDatos(){
	std::cout<<"Digite el numero de elementos: ";
	std::cin>>tam;

	for(int i=0 ; i<tam ; i++){
		std::cout<<"Dame el elemento numero "<<i+1<<std::endl;
		std::cin>>vec[i];
	}
}

void imprimirRes(){
	int res = 0;
	for(int i=0 ; i<tam ; i++){
		res += vec[i];
	}
	std::cout<<"Resultado a la suma de los vectores"<<std::endl;
	std::cout<<res<<std::endl;
}
