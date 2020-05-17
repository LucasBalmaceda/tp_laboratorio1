#include "utn.h"

#include "arrayEmployee.h"
#include "reports.h"


int utn_getString(char* pResult, char* msg, char* msgError, int min, int max, int* retries)
{
	int ret=-1;
	char bufferStr[max+10];

	if(msg!=NULL && msgError!=NULL && min<=max && retries>=0 && pResult!=NULL)
	{
		do
		{
			printf("%s",msg);   //no poner salto de linea, se va a pasar en el mensaje por valor
			//fflush(stdin);
			fgets(bufferStr,sizeof(bufferStr),stdin);
			bufferStr[strlen(bufferStr)-1]='\0';

			if(strlen(bufferStr)>=min && strlen(bufferStr)<max)    // tamaño (max) =cantidad de elementos (strlen) + 1(\0)
			{
				strncpy(pResult,bufferStr,max);
				ret=0;
				break;
			}
			printf("%s 1",msgError);
			(*retries)--;
		}
		while((*retries)>=0);
	}

	return ret;
}

//---------------------------------------------------------------------------------------------------------------------------//

int utn_getUnsignedInt(int* pResult, char* msg, char* msgError, int minSize, int maxSize, int min, int max, int retries)
{
	int ret = -1;
	char bufferStr[maxSize];

	if(msg!=NULL && msgError!=NULL && minSize<maxSize && min<max && retries>=0 && pResult!=NULL)
	{
		do
		{
			if(!utn_getString(bufferStr,msg,msgError,minSize,maxSize,&retries)) //==0 sin errores !0
			{
				if(isValidNumber(bufferStr)==1)
				{
					*pResult=atoi(bufferStr);     // unsigned long int strtoul(const char *str, char **end, int base)?
					ret=0;
					break;
				}
				else
				{
					printf("%s 2",msgError);
					ret--;
				}
			}
		}while(ret>=0);
	}

	return ret;
}

int isValidNumber(char* stringReceived)
{
	int retorno=1;  // para las funciones isValid arranco con verdadero y cambio cuando encuentro un error
	int i;
	if(stringReceived!=NULL)
	{
		for(i=0;stringReceived[i]!='\0';i++)
		{
			if(stringReceived[i]<'0' || stringReceived[i]>'9')
			{
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

//---------------------------------------------------------------------------------------------------------------------------//

int utn_getSingedInt(int *pResult,char *msg,char *msgError,int minSize,int maxSize,int min,int max,int retries)
{
	int ret=-1;
	char bufferStr[maxSize];

	if(pResult!=NULL && msg!=NULL && msgError!=NULL && minSize<=maxSize && min<=maxSize && retries>0)
	{
		do
		{
			if(!utn_getString(bufferStr,msg,msgError,minSize,maxSize,&retries))
			{
				if(isValidSingedInt(bufferStr)==1)
				{
					*pResult = atoi(bufferStr);
					ret=0;
					break;
				}
				else
				{
					printf("%s 2",msgError);
					ret--;

				}
			}
		}while(retries>=0);
	}

	return ret;
}

int isValidSingedInt(char *stringReceived)
{
	int ret=-1;
	int i;

	if(stringReceived!=NULL)
	{
		for(i=0;stringReceived[i]!='\0';i++)
		{
			if((stringReceived[i]<'0' || stringReceived[i]>'9') && (stringReceived[0]!='+' && stringReceived[0]!='-'))
			{
				ret=0;
				break;
			}
		}
	}

	return ret;
}

//---------------------------------------------------------------------------------------------------------------------------//

int utn_getFloat(float *pResult, char *msg, char *msgError,int minSize, int maxSize, int min, int max, int retries)
{
	int ret=-1;
	char bufferStr[maxSize];

	if(pResult!=NULL && msg!=NULL && msgError!=NULL && minSize<maxSize && min<max && retries>=0)
	{
		do
		{
			if(!utn_getString(bufferStr,msg,msgError,minSize,maxSize,&retries))
			{
				if(isValidFloat(bufferStr))
				{
					*pResult=atof(bufferStr);
					ret = 0;
					break;
				}
				else
				{
					printf("%s 2",msgError);
					retries--;
				}
			}
		}while(retries>=0);
	}

	return ret;
}

int isValidFloat(char *stringReceived)
{
	int ret=-1;
	int i;
	if(stringReceived!=NULL)
	{
		for(i=0;stringReceived[i]!='\0';i++)
		{
			if((stringReceived[i]<'0' || stringReceived[i]>'9') && (stringReceived[i]!='.'))
			{
				ret = 0;
				break;
			}
		}
	}

	return ret;
}

//---------------------------------------------------------------------------------------------------------------------------//

int utn_getChar(char *pResult, char* msg, char* msgError, int min, int max, int retries)
{
	int ret=-1;
	char bufferChar[50];

	if(pResult!=NULL && msg!=NULL && msgError!=NULL && min<max && retries>=0)
	{
		do
		{
			if(!utn_getString(bufferChar,msg,msgError,1,3,&retries)) //==0
			{
				if(isValidChar(bufferChar[0])==1)
				{
					*pResult=bufferChar[0];
					ret=0;
					break;
				}
				else
				{
					printf("%s",msgError);
					retries--;
				}
			}
		}while(retries>=0);
	}

	return ret;
}

int isValidChar(char stringReceived)
{
	int ret=-1;

	if(stringReceived<'A' || (stringReceived>'Z' && stringReceived<'a') || stringReceived>'z')
	{
		ret=0;
	}

	return ret;
}

//---------------------------------------------------------------------------------------------------------------------------//

int utn_getText(char *pResult, char *msg, char *msgError, int minSize, int maxSize, int retries)
{
	int ret=-1;
	char bufferStr[maxSize];

	if(pResult!=NULL && msg!=NULL && msgError!=NULL && minSize<maxSize && retries>=0)
	{
		do
		{
			if(!utn_getString(bufferStr,msg,msgError,minSize,maxSize,&retries)) //==0 sin errores !0
			{
				if(isValidText(bufferStr)==1)
				{
					strncpy(pResult,bufferStr,maxSize);
					ret=0;
					break;
				}
				else
				{
					printf("%s",msgError);
					retries--;
				}
			}
		}while(retries>=0);
	}

	return ret;
}

int isValidText(char *stringReceived)
{
	int ret=-1;
	int i;

	if(stringReceived!=NULL)
	{
		for(i=0;stringReceived[i]!='\0';i++)
		{
			if(stringReceived[i]<' ' || stringReceived[i]>'z')
			{
				ret=0;
				break;
			}
		}
	}

	return ret;
}

//---------------------------------------------------------------------------------------------------------------------------//
int imprimirArrayInt(int *pArray,int size)
{
	int i;
	int ret =-1;
	if(pArray != NULL && size >= 0)
	{
		for(i=0;i<size;i++)
		{
			printf("El indice de [%d] tiene como valor: %d\n",i , pArray[i]);
			ret =0;
		}
	}

	return ret;
}

int ordenarArray(int *pArray, int size)
{
	int ret = -1;
	int i;
	int flagSwap;
	int buffer;

	if(pArray != NULL && size >= 0)
	{
		do
		{
			flagSwap = 0;
			for(i=0 ; i<size-1 ; i++)
			{
				if(pArray[i] < pArray[i+1])
				{
					flagSwap = 1;
					buffer = pArray[i];
					pArray[i] = pArray[i+1];
					pArray[i+1] = buffer;
				}
			}
			size--;
		}while(flagSwap);
		ret = 0;
	}

	return ret;
}
