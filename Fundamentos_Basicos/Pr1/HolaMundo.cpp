#include <iostream>

void menu();

int main(){
	
	std::cout<<"Hola Mundo"<<std::endl;
	std::cout<<"Este es mi primer proyecto con C++, en Terminal de Fedora"<<std::endl;

	menu();	

	return 0;
}

void menu(){
	std::cout<<"Escoje una opcion de 0-3"<<std::endl;
	std::cout<<"Mini Calculadora"<<std::endl;
}
