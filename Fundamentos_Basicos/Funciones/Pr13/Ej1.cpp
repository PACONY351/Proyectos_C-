#include<iostream>


void pedirDatos();
int res(int, int);

int main(){

	pedirDatos();	

	return 0;
}

void pedirDatos(){
	int numero, potencia, re;
	do{
		std::cout<<"Numero: ";std::cin>>numero;
	}while(numero < 0);
	do{
		std::cout<<"Potencia: ";std::cin>>potencia;
	}while(potencia < 0);

	re = res(numero, potencia);

	std::cout<<"Res: "<<re;
}	

int res(int numero, int potencia){
	if(potencia > 0){
		return numero;
	}
	numero = numero * res(numero, potencia -1);
}

