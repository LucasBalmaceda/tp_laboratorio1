#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int utn_getString(char* pResult, char* msg, char* msgError, int min, int max, int* retries);

int utn_getUnsignedInt(int *pResult, char *msg, char *msgError, int minSize, int maxSize, int min, int max, int retries);
int isValidNumber(char* stringReceived);

int utn_getSingedInt(int *pResult,char *mensaje,char *mensajeError,int minSize,int maxSize,int min,int max,int retries);
int isValidSingedInt(char *stringReceived);

int utn_getFloat(float *pResult, char *msg, char *msgError,int minSize, int maxSize, int min, int max, int retries);
int isValidFloat(char *stringReceived);

int utn_getChar(char *pResult, char* msg, char* msgError, int min, int max, int retries);
int isValidChar(char stringReceived);

int utn_getText(char *pResult, char *msg, char *msgError, int minSize, int maxSize, int retries);
int isValidText(char *stringReceived);

int imprimirArrayInt(int pArray[],int size);
int pedirArray(int *pArray, int size);
int ordenarArray(int *pArray, int size);
