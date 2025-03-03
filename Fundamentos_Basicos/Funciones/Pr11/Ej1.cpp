#include <iostream>


int factorial(int);
int pedirDatos();

int main() { 
    int numero = pedirDatos(); 
    int resultado = factorial(numero); 
    std::cout << "El factorial de " << numero << " es: " << resultado << std::endl;
    return 0;
}

int factorial(int n) { 
    if (n == 0 || n == 1) { 
        return 1;
    } else { 
        return n * factorial(n - 1); 
    }
}

int pedirDatos() { 
    int num = 0;
    std::cout << "Dame un número entero: ";
    std::cin >> num;
    return num;  
}

