#include <stdio.h>

void menu();
void opcionesMenu(int);

void saludar();
void sumar();
void matriz();

int main(){
    menu();

    return 0;
}

void menu(){
    int op=0;
    printf("\n+-------------------------------+\n");
    printf("|              MENU             |\n");
    printf("| 1- Saludar en C               |\n");
    printf("| 2- Sumar en C                 |\n");
    printf("| 3- Matriz                     |\n");
    printf("+-------------------------------+\n");

    do{
        printf("Op: ");
        scanf("%d",&op);
        if(op < 0 || op > 10){
            printf("Opcion invalida.\n");
        }
    }while(op < 0 || op > 10);

    opcionesMenu(op);
}

void opcionesMenu(int op){
    switch (op)
    {
    case 1 :
        saludar();
        break;
    case 2 :
        sumar();
        break;
    case 3 :
        matriz();    
    default:
        break;
    }
}

void saludar(){
    printf("+----------------------------HOLA MUNDO---------------------------+\n");
    printf("Este archiv .c fue echo con el proposito de aprender un poco\n");
    printf("de los fundamentos basicos de la programación en C en base a C++\n");
    printf("esto con el objetivo de emplearlo en los sistemas embebidos\n");
    printf("                                #####      \n");
    printf("                              ##     ##    \n");
    printf("                             #  #   #  #   \n");
    printf("                             #   ###   #   \n");
    printf("                              ##     ##    \n");
    printf("                                #####      \n");
    printf("                                 # #       \n");
    printf("                                #   #      \n");
    printf("                                #   #      \n");
    printf("                                #   #      \n");
    printf("                                #   #      \n");
    printf("                                #####      \n");
}

void sumar(){
    int num1,num2,res;
    printf("Dame dos numeros \n");
    scanf("%d %d", &num1, &num2);
    printf("Respuesra: %d", num1 + num2);
    printf("\n");
}

void matriz(){
    int tabla[2][2];

    printf("Dame 4 numeros \n");
    for(int i = 0 ; i < 2; i++){
        for(int j = 0; j < 2 ; j++){
            scanf("%d", &tabla[i][j]);
        }
    }

    printf("\nEstos son los datos");
    for(int i = 0 ; i < 2; i++){
        printf("\n");
        for(int j = 0; j < 2 ; j++){
            printf("%d ", tabla[i][j]);
        }
    }
    printf("\n");
}
