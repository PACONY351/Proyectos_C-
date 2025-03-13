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



#include<iostream>
#include<stdlib.h>

//	ESTRUCTURAS
struct Nodo{
	int dato;
	Nodo *siguiente;
};
//	PROTOTIPOS
void agregarPila(Nodo *&, int);

int main(){

	Nodo *pila = NULL;
	int n1,n2;

	std::cout<<"Digite un numero: ";
	std::cin>>n1;
	agregarPila(pila, n1);




	return 0;
}

//FUNCIONES
void agregarPila(Nodo *&pila, int n){
	Nodo *nuevo_nodo = new Nodo();
	nuevo_nodo -> dato = n;
	nuevo_nodo -> siguiente = pila;
	pila = nuevo_nodo;

	std::cout<<"Elemento "<<n<<" agregado a la pila."<<std::endl;
}

void sacarPila(Nodo *& pila, int &n){
	
}
