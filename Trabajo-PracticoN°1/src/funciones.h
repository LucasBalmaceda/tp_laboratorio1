#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * \brief Se encarga de hacer el llamado a todas las funciones del programa y mantener limpio el main al ser la unica funcion llamada desde nuestro main
 * \return Siempre retorna 0 ya que no valida si sale bien
 */
int calculadora(void);
/*
 * \brieg Solicita dos numeros, se encarga de realizar la suma y devuelve el resultado mediante un parametro
 * \param pResultado Puntero en donde guardaremos el valor de la suma
 * \param numero1 aqui hacemos referencia al primer operando de la suma ingresado por el usuario
 * \param numero2 aqui hacemos referencia al segundo operando de la suma ingresado por el usuario
 * \return en cado de exito (0), en caso de error (-1)
 */
int sumar(int *pResultado, int numero1, int numero2);
/*
 * \brieg Solicita dos numeros, se encarga de realizar la resta devolviendo el resultado por parametro
 * \param pResultado Puntero en donde guardaremos el valor de la resta
 * \param numero1 aqui hacemos referencia al primer operando de la resta ingresado por el usuario
 * \param numero2 aqui hacemos referencia al segundo operando de la resta ingresado por el usuario
 * \return en cado de exito (0), en caso de error (-1)
 */
int restar(int *pResultado,int numero1, int numero2);
/*
 * \brieg Solicita dos numeros, se encarga de realizar la division entre ambos operandos devolviendo el resultado por parametro
 * \param pResultado Puntero en donde guardaremos el valor de la division
 * \param numero1 aqui hacemos referencia al primer operando de la division ingresado por el usuario
 * \param numero2 aqui hacemos referencia al segundo operando de la division ingresado por el usuario
 * \return en cado de exito (0), en caso de error (-1)
 */
float division(float *pResultado,int numero1, int numero2);
/*
 * \brieg Solicita dos numeros, se encarga de realizar la multiplicacion y devuelve el resultado de estos mismos por parametro
 * \param pResultado Puntero en donde guardaremos el valor de la multiplicacion
 * \param numero1 aqui hacemos referencia al primer operando ingresado por el usuario
 * \param numero2 aqui hacemos referencia al segundo operando de la multiplicacion ingresado por el usuario
 * \return en cado de exito (0), en caso de error (-1)
 */
int multiplicacion(int *pResultado,int numero1, int numero2);
/*
 * \brieg Solicita dos numeros, se encarga de realizar el factorial de cada numero y devuelve el resultado de estos mismos por separado mediante dos parametros
 * \param pResultado1 Puntero en donde guardaremos el primer valor del factorial del operando numero2
 * \param pResultado2 Puntero en donde guardaremos el segundo valor del factorial del operando numero2
 * \param numero1 aqui hacemos referencia al primer operando ingresado por el usuario
 * \param numero2 aqui hacemos referencia al segundo operando del factorial ingresado por el usuario
 * \return en cado de exito (0), en caso de error (-1)
 */
int factorial(int *pResultado,int *pResultado2,int numero1, int numero2);
/**
 * \brief Solicita un entero al usuario, lo valida, verifica y devuelve el resultado
 * \param pResultado Puntero al resultado alli se dejara el entero ingresado por el usuario
 * \param mensaje Es el mensaje a ser mostrado
 * \param mensajeError Es el mensaje a ser mostrado en caso de error
 * \param minimo Valor minimo aceptado
 * \param maximo Valor maximo aceptado
 * \param reintentos Cantidad de reintentos en el caso de error
 * \return En caso de exito (0), en caso de error (-1)
 */
int utn_getNumero(int* pResultado,char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);

