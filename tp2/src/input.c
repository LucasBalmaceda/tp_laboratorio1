/*
 * main.c
 *
 *  Created on: 6 sep. 2021
 *      Author: lucas
 */

#include "input.h"

int obtenerString(char *pResultado, char *pMensaje, char *pMensajeError, int minimo, int maximo, int reintentos)
{
	int retorno;
	char bufferString[maximo+10];
	retorno=-1;
	if(pMensaje != NULL && pMensajeError != NULL && minimo <= maximo && reintentos >= 0 && pResultado != NULL)
	{
		do
		{
			printf("%s", pMensaje);   //si ponemos salto de linea se va a mostrar en el mensaje :(
			//fflush(stdin);
			fgets(bufferString, sizeof(bufferString), stdin);
			bufferString[strlen(bufferString)-1]='\0';
			if(strlen(bufferString)>=minimo && strlen(bufferString)<maximo)		// tamaño (max) =cantidad de elementos (strlen) + 1(\0)
			{
				strncpy(pResultado, bufferString,maximo);
				retorno=0;
				break;
			}
			printf("%s", pMensajeError);
			reintentos--;
		}while(reintentos>=0);
	}
	return retorno;
}

int obtenerNumeroEntero(int *pResultado, char *mensaje, char *mensajeError, int minSize, int maxSize, int minimo, int maximo, int reintentos)
{
	int retorno=-1;
	char bufferString[maxSize];
	if(mensaje != NULL && mensajeError != NULL && minSize < maxSize && minimo < maximo && reintentos >= 0 && pResultado != NULL)
	{
		do
		{
			if(!obtenerString(bufferString, mensaje, mensajeError, minSize, maxSize, reintentos))
			{
				if(esNumericoEntero(bufferString) == 1)
				{
					*pResultado=atoi(bufferString);
					retorno=0;
					break;
				}
				else
				{
					printf("%s", mensajeError);
					reintentos--;
				}
			}
		}while(reintentos >= 0);
	}
	return retorno;
}

int esNumericoEntero(char *pStringRecibido)
{
	int retorno;
	int i;
	retorno = -1;
	if(pStringRecibido != NULL)
	{
		for(i=0;pStringRecibido[i]!='\0';i++)
		{
			if(pStringRecibido[i] < '0' || pStringRecibido[i] > '9')
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int obtenerNumeroFlotante(float *pResultado, char *mensaje, char *mensajeError, int minSize, int maxSize, int minimo, int maximo, int reintentos)
{
	int retorno;
	char bufferString[maxSize];
	retorno = -1;
	if(mensaje != NULL && mensajeError != NULL && minSize < maxSize && minimo < maximo && reintentos >= 0 && pResultado != NULL)
	{
		do
		{
			if(!obtenerString(bufferString, mensaje, mensajeError, minSize, maxSize, reintentos))
			{
				if(esNumericoFlotante(bufferString)==1)
				{
					*pResultado=atof(bufferString);
					retorno=0;
					break;
				}
				else
				{
					printf("%s", mensajeError);
					reintentos--;
				}
			}
		}
		while(reintentos>=0);
	}
	return retorno;
}

int esNumericoFlotante(char *pStringRecibido)
{
	int retorno;
	int i;
	retorno = -1;
	if(pStringRecibido != NULL)
	{
		for(i=0;pStringRecibido[i]!='\0';i++)
		{
			if((pStringRecibido[i] < '0' || pStringRecibido[i] > '9') && (pStringRecibido[i] != '.'))
			{
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}

int obtenerCaracter(char *pResultado, char *pMensaje, char *pMensajeError, int minimo, int maximo, int reintentos)
{
	int retorno;
	char bufferChar[50];
	retorno=-1;
	if(pResultado != NULL && pMensaje != NULL && pMensajeError != NULL && minimo<=maximo && reintentos >=0)
	{
		for(;reintentos>=0;reintentos--)
		{
			obtenerString(pResultado, pMensaje, pMensajeError, minimo, maximo, reintentos);
			if(caracterValido(pResultado[0]) == 0)
			{
				*pResultado=bufferChar[0];
				retorno=0;
				break;
			}
			else
			{
				printf("%s", pMensajeError);
			}
		}
	}
	return retorno;
}

int caracterValido(char pCaracter)
{
	int retorno;
	retorno=-1;
	if(pCaracter < 'A' || (pCaracter > 'Z' || pCaracter < 'a') || pCaracter > 'z')
	{
		retorno = 0;
	}
	return retorno;
}

int obtenerNombre(char *pResultado, char *mensaje, char *mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno;
	char bufferString[maximo];
	retorno = -1;
	if(mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0 && pResultado != NULL)
	{
		do
		{
			if(!obtenerString(bufferString, mensaje, mensajeError, minimo, maximo, reintentos))
			{
				if(nombreValido(bufferString) == 1)
				{
					strncpy(pResultado, bufferString, maximo);
					retorno=0;
					break;
				}
				else
				{
					printf("%s",mensajeError);
					reintentos--;
				}
			}
		}
		while(reintentos >= 0);
	}
	return retorno;
}

int nombreValido(char *pStringRecibido)
{
	int retorno;
	int i;
	retorno = -1;
	for(i=0;pStringRecibido[i]!='\0';i++)
	{
		if(pStringRecibido[i]<'A' || (pStringRecibido[i]>'Z' && pStringRecibido[i]<'a') || pStringRecibido[i]>'z')
		{
			retorno=0;
			break;
		}
	}
	return retorno;
}
