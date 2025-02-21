#include <iostream>

void menu();
void seleccionMenu(int opcion);
void suma();

int main(){
	
	std::cout<<"Hola Mundo"<<std::endl;
	std::cout<<"Este es mi primer proyecto con C++, en Terminal de Fedora"<<std::endl;

	menu();	

	return 0;
}

void menu(){
	int opcion;
	std::cout<<"Escoje una opcion de 0-3"<<std::endl;
	std::cout<<"1- Mini Calculadora"<<std::endl;
	std::cin>>opcion;
	seleccionMenu(opcion);
}

void seleccionMenu(int opcion){
	switch (opcion){
		case 1:
			std::cout<<"Bienvenido a la MiniCalduladora"<<std::endl;
			suma();
		break;
		default:
		break;
	}
}

void suma(){
	double n1, n2;
	
	std::cout<<"Dame el numero 1: ";std::cin>>n1;
	std::cout<<"Dame el numero 2: ";std::cin>>n2;
	std::cout<<"Resultado: "<<(n1 + n2)<<std::endl;
}
