#include<iostream>

void solicitarNum();
int suma(int);

int main(){
	solicitarNum();
	return 0;
}

void solicitarNum(){
	int num1,res;
	std::cout<<"Dame el primer numero: ";std::cin>>num1;
	res = suma(num1);
	std::cout<<"Res: "<<res<<std::endl;
}

int suma(int num1){
	return num1 + suma(num1 -1);
}
