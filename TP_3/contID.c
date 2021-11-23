#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "contID.h"

int buscarMayorId(LinkedList* pArrayListEmployee, int* pId)
{
    int todoOk = 0;
    Employee* auxEmp = NULL;
    int mayor;

    if(pArrayListEmployee != NULL)
    {
        for(int i=0; i< ll_len(pArrayListEmployee); i++)
        {
            auxEmp = (Employee*)ll_get(pArrayListEmployee, i);
            if(i==0 || auxEmp->id > mayor)
            {
                mayor = auxEmp->id;
            }
        }
        *pId = mayor+1;
        todoOk = 1;
    }
    return todoOk;
}


int guardarId(int id)
{
    int todoOk = 0;
    FILE* pFile;
    pFile = fopen("uID.txt","w");

    if(pFile!=NULL)
    {
        fprintf(pFile,"%d\n",id);
        fclose(pFile);
        todoOk = 1;
    }
    return todoOk;
}


int obtenerId(int* id)
{
    int todoOk = 0;
    *id = 1;
    int newID;
    FILE* pFile;
    pFile = fopen("uID.txt","r");

    if(pFile!=NULL)
    {
        fscanf(pFile, "%d\n", &newID);
        *id = newID;
        fclose(pFile);
        todoOk = 1;
    }
    return todoOk;
}


int actualizarId(int id)
{
    int nextID = id++;
    int todoOk = 0;
    FILE* pFile;
    pFile = fopen("uID.txt","w");

    if(pFile!=NULL)
    {
        fprintf(pFile,"%d\n",nextID);
        fclose(pFile);
        todoOk = 1;
    }
    return todoOk;
}


int buscarEmpleadoPorId(LinkedList* pArrayListEmployee, int id)
{
    int todoOk = -1;
    int auxId;
    int len;
    Employee* pEmployee;

    if (pArrayListEmployee != NULL && id > 0)
    {
        len = ll_len(pArrayListEmployee);
        for (int i = 0; i < len; i++)
        {
            pEmployee = (Employee*)ll_get(pArrayListEmployee,i);
            if (pEmployee != NULL && employee_getId(pEmployee, &auxId) == 1 && auxId == id)
            {
                todoOk = i;
                break;
            }
        }
    }
    return todoOk;
}
