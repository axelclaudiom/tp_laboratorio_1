/*
 * melgartp1.c
 *
 *  Created on: 24 sep. 2021
 *      Author: Axel
 */

#include <stdio.h>
#include <stdlib.h>
#include "melgartp1.h"

int ingOperandoUno(void)
{
    int ingresoUno;
    printf("Ingrese 1er Operando: ");
    scanf("%d" , &ingresoUno);
    return ingresoUno;
}

int ingOperandoDos(void)
{
    int ingresoDos;
    printf("Ingrese 2do Operando: ");
    scanf("%d" , &ingresoDos);
    return ingresoDos;
}

int calcularOperaciones(int a, int b, int gatillo)
{
    int num1 = a;
    int num2 = b;
    int flagDiv =0;
    int flagCalculos = 0;
    int retSuma;
    int retDiv;
    int retResta;
    int retMulti;
    int retAFact;
    int retBFact;

    float pResDiv;
    int pResSuma;
    int pResResta;
    int pResMulti;
    int pResAFact;
    int pResBFact;


    retSuma = sumar(num1, num2, &pResSuma);
    retResta = resta(num1, num2, &pResResta);
    retDiv = dividir(num1, num2, &pResDiv);
    retMulti = multiplicar(num1, num2, &pResMulti);
    retAFact = factorialRec(num1, &pResAFact);
    retBFact = factorialRec(num2, &pResBFact);

    if(retSuma == 1 && retResta == 1 && retMulti == 1 && retAFact == 1 && retBFact == 1)
    {
        flagCalculos = 1;
    }
    if(retDiv == 0)
    {
        flagDiv = 1;
    }
    if(gatillo == 1 && flagCalculos == 1)
    {
        mostrar(num1, num2, pResSuma , pResResta ,pResDiv, pResMulti, pResAFact, pResBFact, flagDiv, flagCalculos);
    }
    return flagCalculos;
}

int sumar(int a, int b, int* c){
    int todoOk = 0;
    if(c != NULL)
    {
        *c = a + b;
        todoOk = 1;
    }
    return todoOk;
}

int resta(int a, int b, int* c){
    int todoOk = 0;
    if(c != NULL)
    {
        *c = a - b;
        todoOk = 1;
    }
    return todoOk;
}

int dividir(int dividendo, int divisor, float * pCociente)
{
    int todoOk = 0;
    if(pCociente != NULL && divisor != 0)
    {
        *pCociente = (float) dividendo / divisor;
        //*pCociente = dividendo / divisor;
        todoOk = 1;
    }
    return todoOk;
}

int multiplicar(int a, int b, int* c){
    int todoOk = 0;
    if(c != NULL)
    {
        *c = a * b;
        todoOk = 1;
    }
    return todoOk;
}

int factorialRec(int a, int* c){
    int todoOk = 0;
    if(c != NULL)
    {
        int fact = 0;
        if(a >=0)
        {
            fact= 1;
            for(int i = 2; i <= a; i++){
                fact = fact * i;
            }
        }
        *c = fact;
        todoOk = 1;
    }
    return todoOk;
}


int mostrar(int num1, int num2, int resSuma , int resResta , float resDiv, int resMulti, int resAFact, int resBFact, int flagDiv, int flagCalculos)
{
    if(flagCalculos == 1)
    {
        printf("- El resultado de %d + %d es: %d \n", num1, num2, resSuma);
        printf("- El resultado de %d - %d es: %d \n", num1, num2, resResta);
        if(flagDiv == 1)
        {
            printf("-! No se pudo Dividir, el divisor no puede ser 0 \n");
        }
        else
        {
            printf("- El Resultado de %d / %d es: %f \n", num1, num2 , resDiv);
        }

        printf("- El resultado de %d * %d es: %d \n", num1, num2 , resMulti);
        printf("- El factorial de %d es: %d y el factorial de %d es: %d \n", num1 , resAFact, num2, resBFact);
    }
    else
    {
        printf("Para mostrar los resultados, primero tenes que hacer los calculos");
    }


    return 0;
}
