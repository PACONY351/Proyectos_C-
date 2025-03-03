#include <iostream>

struct Fecha {
    int dia, mes, anio;
};

// Declaración de funciones
void pedirDatos(Fecha&, Fecha&);
Fecha comparar(Fecha, Fecha);
void mostrar(Fecha);

int main() {
    Fecha f1, f2;
    pedirDatos(f1, f2);
    Fecha masReciente = comparar(f1, f2);
    mostrar(masReciente);
    return 0;
}

void pedirDatos(Fecha& f1, Fecha& f2) {
    std::cout << "Primera fecha" << std::endl;
    std::cout << "Día: "; std::cin >> f1.dia;
    std::cout << "Mes: "; std::cin >> f1.mes;
    std::cout << "Año: "; std::cin >> f1.anio;

    std::cout << "Segunda fecha" << std::endl;
    std::cout << "Día: "; std::cin >> f2.dia;
    std::cout << "Mes: "; std::cin >> f2.mes;
    std::cout << "Año: "; std::cin >> f2.anio;
}

Fecha comparar(Fecha f1, Fecha f2) {
    if (f1.anio > f2.anio) {
        return f1;
    } else if (f1.anio < f2.anio) {
        return f2;
    } else { 
        if (f1.mes > f2.mes) {
            return f1;
        } else if (f1.mes < f2.mes) {
            return f2;
        } else { 
            if (f1.dia > f2.dia) {
                return f1;
            } else {
                return f2;
            }
        }
    }
}

void mostrar(Fecha f) {
    std::cout << "\nEsta es la fecha más reciente:" << std::endl;
    std::cout << "DD: " << f.dia << " MM: " << f.mes << " AAAA: " << f.anio << std::endl;
}
