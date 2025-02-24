#include<iostream>

//PROTORIPO DE FUNCIÓN
void pedirDatos();
void ingresarMatriz();
void imprimir();
//DATOS GLOBALES
int vec[100][100], tamx, tamy;
//MAIN
int main (){
	pedirDatos();
	ingresarMatriz();
	imprimir();
	return 0;
}

//FUNCIONES
void pedirDatos(){
	std::cout<<"Ingresa el tamaño de la matrix en X Y"<<std::endl;
	std::cout<<"X: ";std::cin>>tamx;
	std::cout<<"Y: ";std::cin>>tamy;
}
void ingresarMatriz(){
	std::cout<<"Ingresa los datos"<<std::endl;
	for(int i = 0; i < tamx; i++){
		for(int j = 0; j < tamy; j++){
			std::cin>>vec[i][j];
		}
	}
}
void imprimir(){
	for(int i = 0; i < tamx; i++){
		for(int j = 0; j < tamy; j++){
			std::cout<<vec[i][j];
		}
	}
}
