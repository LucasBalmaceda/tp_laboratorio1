/*
 * ArrayEmployees.c
 *
 *  Created on: 12 oct. 2021
 *      Author: lucas
 */

#include "ArrayEmployees.h"
#include "input.h"

int initEmployees(Employee* list, int len)
{
	int retorno;
	int i;
	if(list != NULL)
	{
		for(i=0;i<=len;i++)
		{
			list[len].isEmpty = 1;
		}
		retorno=0;
	}
	return retorno;
}

int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int retorno;
	retorno=-1;
	if(list != NULL && len >= 0 && id < 0 && name != NULL && lastName != NULL && salary > 0 && sector > 00)
	{
		list[id].id = id;
		list[id].salary = salary;
		list[id].sector = sector;
		strcpy(list[id].name, name);
		strcpy(list[id].lastName, lastName);
		list[id].isEmpty = 0;
		retorno = 0;
	}
	return retorno;
}

int findEmployeeById(Employee *list, int len, int id, int *pBufferId)
{
	int retorno;
	int i;
	retorno = -1;
	if(list!=NULL && len > 0 && id > 0)
	{
		for(i=0;i<=len;i++)
		{
			if(id==list[i].id)
			{
				*pBufferId = i;
				retorno = 0;
			}
		}
	}
	return retorno;
}

int removeEmployee(Employee *list, int len, int id)
{
	int retorno;
	int bufferId;
	retorno = -1;
	if(list != NULL && len > 0 && id > 0)
	{
		if(findEmployeeById(list, len, id, &bufferId) == 0)
		{
			strcpy(list[bufferId].name, "");
			strcpy(list[bufferId].lastName, "");
			list[bufferId].id = 0;
			list[bufferId].salary = 0;
			list[bufferId].sector = 0;
			retorno = 0;
		}
		else
		{
			printf("No se encontro el id ingresado.");
		}
	}
	return retorno;
}

int sortEmployee(Employee *list, int len, int order)
{
	int retorno;
	int i;
	int j;
	Employee aux;
	retorno = -1;
	if(list != NULL && len > 0 && order > 0)
	{
		switch(order)
		{
		case 1:
			for(i=0;i<len-1;i++)
			{
				for(j=i+1;j<len;j++)
				{
					if(strcmp(list[j].lastName, list[i].lastName) < 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector < list[i].sector)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
			retorno = 0;
			break;
		case 2:
			for(i=0;i<len-1;i++)
			{
				for(j=i+1;j<len;j++)
				{
					if(strcmp(list[j].lastName, list[i].lastName) > 0)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
					if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector > list[i].sector)
					{
						aux = list[i];
						list[i] = list[j];
						list[j] = aux;
					}
				}
			}
			retorno = 0;
			break;
		}
	}
	return retorno;
}

int loadEmployee(Employee *list, int len, int *pIdCont)
{
	int retorno;
	int position;
	int auxId;
	char auxName[51];
	char auxLastName[51];
	float auxSalary;
	int auxSector;
	retorno = -1;
	if(list != NULL && len>0)
	{
		if(findEmpty(list, len, &position) == -1)
		{
			printf("\nSe acabaron los lugares para recibir altas.\n");
		}
		else
		{
			(*pIdCont)++;
			auxId = *pIdCont;
			obtenerNombre(auxName, "\nEnter name: ", "\nError", 1, 51, 3);
			obtenerNombre(auxLastName, "\nEnter last name: ", "\nError", 1, 51, 3);
			obtenerNumeroFlotante(&auxSalary, "\nEnter salary: ", "\nError", 1, 300000, 1, 250000, 3);
			obtenerNumeroEntero(&auxSector, "\nEnter sector: ", "\nError", 1,sizeof(int), 1, 10, 3);
			addEmployee(list, len, auxId, auxName, auxLastName, auxSalary, auxSector);
		}
	}

	return retorno;
}

int findEmpty(Employee *list, int len, int *pPosition)
{
	   int retorno=-1;
	    int i;
	    if(list != NULL && len >= 0 && pPosition != NULL)
	    {
	        for(i=0;i<len;i++)
	        {
	            if(list[i].isEmpty==1)
	            {
	                retorno=0;
	                *pPosition=i;
	                break;
	            }
	        }
	    }
	    return retorno;
}

int modifyEmployee(Employee *list, int len, int reintentos)
{
	int retorno;
	int id;
	int position;
	char option;
	retorno = -1;
	if(list != NULL && len > 0)
	{
		obtenerNumeroEntero(&id, "\nIngrese el ID del empleado que desea modificar", "\nError, ese ID no se encuentra en el sistema.", 1, sizeof(int), 1, len, 3);
		if(findEmployeeById(list, len, id, &position) == 0)
		{
			do
			{
				obtenerCaracter(&option, "\n---MODIFICAR---\n\na).Modificar nombre.\nb).Modificar apellido\nc)Modificar salario.\nd)Modificar sector.\ne)Atras.", "Error, esa opcion no existe.", 'a', 'z', 1);
				switch(option)
				{
				case 'a':
					obtenerNombre(list[position].name, "\nIngrese el nuevo nombre: ", "\nError, ese no es un nombre valido.", 1, 51, 3);
					break;
				case 'b':
					obtenerNombre(list[position].lastName, "\nIngrese el nuevo apellido: ", "\nError, ese no es un apellido valido.", 1, 51, 3);
					break;
				case 'c':
					obtenerNumeroFlotante(&list[position].salary, "\nIngrese el nuevo salario: ", "\nError, ese no es un parametro valido.", 1, 300000, 1, 250000, 3);
					break;
				case 'd':
					obtenerNumeroEntero(&list[position].sector, "\nIngrese el nuevo sector", "\nError, ese no es un parametro valido", 1, sizeof(int), 1, 10, 3);
					break;
				default:
					printf("\nEsa no es una opcion vaida, ingrese otra.");
				}
			}while(option!='E');
			retorno = 0;
		}
		else
		{
			printf("\nNo existe ningun empleado con ese id.");
		}
	}
	return retorno;
}

int printEmployees(Employee *list, int len)
{
	int retorno;
	int i;
	retorno = -1;
	if(list != NULL && len >= 0)
	{
		printf("\n----------ID\tApellido\t\t\tNombre\t\tSalario\t\tSector----------\n");
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 1)
			{
				continue;
			}
			else
			{
				printf("\n%d\t%s\t\t\t%s\t\t%.2f\t\t%d",list[i].id, list[i].lastName, list[i].name, list[i].salary, list[i].sector);
			}
		}
		retorno=0;
	}
	return retorno;
}

int salary(Employee *list, int len)
{
	int retorno;
	int i;
	int accountant;
	float accumulator;
	float total;
	int averageHigherSalary;
	retorno = -1;
	accountant = 0;
	accumulator = 0;
	total = 0;
	averageHigherSalary = 0;
	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				accountant ++;
				accumulator = accumulator + list[i].salary;
			}
		}
		total = accumulator / accountant;
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0 && list[i].salary > total)
			{
				averageHigherSalary++;
			}
		}
		printf("\n-Salario total: %.2f-", accumulator);
		printf("\n-Salario promedio: %.2f-", total);
		printf("\n-Cantidad de empleados que superan el salario promedio: %d-\n", averageHigherSalary);
		retorno = 0;
	}
	return retorno;
}

int report(Employee *list, int len)
{
	int retorno;
	int option;
	int order;
	retorno = -1;
	if(list != NULL && len > 0)
	{
		do
		{
			obtenerNumeroEntero(&option, "\n_1)Lista de empleados.\n_2)Salarios.\n_3)Atras.", "\nError, esa no es una opcion valida.", 1, sizeof(int), 1, 5, 3);
			switch(option)
			{
			case 1:
				obtenerNumeroEntero(&order, "\nOrdenar por apellido.\n-1)Ascendente.\n-2)Descendente\nIngrese una opcion: ", "Error, esa no es una opcion valida.", 1, sizeof(int), 1, 2, 3);
				sortEmployee(list, len, order);
				printEmployees(list, len);
				break;
			case 2:
				salary(list, len);
				break;
			default:
				printf("\nEsa no es una opcion valida.");
			}
		}while(option != 3);
		retorno = 0;
	}
	return retorno;
}

int existEmployee(Employee *list, int len)
{
	int retorno = -1;
	int i;
	if(list != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == 0)
			{
				retorno = 0;
			}
		}
	}
	return retorno;
}
