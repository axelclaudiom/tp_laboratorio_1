#ifndef MELGARTP1_H_INCLUDED
#define MELGARTP1_H_INCLUDED



#endif // MELGARTP1_H_INCLUDED

/** \brief La Funcion pide al usuario un numero entero y lo retorna
 *
 * \param void
 * \return int Retorna el numero entero ingresado por el usuario
 *
 */
int ingOperandoUno(void);


/** \brief La Funcion pide al usuario un numero entero y lo retorna
 *
 * \param void
 * \return int Retorna el numero entero ingresado por el usuario
 *
 */
int ingOperandoDos(void);


/** \brief La funcion recopila los datos necesarios para llamar a las demas funciones, las llama, devuelve los resultados invocando a la funcion mostrar() y devuelve como resultado una bandera indicando que todas las operaciones salieron exitosas (1) o no (0).
 *
 * \param a int Es el operando ingresado por el usuario
 * \param b int Es el operando ingresado por el usuario
 * \param gatillo int Este gatillo lo uso para indicarle a la funcion mostrar si me tiene que printear los resultados (1) o no (0).
 * \return int retorna 0 (Si salio mal) o 1 (si todo esta ok)
 *
 */
int calcularOperaciones(int a, int b, int gatillo);

/** \brief La funcion se encarga de sumar los dos operandos y de dar el resultado por medio del puntero *c
 *
 * \param a int Operando 1 ingresado por el usuario
 * \param b int Operando 2 ingresado por el usuario
 * \param c int* Puntero de resultado
 * \return int Retorna 0 si la operacion salio mal o 1 si la operacion salio bien.
 *
 */
int sumar(int a, int b, int* c);

/** \brief La funcion se encarga de restar los dos operandos y de dar el resultado por medio del puntero *c
 *
 * \param a int Operando 1 ingresado por el usuario
 * \param b int Operando 2 Ingresado por el usuario
 * \param c int* Puntero de resultado
 * \return int Retorna 0 si la operacion salio mal o 1 si la operacion salio bien
 *
 */
int resta(int a, int b, int* c);

/** \brief La funcion se encarga de dividir los dos operandos y de dar el resultado por medio del puntero *pCociente, a su vez si el divisor es igual a 0 activa una bandera llamada flagDiv = 1 para indicar que hay un error
 *
 * \param dividendo int Operando 1 ingresado por el usuario
 * \param divisor int Operando 2 ingresado por el usuario
 * \param pCociente float* Puntero de resultado
 * \return int Retorna 0 si la operacion salio mal o 1 si la operacion salio bien
 *
 */
int dividir(int dividendo, int divisor, float * pCociente);

/** \brief La funcion se encarga de multiplicar los dos operandos y dar el resultado por medio del puntero *c
 *
 * \param a int Operando 1 ingresado por el usuario
 * \param b int Operando 2 Ingresado por el usuario
 * \param c int* Puntero de resultado
 * \return int Retorna 0 si la operacion salio mal o 1 si la operacion salio bien
 *
 */
int multiplicar(int a, int b, int* c);


/** \brief La funcion se encarga de dar el numero factorial de un numero ingresado y devolver el resultado por medio del puntero *c
 *
 * \param a int Numero ingresado por el usuario
 * \param c int* Puntero de resultado
 * \return int Retorna 0 si la operacion salio mal o 1 si la operacion salio bien
 *
 */
int factorialRec(int a, int* c);

/** \brief La funcion se encarga de mostrar el resultado de las operaciones
 *
 * \param num1 int Operando 1 ingresado por el usuario
 * \param num2 int Operando 2 ingresado por el usuario
 * \param pResSuma int Resultado de la funcion sumar
 * \param pResResta int Resultado de la funcion Restar
 * \param pResDiv float Resultado de la funcion Dividir
 * \param pResMulti int Resultado de la funcion multiplicar
 * \param pResAFact int Resultado del factorial del operando A
 * \param pResBFact int Resultado del factorial del operando B
 * \param flagDiv int Bandera de la funcion Dividir si es igual a 1 indica que el divisor es igual a 0
 * \param flagCalculos int Bandera de la funcion calcularOperaciones es para hacer la validacion de que antes se hicieron los calculos
 * \return int Retorna 0 si la operacion salio mal o 1 si la operacion salio bien
 *
 */
int mostrar(int num1, int num2, int pResSuma, int pResResta, float pResDiv, int pResMulti, int pResAFact, int pResBFact, int flagDiv, int flagCalculos);

