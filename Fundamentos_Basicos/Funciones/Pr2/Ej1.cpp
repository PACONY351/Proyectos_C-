#include<iostream>


void calcular(int, int, int&, int&);

int main (){
	
	int num1 ,num2, suma=0, producto=0;
	std::cout<<"Digite 2 numeros"<<std::endl;
	std::cin>>num1;
	std::cin>>num2;

	calcular(num1, num2, suma, producto);

	std::cout<<"La suma es: "<<suma<<std::endl;
	std::cout<<"El producto es: "<<producto<<std::endl;

	return 0;
}

void calcular(int num1, int num2, int& suma, int& producto){
	suma = num1 + num2;
	producto = num1 * num2;
}
