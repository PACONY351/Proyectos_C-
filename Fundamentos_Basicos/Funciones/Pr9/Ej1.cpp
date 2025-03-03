#include<iostream>



struct Complejo{
	float real,imaginario;
}z1,z2;


void pedirDatos();
Complejo suma(Complejo, Complejo);
void mostrarDatos(Complejo);

int main(){
	
	pedirDatos();
	mostrarDatos(suma(z1,z2));
	
	return 0;
}

void pedirDatos(){
	std::cout<<"De z1 dame"<<std::endl;
	std::cout<<"Real: ";std::cin>>z1.real;
	std::cout<<"Imaginaria: ";std::cin>>z1.imaginario;
	std::cout<<"De z2 dame"<<std::endl;
        std::cout<<"Real: ";std::cin>>z2.real;
        std::cout<<"Imaginaria: ";std::cin>>z2.imaginario;
}

Complejo suma(Complejo, Complejo){
	z1.real += z2.real;
	z1.imaginario += z2.imaginario;
	return z1;
}

void mostrarDatos (Complejo z){
	std::cout<<"-------Resultado--------"<<std::endl;
	std::cout<<"Imaginario: "<<z.imaginario<<std::endl;
	std::cout<<"Real: "<<z.real<<std::endl;
}
