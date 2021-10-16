#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include <ctype.h>
#include "inputs.h"

int menu()
{
    int opcion;
    system("cls");
    setbuf(stdin, NULL);
    printf("     ***ABM Empleados ***\n");
    printf("1 - Alta Empleado \n");
    printf("2 - Baja Empleado \n");
    printf("3 - Modificar Empleado \n");
    printf("4 - Informes \n");
    printf("5 - Salir \n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int menuInformes()
{
    int opcion;
    system("cls");
    setbuf(stdin, NULL);
    printf("     ***Menu Informes ***\n");
    printf("1 - Listado de empleados ordenados alfabeticamente por apellido y sector \n");
    printf("2 - Total y promedio de los salarios, y cuantos empleados superan el salario promedio \n");
    printf("3 - Salir \n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int initEmployees(eEmployee* list, int len)
{
    int todoOk = -1;
    if (list != NULL && len > 0)
    {
        for(int i = 0; i<len; i++)
        {
            list[i].isEmpty = 1;
        }
        todoOk = 0;
    }

    return todoOk;
}

int getIsEmpty(eEmployee list[], int len)
{
    int todoOk = -1;
    if (list != NULL && len > 0)
    {
        for(int i = 0; i<len; i++)
        {
            if(list[i].isEmpty)
            {
                todoOk = i;
                break;
            }
        }
    }

    return todoOk;
}

int addEmployee(eEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int retorno = -1;
    int retLugar;
    retLugar = getIsEmpty(list, len);
    if(list != NULL && len > 0)
    {
        if (retLugar != -1)
        {
            list[retLugar].id = id;
            strcpy(list[retLugar].name, name);
            strcpy(list[retLugar].lastName, lastName);
            list[retLugar].salary = salary;
            list[retLugar].sector = sector;
            list[retLugar].isEmpty = 0;

            retorno = 0;
        }
    }
    return retorno;
}

int cargarEmpleado(eEmployee list[], int len, int* pId)
{
	setbuf(stdin, NULL);
    int todoOk = -1;
    int retorno;
    eEmployee auxEmployee;

    if (list != NULL && len > 0)
    {
        system("cls");
        printf("         **** Alta Persona **** \n\n");
        auxEmployee.id = *pId;
        *pId += 1;

        pedirCadena(" Nombre del empleado: " , auxEmployee.name);

        pedirCadena(" Apellido del empleado: " ,auxEmployee.lastName);

       /* printf("Ingrese salario:");
        scanf("%f", &auxEmployee.salary);*/
        auxEmployee.salary = getFloat("\n Salario del empleado: ");

        /*printf("Ingrese sector:");
        scanf("%d", &auxEmployee.sector);*/
        auxEmployee.sector = getInt("\n Sector del empleado: ");

        auxEmployee.isEmpty = 0;

        retorno = addEmployee(list, len, auxEmployee.id, auxEmployee.name, auxEmployee.lastName, auxEmployee.salary, auxEmployee.sector);


        todoOk = retorno;
    }

    return todoOk;
}

void printEmployee(eEmployee p)
{
    printf("  %d  %10s       %10s      %.2f     %d  \n", p.id, p.name, p.lastName, p.salary, p.sector);
}


int printEmployees(eEmployee* list, int len)
{
    int todoOk = -1;
    int flag = 1;
    system("cls");
    if(list != NULL && len > 0)
    {
        system("cls");
        printf(" | ********* Lista de Empleados ********* |\n");
        printf("---------------------------------------------------------\n");
        printf(" Id       Nombre         Apellido     Salario   Sector \n");
        printf("---------------------------------------------------------\n");
        for(int i = 0; i< len; i++)
        {
            if(!list[i].isEmpty)
            {
                printEmployee(list[i]);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No hay personas para mostrar\n");
        }
        todoOk = 0;
    }
    return todoOk;

}

int findEmployeeById(eEmployee* list, int len,int id)
{
    int todoOk = -1;
    if(list != NULL && len > 0)
    {
        for(int i = 0; i < len; i++)
        {
            if(list[i].id == id && !list[i].isEmpty)
            {
                todoOk = i;
                break;
            }
        }
    }
    return todoOk;
}

int removeEmployee(eEmployee* list, int len, int id)
{
    int retorno = -1;
    if(list != NULL && len >0)
    {
        for(int i=0; i<len; i++)
        {
            if(list[i].id == id && !list[i].isEmpty)
            {
                list[i].isEmpty = 1;
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}


int bajaPersona(eEmployee list[], int len)
{
    int todoOk = -1;
    int indice;
    int id;
    int retorno;
    char confirma;
    if(list != NULL && len > 0)
    {
        system("cls");
        printf("        *** Baja Persona *** \n\n");
       /* printf("Ingrese id: ");
        scanf("%d", &id);*/
        id = getInt("\n Ingrese el id del empleado que desea dar de baja: ");

        indice = findEmployeeById(list, len, id);

        if (indice == -1)
        {
            printf("El ID %d no se encuentra en el sistema \n", id);
        }
        else
        {
            printEmployee(list[indice]);
            printf("Confirma Baja?: ");
            setbuf(stdin, NULL);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                retorno = removeEmployee(list, len, id);
                //lista[indice].isEmpty = 1;
                todoOk = retorno;
            }
            else
            {
                printf("Baja cancelada por el usuario");
            }

        }
        //todoOk = 1;
    }
    return todoOk;
}

int sortEmployees(eEmployee* list, int len, int order)
{
    int todoOk = -1;
    eEmployee auxPersona;
    if(list != NULL && len > 0 && order >= 0 && order <= 1)
    {
        for(int i=0; i < len -1; i++)
        {
            for(int j= i+1; j< len; j++)
            {
                //if((lista[i].sexo > lista[j].sexo) || (lista[i].sexo == lista[j].sexo && strcmp(lista[i].nombre, lista[j].nombre) >0 ))
                //if( ((strcmp(list[i].lastName, list[j].lastName) > 0 && list[i].sector == list[j].sector && order) /*|| list[i].sector > list[j].sector && order) || ((strcmp(list[i].lastName, list[j].lastName) > 0 && list[i].sector == list[j].sector && order) || list[i].sector < list[j].sector && !order)*/ )
                //if((list[i].sector > list[j].sector) || (list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) >0 ))
               if( (((list[i].sector > list[j].sector) || (list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) >0 )) && order) || (((list[i].sector < list[j].sector) || (list[i].sector == list[j].sector && strcmp(list[i].lastName, list[j].lastName) < 0 )) && !order))
               // if((strcmp(list[i].lastName, list[j].lastName) > 0 && list[i].sector == list[j].sector) || list[i].sector > list[j].sector)
                {
                    //if((list[i] > list[j] && order) || (list[i] < list[j] && !order))
                    auxPersona = list[i];
                    list[i] = list[j];
                    list[j] = auxPersona;
                }
            }
        }
        todoOk = 0;
    }
    return todoOk;
}

int salariosOrden(eEmployee list[], int len){
int todoOk = -1;
int flag = 1;
float salarioTotal = 0;
int contadorEmpleados = 0;
float promedioSalario = 0;
    if(list != NULL && len > 0)
    {
        system("cls");
        printf(" | ********* Lista de salarios ********* |\n");
        printf("---------------------------------------------------------\n");
        /*for(int i = 0; i< tam; i++){
            if(lista[i].isEmpty == 0 && lista[i].sexo == 'f'){
                mostrarPersona(lista[i]);
                flag = 0;
            }
        }*/
        for(int i = 0; i< len; i++){
            if(list[i].isEmpty == 0){
                salarioTotal += list[i].salary;
                contadorEmpleados++;
            }
        }
        printf("- Salario total %f \n" , salarioTotal);
        promedioSalario = (float) salarioTotal / contadorEmpleados;
        printf("- Promedio de salario %f \n" , promedioSalario);
        printf("\n\n");
        printf("Empleados que superan el salario promedio: \n");
        for(int i = 0; i< len; i++){
            if(list[i].isEmpty == 0 && list[i].salary > promedioSalario){
                printEmployee(list[i]);
                flag = 0;
            }
        }
        if(flag){
            printf("Ninguna persona supera el salario promedio\n");
        }
        //system("pause");
        todoOk = 0;
    }
    return todoOk;

}

int modificarEmployee(eEmployee list[], int len){
    int todoOk = -1;
    int indice;
    int id;
    char confirma;
    char auxNombre[51];
    char auxlastName[51];
    float auxSalary;
    int auxSector;

    if(list != NULL && len > 0)
    {
        system("cls");
        printf("        *** Modificar Empleado *** \n\n");
        printf("Ingrese id: ");
        scanf("%d" , &id);
        indice = findEmployeeById(list, len, id);
        if (indice == -1){
            printf("El ID %d no se encuentra en el sistema \n" , id);
        }
        else
        {
            printEmployee(list[indice]);

            printf("Confirma modificacion?: ");
            setbuf(stdin, NULL);
            scanf("%c" , &confirma);
            if(confirma == 's'){
                switch(menuModificacion()){
                case 1:
                    pedirCadena("Ingrese nuevo nombre: \n" , auxNombre);
                    strcpy(list[indice].name, auxNombre);


                    break;
                case 2:
                    pedirCadena("Ingrese nuevo apellido: \n" , auxlastName);
                    strcpy(list[indice].lastName, auxlastName);
                    break;
                case 3:
                    auxSalary = getFloat("\n Ingrese el salario nuevo:");
                    list[indice].salary = auxSalary;
                    break;
                case 4:
                    auxSector = getInt("\n Ingrese el nuevo sector");
                    list[indice].sector = auxSector;
                    break;
                default:
                    printf("Opcion invalida!");
                }

                todoOk = 0;
            }
            else{
                printf("Modificacion cancelada por el usuario");
            }

        }
        //todoOk = 1;
    }
    return todoOk;
}

int menuModificacion()
{
    int opcion;
    system("cls");
    setbuf(stdin, NULL);
    printf("1 - Nombre \n");
    printf("2 - Apellido \n");
    printf("3 - Salario \n");
    printf("4 - Sector \n");
    printf("5 - Salir \n");
    printf("Ingrese opcion: ");
    scanf("%d", &opcion);
    return opcion;
}
