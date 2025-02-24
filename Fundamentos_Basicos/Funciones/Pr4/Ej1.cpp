#include<iostream>

void cuadrado(int vec[], int); 
void impresion(int vec[], int);

int main(){
	const int TAM = 5;
	int vec[TAM] = {1,2,3,4,5};
	
	cuadrado(vec, TAM);
	impresion(vec, TAM);
	
	return 0;
}

void cuadrado(int vec[], int tam){
	for(int i=0;i<tam;i++){
		vec[i] *= vec[i];
	}

}

void impresion(int vec[], int tam){
	for(int i=0; i<tam; i++){
		std::cout<<vec[i]<<std::endl;
	}
}
