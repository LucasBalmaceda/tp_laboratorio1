#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * \brief Solicita
 * \
 * \return
 */
int calculadora(void);
int sumar(int *pResultado, int numero1, int numero2);
int restar(int *pResultado,int numero1, int numero2);
float division(float *pResultado,int numero1, int numero2);
int multiplicacion(int *pResultado,int numero1, int numero2);
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

