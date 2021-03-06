#include "funciones.h"

int calculadora(void)
{
	int opcion;
	int num1=0;
	int num2=0;
	int resultadoSuma;
	int resultadoResta;
	float resultadoDivision;
	int resultadoMultiplicacion;
	int resultadoFactorial1;
	int resultadoFactorial2;
	int flag=0;

	do
	{
		printf("\nIngrese una opcion: \n1-Ingresar numero entero 1.\n2-Ingresar numero entero 2.\n3-Hacer Suma, Resta, Multiplicacion, Division, Factorial.\n4-Mostrar resultados.\n5-Finalizar programa\n");
		scanf("%d",&opcion);
		if(opcion>=1 && opcion<=5)
		{
			switch(opcion)
			{
			case 1:
				utn_getNumero(&num1,"\nIngrese un numero: ","Error, ese numero no esta entre los parametros. Intentelo de nuevo: ",0,9999,3);
				break;
			case 2:
				utn_getNumero(&num2,"\nIngrese un numero: ","Error, ese numero no esta entre los parametros. Intentelo de nuevo: ",0,9999,3);
				break;
			case 3:
				sumar(&resultadoSuma,num1,num2);
				restar(&resultadoResta,num1,num2);
				division(&resultadoDivision,num1,num2);
				multiplicacion(&resultadoMultiplicacion,num1,num2);
				factorial(&resultadoFactorial1,&resultadoFactorial2,num1,num2);
				flag=1;
				break;
			case 4:
				if(flag == 1)
				{
					printf("\nEl resultado de la suma entre %d y %d es: %d.\nEl resultado de la resta entre %d y %d es: %d.\nEl resultado de la division entre %d y %d es: %f.2.\nEl resultado de la multiplicacion entre %d y %d es: %d.\nEl factorial de %d es: %d.\nEl factorial de %d es: %d.\n\n",num1,num2,resultadoSuma,num1,num2,resultadoResta,num1,num2,resultadoDivision,num1,num2,resultadoMultiplicacion,num1,resultadoFactorial1,num2,resultadoFactorial2);
				}
				else
				{
					printf("\nPrimero ingrese numeros y realice la cuenta.\n");
				}
				break;
			case 5:

				break;
			}
		}
		else
		{
			printf("Error, esa no es una opcion valida, intentelo de nuevo");
		}
	}while(opcion != 5);

	return 0;
}

int sumar(int *pResultado, int numero1, int numero2)
{
	int ret=-1;
	int buffer;

	if(pResultado != NULL)
	{
		buffer = numero1 + numero2;
		*pResultado = buffer;
		ret = 0;
	}
	return ret;
}

int restar(int *pResultado,int numero1, int numero2)
{
	int ret=-1;
	int buffer;

	if(pResultado != NULL)
	{
		buffer = numero1 - numero2;
		*pResultado = buffer;
		ret=0;
	}
	return ret;
}

float division(float *pResultado,int numero1, int numero2)
{
	int ret = -1;
	float buffer;

	if(pResultado != NULL)
	{
		if(numero1!=0 && numero2!=0)
		{
			buffer = numero1/numero2;
			*pResultado = buffer;
			ret = 0;
		}
		else
		{
			printf("\nNo se puede dividir por cero, intentelo de nuevo.");
		}
	}

	return ret;
}

int multiplicacion(int *pResultado,int numero1, int numero2)
{
	int ret=-1;
	int buffer;

	if(pResultado != NULL)
	{
		buffer = numero1*numero2;
		*pResultado = buffer;
		ret=0;
	}

	return ret;
}

int factorial(int *pResultado1,int *pResultado2,int numero1, int numero2)
{
	int ret=-1;
	int buffer1=1;
	int buffer2=1;
	int i1;
	int i2;

	if(pResultado1 != NULL && pResultado2 != NULL)
	{
		for(i1=1;i1<=numero1;i1++)
		{
			buffer1=buffer1*i1;
		}
		for(i2=1;i2<=numero2;i2++)
		{
			buffer2=buffer2*i2;
		}
		*pResultado1=buffer1;
		*pResultado2=buffer2;
	}

	return ret;
}

int utn_getNumero(int* pResultado,char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int ret = -1;
	int num;
	if(mensaje != NULL && mensajeError != NULL)
	{
		while(reintentos>0)
		{
			printf(mensaje);
			scanf("%d",&num);
			if(num<=maximo && num>=minimo)
			{break;}
			reintentos--;
			printf(mensajeError);
		}
		if(reintentos==0)
		{
			ret=-1;
		}
		else
		{
			ret=0;
			*pResultado = num;
		}
	}
	return ret;
}
