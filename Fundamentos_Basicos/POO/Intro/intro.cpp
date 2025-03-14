// CLASES EN C++

#include<iostream>
#include<stdlib.h>

class Persona{
    private:
        int edad;
        std::string nombre;
    
    public:
        Persona(int,std::string);
        void leer();
        void correr();
};

Persona::Persona(int _edad, std::string _nombre){
    edad = _edad;
    nombre = _nombre;
}

void Persona::leer(){
    std::cout<<"Soy "<<Persona::nombre<<" y estoy leyendo un comic"<<std::endl;
}

void Persona::correr(){
    std::cout<<"Soy "<<Persona::nombre<<" y estoy corriendo un maraton"<<std::endl;
}


int main(){

    Persona p1 = Persona(20, "Francisco");
    p1.correr();
    p1.leer();

    return 0;
}