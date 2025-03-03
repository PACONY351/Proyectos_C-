#include<iostream>

//PROTOTIPO DE FUNCIÓN
void mostrarMatriz(int m[][3],int,int);
void mostrarMatrizC(int m[][3],int,int);
//DATOS GLOBALES
//MAIN
int main(){
	const int NFILAS = 2;
	const int NCOL = 3;
	int m[NFILAS][NCOL] = {{1,2,3},{4,5,6}};
	mostrarMatriz(m,NFILAS,NCOL);
	mostrarMatrizC(m,NFILAS,NCOL);
	return 0;
}
//FUNCIÓNES
void mostrarMatriz(int m[][3],int NFILAS, int NCOL){
	for(int i = 0; i < NFILAS ; i++){
		for(int j = 0; j < NCOL; j++){
			std::cout<<m[i][j]<<" ";
		}
		std::cout<<""<<std::endl;
	}
}

void mostrarMatrizC(int m[][3], int NFILAS, int NCOL){
	for(int i = 0; i < NFILAS; i++){
		for(int j = 0; j < NCOL ; j++){
			std::cout<<m[i][j] * m[i][j]<<" ";
		}
	std::cout<<""<<std::endl;
	}
}
