#include <stdio.h>
#include <stdlib.h>
#include "arrayEmployees.h"
//#include "datawarehouse.h"
#include "ctype.h"
#include "string.h"
#include "inputs.h"

#define ASC 1
#define DESC 0
#define TAM 1000

int main()
{
	setbuf(stdin, NULL);
    char seguir = 's';
    int nextId = 0;
    int flagAlta = 0;
    eEmployee list[TAM];

    if(!initEmployees(list, TAM))
    {
        printf("Inicializado correcto\n");
    }
    //hardcodearPersonas(list,TAM, 10, &nextId);
    //fflush(stdin);
    do
    {
        switch(menu())
        {
        case 1:

            if(!cargarEmpleado(list,TAM, &nextId))
            {
                printf("Alta exitosa \n");
                flagAlta = 1;
            }
            else
            {
                printf("No se pudo realizar el alta \n");
            }
            break;
        case 2:
            if(flagAlta)
            {
                if(!bajaPersona(list,TAM))
                {
                    printf("Baja Exitosa \n");
                }
                else
                {
                    printf("No se pudo realizar la baja \n");
                }
            }
            else{
                printf("Para hacer una baja primero tenes que cargar algun empleado \n");
            }
            break;
        case 3:
            if(flagAlta)
            {
                if(!modificarEmployee(list,TAM))
                {
                    printf("Modificacion exitosa \n");
                }
                else
                {
                    printf("No se pudo realizar la modificacion \n");
                }
            }
            else
            {
                printf("Para hacer una modificacion primero tenes que cargar algun empleado \n");
            }
            break;
        case 4:
            if(flagAlta)
            {
                switch(menuInformes())
                {
                case 1:
                    sortEmployees(list, TAM, ASC);
                    printEmployees(list, TAM);
                    //system("pause");
                    break;
                case 2:
                    salariosOrden(list,TAM);
                    break;
                }
            }
            else
            {
                printf("Para hacer un informe primero tenes que cargar algun empleado \n");
            }
            break;
        case 5:
            printf("salir \n");
            seguir = 'n';
            break;
        default:
            printf("opcion invalida");

        }
        system("pause");
    }
    while (seguir=='s');
    return 0;
}
