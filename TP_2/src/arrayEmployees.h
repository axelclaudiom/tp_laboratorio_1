#ifndef ARRAYEMPLOYEES_H_INCLUDED
#include "ctype.h"
#include "string.h"
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty; // 1 esta vacio, 0 esta lleno
} eEmployee;

#endif // ARRAYEMPLOYEES_H_INCLUDED

/** \brief
 *
 * \param list[] eEmployee Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if error [Invalid length or NULL pointer] - (0) if Ok.
 *
 */
int initEmployees(eEmployee* list, int len);


/** \brief Esta funcion busca el primer lugar libre en un array de empleados
 *
 * \param list Employee* Recibe un puntero a un array de empleados
 * \param len int Recibe el largo del array de empleados
 * \return int Devuelve el indice del primer lugar libre dentro del array de empleados o -1 (si no hay lugar disponible, si el largo del array es invalido o si el puntero al array es NULL)
 *
 */
int getIsEmpty(eEmployee list[], int len);

/** \brief add in a existing list of employees the values received as parameters in the first empty position
 *
 * \param list eEmployee* pointer to array of employees
 * \param len int Array Length
 * \param id int id employee
 * \param name[] char name employee
 * \param lastName[] char lastname employee
 * \param salary float salary employee
 * \param sector int sector employee
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int addEmployee(eEmployee* list, int len, int id, char name[],char lastName[],float salary,int sector);

/** \brief funcion auxiliar de carga de empleados hace la toma de datos y llama a la funcion addEmployee
 *
 * \param list[] eEmployee array of employees
 * \param len int Array Length
 * \param pId int* Pointer of Id
 * \return int int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int cargarEmpleado(eEmployee list[], int len, int* pId);

/** \brief muestra informacion de un solo empleado por id
 *
 * \param p eEmployee  eEmployee array of employees
 * \return void
 *
 */
void printEmployee(eEmployee p);

/** \brief print the content of employees array
 *
 * \param list eEmployee* eEmployee array of employees
 * \param len int Array Length
 * \return int (-1) if Error [Invalid length or NULL pointer or employee not found] - (0) if Ok
 *
 */
int printEmployees(eEmployee* list, int len);

/** \brief Menu principal
 *
 * \return int
 *
 */
int menu();

/** \brief find an Employee by id en returns the index position in array.
 *
 * \param list eEmployee* eEmployee array of employees
 * \param len int Array Length
 * \param id int id employee
 * \return int (-1) if Error [Invalid length or NULL pointer or employee not found] - (0) if Ok
 *
 */
int findEmployeeById(eEmployee* list, int len,int id);

/** \brief
 *
 * \param list eEmployee* eEmployee array of employees
 * \param len int Array Length
 * \param id int id employee
 * \return int (-1) if Error [Invalid length or NULL pointer or if can´t find a employee] - (0) if Ok
 *
 */
int removeEmployee(eEmployee* list, int len, int id);

/** \brief Funcion auxiliar Pide informacion al usuario
 *
 * \param list[] eEmployee eEmployee* eEmployee array of employees
 * \param len int int Array Length
 * \return int int (-1) if Error [Invalid length or NULL pointer or if can´t find a employee] - (0) if Ok
 *
 */
int bajaPersona(eEmployee list[], int len);

/** \brief  Order employees by sector and lastName asc o desc
 *
 * \param list eEmployee* eEmployee array of employees
 * \param len int int Array Length
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int (-1) if Error [Invalid length or NULL pointer or if can´t find a employee] - (0) if Ok
 *
 */
int sortEmployees(eEmployee* list, int len, int order);

/** \brief Muestra Total de salarios, promedio y empleados que superan el promedio
 *
 * \param list[] eEmployee array of employees
 * \param len int Array Length
 * \return int (-1) if Error [Invalid length or NULL pointer or if can´t find a employee] - (0) if Ok
 *
 */
int salariosOrden(eEmployee list[], int len);

/** \brief Menu de informes
 *
 * \return int
 *
 */
int menuInformes();

/** \brief funcion encargada de modificar informacion de los empleados
 *
 * \param list[] eEmployee array of employees
 * \param len int Array Length
 * \return int (-1) if Error [Invalid length or NULL pointer or if can´t find a employee] - (0) if Ok
 *
 */
int modificarEmployee(eEmployee list[], int len);

/** \brief Menu de modificacion de empleados
 *
 * \return int
 *
 */
int menuModificacion();
