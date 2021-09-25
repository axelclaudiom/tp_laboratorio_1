/*
 ============================================================================
 Name        : tp1.c
 Author      : Axel Claudio Melgar
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "melgartp1.h"

/** \brief muestra el menu de opciones y retorna la opcion seleccionada
 *
 * \return int
 *
 */
int menu();

int main()
{
    char seguir = 's';
    int operandoIngUno = -1;
    int operandoIngDos = -1;
    int flagCalculo = 0;

    do {
        system("cls");
        switch(menu(operandoIngUno, operandoIngDos, flagCalculo))
        {

        case 1:
            operandoIngUno = ingOperandoUno();

            break;

        case 2:
            operandoIngDos = ingOperandoDos();
            break;

        case 3:
            if(operandoIngDos != -1 && operandoIngDos != -1)
            {
                flagCalculo = calcularOperaciones(operandoIngUno, operandoIngDos, 0);
            }
            else
            {
                printf("Para hacer los calculos, primero tenes que ingresar los operandos");
            }
            break;

        case 4:
            if(flagCalculo == 1)
            {
                calcularOperaciones(operandoIngUno, operandoIngDos, 1);
            }
            else
            {
                printf("Para mostrar resultados, primero tenes que sacar los calculos");
            }
            break;
        case 5:
            seguir = 'n';
            break;

        default:
            printf("Opcion invalida \n");
        }
        system("pause");

    }while(seguir == 's');
    return EXIT_SUCCESS;
}

int menu(int a , int b, int flagCalculo){

        int opcion;

        system("cls");
        printf("Menu de opciones \n\n");
        if(a != -1)
        {
            printf("1. Ingresar Operando A = %d \n" , a);
        }
        else
        {
            printf("1. Ingresar Operando A = x \n");
        }

        if(b != -1)
        {
            printf("2. Ingresar Operando B = %d \n" , b);
        }
        else
        {
            printf("2. Ingresar Operando B = y \n");
        }

        if(a != -1 && b != -1)
        {
            printf("3. Calcular todas las operaciones\n");
        }
        else{
            printf("(!) 3. Calcular todas las operaciones \n");
        }
        if(flagCalculo)
        {
            printf("4. Informar resultados\n");
        }
        else{
            printf("(!) 4. Informar resultados\n");
        }
        printf("5. salir\n");
        printf("Indique opcion: ");
        fflush(stdin);
        scanf("%d", &opcion);

        return opcion;
}
