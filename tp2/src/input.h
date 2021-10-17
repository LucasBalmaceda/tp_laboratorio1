/*
 * main.h
 *
 *  Created on: 6 sep. 2021
 *      Author: lucas
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_



#endif /* FUNCIONES_H_ */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int obtenerString(char *pResultado, char *pMensaje, char *pMensajeError, int minimo, int maximo, int reintentos);

int obtenerNumeroEntero(int *pResultado, char *mensaje, char *mensajeError, int minSize, int maxSize, int minimo, int maximo, int reintentos);
int esNumericoEntero(char *pStringRecibido);

int obtenerNumeroFlotante(float *pResultado, char *mensaje, char *mensajeError, int minSize, int maxSize, int minimo, int maximo, int reintentos);
int esNumericoFlotante(char *pStringRecibido);

int obtenerCaracter(char *pResultado, char *pMensaje, char *pMensajeError, int minimo, int maximo, int reintentos);
int caracterValido(char pCaracter);

int obtenerNombre(char *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos);
int nombreValido(char *pStringRecibido);
