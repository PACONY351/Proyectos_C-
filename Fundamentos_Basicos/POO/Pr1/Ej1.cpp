#include<iostream>
#include<stdlib.h>


class Rectangulo{
    private:
        float largo;
        float ancho;

    public:
        Rectangulo(float _largo, float _ancho);
        void perimetro();
        void area();
};

Rectangulo::Rectangulo(float _largo, float _ancho){
    largo = _largo;
    ancho = _ancho;
}

void Rectangulo::perimetro(){
    std::cout<<"Perimetro: "<<largo*ancho<<std::endl;
}

void Rectangulo::area(){
    std::cout<<"Area: "<<(ancho*2)+(largo*2)<<std::endl;
}

int main(){
    Rectangulo r1 = Rectangulo(10.3,5.1);
    r1.area();
    r1.perimetro();
    return 0;
}