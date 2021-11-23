#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    Employee *pEmployee;
	char auxId[50];
	char auxNombre[200];
	char auxHTrab[50];
	char auxSueldo[50];
	int todoOk = 0;

	if (pFile != NULL && pArrayListEmployee != NULL)
        {
            fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", auxId, auxNombre, auxHTrab,auxSueldo); // lectura cabecera
            do
            {
                fscanf(pFile, "%[^,], %[^,], %[^,], %[^\n]\n", auxId, auxNombre, auxHTrab,auxSueldo);
                pEmployee = employee_newParametros(auxId, auxNombre, auxHTrab,auxSueldo);

                if (pEmployee != NULL)
                    {
                        ll_add(pArrayListEmployee, pEmployee);
                        todoOk = 1;
                    }
            }while(!feof(pFile));
        }

    return todoOk;
}


/** \brief Parsea los datos los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk = 0;
    Employee* pEmployee;

    if (pFile != NULL && pArrayListEmployee != NULL)
    {
            do
            {
                pEmployee = employee_new();

                if (pEmployee != NULL && fread(pEmployee,sizeof(Employee),1,pFile)==1)
                    {
                        ll_add(pArrayListEmployee, pEmployee);
                        todoOk = 1;
                    }
                else {
                        employee_delete(pEmployee);
                        break;
                    }
            } while (!feof(pFile));

            todoOk = 1;
        }

    return todoOk;
}

int parser_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	int tam;
	Employee* pEmployee;

	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		tam = ll_len(pArrayListEmployee);

		for (int i = 0; i < tam; i++)
		{
			pEmployee = (Employee*)ll_get(pArrayListEmployee, i);

			if (pEmployee != NULL)
			{
				fwrite(pEmployee, sizeof(Employee), 1, pFile);
			}
		}
		todoOk = 1;
	}
	return todoOk;
}

int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int todoOk = 0;
	Employee *pEmployee;
    char nombre[200];
    int Id;
    int horas;
    int sueldo;
	int tam;


	if (pFile != NULL && pArrayListEmployee != NULL)
	{
		tam = ll_len(pArrayListEmployee);
		fprintf(pFile, "ID,NOMBRE,HORAS TRABAJADAS,SUELDO\n");

		for (int i = 0; i < tam; i++)
		{
			pEmployee = (Employee*)ll_get(pArrayListEmployee, i);
			if (pEmployee != NULL &&
				employee_getId(pEmployee, &Id) &&
				employee_getNombre(pEmployee, nombre) &&
				employee_getSueldo(pEmployee, &sueldo) &&
				employee_getHorasTrabajadas(pEmployee, &horas))
			{
				fprintf(pFile, "%d,%s,%d,%d\n", Id, nombre, horas, sueldo);
			}
		}
		todoOk = 1;
	}
	return todoOk;
}
