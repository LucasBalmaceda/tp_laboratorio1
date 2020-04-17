#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculadora(void);
int sumar(int *pResultado, int numero1, int numero2);
int restar(int *pResultado,int numero1, int numero2);
int division(int *pResultado,int numero1, int numero2);
int multiplicacion(int *pResultado,int numero1, int numero2);
int factorial(int *pResultado,int *pResultado2,int numero1, int numero2);
int utn_getNumero(int* pResultado,char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
