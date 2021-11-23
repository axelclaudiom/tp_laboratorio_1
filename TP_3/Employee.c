#include "Employee.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


Employee* employee_new()
{
    Employee* employee_new;
    employee_new = (Employee*) malloc(sizeof(Employee));

    if (employee_new != NULL)
    {
        employee_new->id = 0;
        strcpy(employee_new->nombre, " ");
        employee_new->horasTrabajadas = 0;
        employee_new->sueldo = 0;
    }

    return employee_new;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* pEmployee;
    int auxSueldo;
    int auxId;
    int auxHoras;


    if (idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
    {
        pEmployee = employee_new();
        auxId = atoi(idStr);
        auxHoras = atoi(horasTrabajadasStr);
        auxSueldo = atof(sueldoStr);

        if ((pEmployee != NULL) &&
                (!(employee_setNombre(pEmployee,nombreStr) &&
                   employee_setHorasTrabajadas(pEmployee,auxHoras) &&
                   employee_setSueldo(pEmployee,auxSueldo) &&
                   employee_setId(pEmployee,auxId))))
        {
            employee_delete(pEmployee);
            pEmployee = NULL;
        }
    }
    return pEmployee;
}

void employee_delete(Employee* this)
{
    if(this != NULL)
    {
        free(this);
    }
}

int employee_setId(Employee* this,int id)
{
    int todoOk = 0;
    if( this != NULL && id >0)
    {
        this->id = id;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if (this != NULL && nombre != NULL)
    {
        strlwr(nombre);
        nombre[0] = toupper(nombre[0]);
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }
    return todoOk;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 0;
    if( this != NULL && horasTrabajadas >= 0)
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOk = 0;
    if( this != NULL && sueldo > 0)
    {
        this->sueldo = sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getId(Employee* this,int* id)
{
    int todoOk = 0;
    if( this != NULL && id!= NULL)
    {
        *id = this->id;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;
    if (this != NULL && nombre != NULL)
    {
        strcpy(nombre, this->nombre);
        todoOk = 1;
    }
    return todoOk;
}


int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 0;
    if( this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }
    return todoOk;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOk = 0;
    if( this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOk = 1;
    }
    return todoOk;
}

int employee_OrderByName(void *nombreUno, void *nombreDos)
{
    char nombre1[128];
    char nombre2[128];
    int todoOk = 0;
    employee_getNombre(nombreUno, nombre1);
    employee_getNombre(nombreDos, nombre2);

    if (strcmp(nombre1, nombre2) > 0)
    {
        todoOk = 1;
    }
    else if (strcmp(nombre1, nombre2) < 0)
    {
        todoOk = -1;
    }
    return todoOk;
}


int employee_OrderByHours(void *horas_Uno, void *horas_Dos)
{
    int HorasUno;
    int HorasDos;
    int todoOk = 0;

    employee_getHorasTrabajadas(horas_Uno, &HorasUno);
    employee_getHorasTrabajadas(horas_Dos, &HorasDos);

    if (HorasUno > HorasDos)
    {
        todoOk = 1;
    }
    else if(HorasUno < HorasDos)
    {
        todoOk = -1;
    }
    return todoOk;
}

int employee_OrderBySueldo(void *sueldo_Uno, void *sueldo_Dos)
{
    int sueldoUno;
    int sueldoDos;
    int todoOk = 0;

    employee_getSueldo(sueldo_Uno, &sueldoUno);
    employee_getSueldo(sueldo_Dos, &sueldoDos);

    if (sueldoUno > sueldoDos)
    {
        todoOk = 1;
    }
    else if (sueldoUno < sueldoDos)
    {
        todoOk = -1;
    }
    return todoOk;
}

int employee_OrderByID(void *id_Uno, void *id_Dos)
{
    int idUno;
    int idDos;
    int todoOk;

    employee_getId(id_Uno, &idUno);
    employee_getId(id_Dos, &idDos);

    if (idUno > idDos)
    {
        todoOk = 1;
    }
    else if (idUno < idDos)
    {
        todoOk = -1;
    }
    return todoOk;
}
