/*
 ============================================================================
 Name        : tp2.c
 Author      : Balmaceda Lucas
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "input.h"

int main(void)
{
	setbuf(stdout,NULL);
	Employee arrayEmployee[EMPLOYEE];
	initEmployees(arrayEmployee, EMPLOYEE);
	int option;
	int idEmployee;
	int findId;
	idEmployee = 0;
	do
	{
		obtenerNumeroEntero(&option, "-----MENU-----\n\n1)CargarEmpleado.\n2)Modificar empleado\n3)Remover empleado\n4)Informar\n5)Salir", "\nError, esa no es una opcion valida.", 1, sizeof(int), 1, 5, 3);
		switch(option)
		{
		case 1:
			loadEmployee(arrayEmployee, EMPLOYEE, &idEmployee);
			break;
		case 2:
			if(existEmployee(arrayEmployee, EMPLOYEE) == 0)
			{
				printEmployees(arrayEmployee, EMPLOYEE);
				modifyEmployee(arrayEmployee, EMPLOYEE, 3);
			}
			else
			{
				printf("\nPrimero debe ingresar algun empleado.\n");
			}
			break;
		case 3:
			if(existEmployee(arrayEmployee, EMPLOYEE)==0)
			{
				obtenerNumeroEntero(&findId,"\nIngrese el id del empleado que desea eliminar: ", "Error, ese id no existe.", 1, sizeof(int), 1, EMPLOYEE, 3);
				removeEmployee(arrayEmployee, EMPLOYEE, findId);
			}
			else
			{
				printf("\nPrimero debe ingresar algun empleado.\n");
			}
			break;
		case 4:
			if(existEmployee(arrayEmployee, EMPLOYEE) == 0)
			{
				report(arrayEmployee, EMPLOYEE);
			}
			else
			{
				printf("\nPrimero debe ingresar algun empleado.\n");
			}
			break;
		case 5:
			printf("\nGracias por usar el programa de Lucas Balmaceda");
			break;
		}
	}while(option != 5);
	return 0;
}
