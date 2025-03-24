/*
 * main.c
 *
 *  Created on: Mar 23, 2025
 *      Author: franciso
 */
#include<stdio.h>
#include<stdint.h>

	void menuPrincipal();
	void opcionesPrincipales(int);
	void tiposDeDatos();

int main(){
	menuPrincipal();
	tiposDeDatos();

	return 0;
}

void menuPrincipal(){
	printf("+------------Menu------------+\n");
	printf("| 1- stdint.h                |\n");


}

void opcionesPrincipales(int op){
	switch (op) {
		case 1:
			tiposDeDatos();
			break;
		default:
			break;
	}

}

void tiposDeDatos(){
	int8_t *punto1;
	int16_t *punto2;
	int32_t *punto3;
	uint8_t *punto11;
	uint16_t *punto22;
	uint32_t *punto33;

	printf("Estos son los tipos de datos segun\nla libreria de stdint.h\n");
	int8_t numero1 = 8;
	int16_t numero2 = 16;
	int32_t numero3 = 32;

	punto1 = &numero1;
	punto2 = &numero2;
	punto3 = &numero3;

	printf("int8_t   = %d  bits dirección: %p \n", numero1, (void*)punto1);
	printf("int16_t  = %d bits dirección: %p \n", numero2, (void*)punto2);
	printf("int32_t  = %d bits dirección: %p \n", numero3, (void*)punto3);

	uint8_t  numero11 = 8;
	uint16_t  numero22 = 16;
	uint32_t  numero33 = 32;

	punto11 = &numero11;
	punto22 = &numero22;
	punto33 = &numero33;

	printf("uint8_t  = %u  bits dirección: %p \n", numero11, (void*)numero11);
	printf("uint16_t = %u bits dirección: %p \n", numero22, (void*)numero22);
	printf("uint32_t = %u bits dirección: %p \n", numero33, (void*)numero33);



}
