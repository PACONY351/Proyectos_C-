#include<iostream>


template <class TIPOD>
void despliegue(TIPOD dato);

int maximo(int n1, int n2, int n3);

int main(){

	int dato1 = 4;	
	float dato2 = 15.67;
	double dato3 = 567.7890;
	char dato4 = 'a';

	despliegue(dato1);
	despliegue(dato2);
	despliegue(dato3);
	despliegue(dato4);
	
	std::cout<<"El numero maximo de: 20, 50, 44 "<<std::endl;
	std::cout<<"es: "<<maximo(20, 50, 44);
	std::cout<<std::endl;
	
	return 0;
}

template <class TIPOD>
void despliegue(TIPOD dato){
	std::cout<<"El dato es: "<<dato<<std::endl;
}

int maximo(int n1, int n2, int n3){
	if(n1 > n2 && n1 > n3){
		return n1;
	}else if(n2 > n1 && n1 > n3){
		return n2;
	}else{
		return n3;
	}
}
