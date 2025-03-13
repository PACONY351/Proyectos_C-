	//					PILA  --  LIFO
	/*				
		UNA PILA ES UNA STRUCTURA DE DATOS DE ENTRADAS ORDENADAS
		TALES QUE SOLO SE PUEDEN INTRODUCIR Y ELIMINAR POR UN 
		EXTREMO, LLAMADO CIMA.

		LAS OPERACIONES USUALES EN LA PILA SON INSERTAR Y QUITAR

		LA OPERACION INSERTAR (push) AÑADE UN ELEMENTO EN LA CIMA
		DE LA PILA Y LA OPERACION QUITAR (pop) ELIMINA O SACA UN
		ELEMENTO DE LA PILA. 
	*/
	//					NODO	
	/*
		UN NODO CONTIENE UN DATO Y UN PUNTERO CON LA CAPACIDAD DE
		ALMACENAR LA DIRECCION DEL SIGUIENTE NODO.

		struct nodo{
			int dato;
			nodo *puntero
		}
	
	*/
	//					INSERTAR ELEMENTOS EN LA PILA
	/*
	1- Crear el espacio en memoria para almacenar un nodo
	2- Cargar el valor dentro del nodo (dato).
	3- Cargar el puntero pila dentro del nodo(*siguiente).
	4- Asignar el nuevo nodo a pila.



			PASO 1:

	CREAR EL ESPACIO EN MEMORIA PARA ALMACENAR UN NODO

	pila = NULL;   ----La variable pila se inicializa 

	struct Nodo{
		int dato;
		Nodo *siguiente;
	}

	Nodo *nuevo nodo = new Nodo();

	void agregarPila(Nodo *&pila, int n){
		Nodo *nuevo_nodo = new Nodo();
	}


			PASO 2: 

	CARGAR EL VALOR DENTRO DEL NODO(DATO). 

	nuevo_nodo -> = 10;

	void agregarPila(Nodo *&pila, int n){
		Nodo *nuevo_nodo = new Nodo();
		nuevo_nodo -> dato = n;
	}

			PASO 3: 
	
	CARGAR EL PUNTERO PILA DENTRO DEL NODO (*siguiente). 


	nuevo_nodo -> siguiente = pila;

	void agregarPila(Nodo *&pila, int n){
		Nodo *nuevo_nodo = new Nodo();
		nuevo_nodo -> dato = n;
		nuevo_nodo -> sigiente = pila;
	}

			PASO 4: 
	
	ASIGNAR EN NUEVO NODO A PILA

	pila = nuevo_nodo;

	void agregarPila(Nodo *&pila, int n){
		Nodo *nuevo_nodo = new Nodo();
		nuevo_nodo -> dato = n;
		nuevo_nodo -> sigiente = pila;
		pila = nuevo_nodo;
	}
*/
	//					ELIMINAR UN ELEMENTO DE LA PILA	
	/*
			PASO 1: 
	
			CREAR UNA VARIABLE *aux DE TIPO Nodo

	Nodo *aux = pila;

	void sacarPila(Nodo *&pila, int &n){
		Nodo *aux = pila;
	}

			PASO 2: 

			IGUALAR EL n A aux -> dato

	n = aux -> dato;

	void sacarPila(Nodo *&pila, int &n){
		Nodo *aux = pila;
		n = aux -> dato;
	}

			PASO 3: 
			PASAR PILA A SIGUIENTE NODO

	pila = aux -> siguiente;

	void sacarPila(Nodo *&pila, int &n){
		Nodo *aux = pila;
		n = aux -> dato;
		pila = aux -> siguiente;
	}

			PASO 4:
			ELIMINAR aux
	
	delete aux;

	void sacarPila(Nodo *&pila, int &n){
		Nodo *aux = pila;
		n = aux -> dato;
		pila = aux -> siguiente;
		delete aux;
	}	

	*/



#include <iostream>
#include <stdlib.h>
	
//	ESTRUCTURAS
struct Nodo {		
	int dato;
	Nodo* siguiente;
};
	
// GLOBALES
Nodo* pila = NULL;
int dato = 0;
	
//	PROTOTIPOS
int menuPrincipal();
void opcionMenu(int);
	
void opAgregar();
void opSacar();
void opMostrar(Nodo*&);
	
void agregarPila(Nodo*&, int);
void sacarPila(Nodo*&, int&);
	
int main() {
	opcionMenu(menuPrincipal());
	return 0;
}
	
//FUNCIONES
int menuPrincipal() {
	int opcion = -1;
	
	std::cout << "\n||- TEMA: PILAS -||" << std::endl;
	std::cout << "||               ||" << std::endl;
	std::cout << "|| 1 - Agregar   ||" << std::endl;
	std::cout << "|| 2 - Eliminar  ||" << std::endl;
	std::cout << "|| 3 - Mostar    ||" << std::endl;
	std::cout << "|| 4 - Salir     ||" << std::endl;
	
	do {
		std::cout << "|| Opcion: ";
		std::cin >> opcion;
	
		if (std::cin.fail()) { // Verificar si la entrada es válida
			std::cin.clear();  // Limpiar el estado de error
			std::cin.ignore(10000, '\n'); // Descartar la entrada inválida
			opcion = -1;
		}
	
	} while (opcion < 1 || opcion > 4);
	
	return opcion;
}
	
void opcionMenu(int op) {
	switch (op) {
		case 1:
			opAgregar();
			opcionMenu(menuPrincipal());
			break;
		case 2:
			opSacar();
			opcionMenu(menuPrincipal());
			break;
		case 3:
			opMostrar(pila);
			opcionMenu(menuPrincipal());
			break;
		case 4:
			std::cout << "||----- ADIOS -----||" << std::endl;
			exit(0); // Finalizar el programa
			break;
		default:
			break;
	}
}
	
void opAgregar() {
	int dato;
	do {
		std::cout << "Digite un numero (0 para terminar): ";
		std::cin >> dato;
	
			if (dato != 0) {
				agregarPila(pila, dato);
			}
	
	} while (dato != 0);
}
	
void opSacar() {
	std::cout << "Sacando los elementos de la Pila: " << std::endl;
	std::cout << "[-";
		
	while (pila != NULL) {
		sacarPila(pila, dato);
		std::cout << "<" << dato << ">";
	}
	
	std::cout << "-]" << std::endl;
}
	
void agregarPila(Nodo*& pila, int n) {
	Nodo* nuevo_nodo = new Nodo();
	nuevo_nodo->dato = n;
	nuevo_nodo->siguiente = pila;
	pila = nuevo_nodo;
	
	std::cout << "Elemento " << n << " agregado a la pila." << std::endl;
}
	
void sacarPila(Nodo*& pila, int& n) {
	if (pila == NULL) {
		std::cout << "La pila esta vacia." << std::endl;
		return;
	}
	
	Nodo* aux = pila;
	n = aux->dato;
	pila = aux->siguiente;
	delete aux;
}
	
void opMostrar(Nodo*& pila){
	Nodo* aux = pila;
	std::cout << "Mostrando los elementos de la Pila: " << std::endl;
	while (aux != NULL) {
		std::cout<< aux -> dato << " ";
		aux = aux -> siguiente;
	}
	std::cout << std::endl;
}
	