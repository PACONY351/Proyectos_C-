// SOBRE CARGA DE CONSTRUCTORES

#include<iostream>
#include<stdlib.h>


class Tiempo{
    private:
        int horas,min,seg;
    public:
        Tiempo(int, int, int);
        Tiempo(int);
        void verHora();
};

Tiempo::Tiempo(int _seg, int _min, int _horas){
    seg = _seg;
    min = _min;
    horas = _horas;
}

Tiempo::Tiempo(int _seg){
    if(_seg > 3600){
        horas = _seg / 3600;
        _seg = _seg % 3600;
        min = _seg / 60;
        seg = _seg % 60;
    }else if(_seg > 60){
        horas = 0;
        min = _seg / 60;
        seg = _seg % 60;
    }else{
        horas = 0;
        min = 0;
        seg = _seg;
    } 
}

void Tiempo::verHora(){
    std::cout<<"Hora: "<<horas<<"/"<<min<<"/"<<seg<<std::endl;
}

int main(){
    Tiempo t1 = Tiempo(12,2,45);
    Tiempo t2 = Tiempo(3684);
    t1.verHora();
    t2.verHora();
    return 0;
}