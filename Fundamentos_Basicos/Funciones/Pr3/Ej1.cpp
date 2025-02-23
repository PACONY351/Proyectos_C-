#include<iostream>

void menu();
void calcular(int, int&, int&, int&);

int main(){

	menu();


	return 0;
}

void menu(){
	int seg = 0, totalSeg = 0, horas = 0, min = 0;
	std::cout<<"Ingresa los segundos"<<std::endl;
	std::cin>>totalSeg;
	
	calcular(totalSeg, horas, min, seg);

	std::cout<<"Horas: "<<horas<<std::endl;
	std::cout<<"Minutos: "<<min<<std::endl;
	std::cout<<"Segundos: "<<seg<<std::endl;
}

void calcular(int totalSeg, int& horas, int& min, int& seg){
	horas = totalSeg/3600;
	totalSeg %= 3600;
	
	min = totalSeg/60;

	seg = totalSeg%60;
}

