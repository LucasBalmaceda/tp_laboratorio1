/*
 * ArrayEmployees.h
 *
 *  Created on: 12 oct. 2021
 *      Author: lucas
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_



#endif /* ARRAYEMPLOYEES_H_ */

#define EMPLOYEE 1000

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}Employee;

/// @fn int initEmployees(Employee*, int)
/// @briefesta funcion recibe la estructura Employee y se crea una variable entera donde
/// introduciremos el tamaño de empleados.
/// @param list variable creada para poder acceder a los datos de la estructura
/// @param len vaariable creada para tener el limite de empleados
/// @return retorna 0 si la funcion pudo ejecutarse e inicializo los isEmpty en TRUE
int initEmployees(Employee* list, int len);

/// @fn int addEmployee(Employee*, int, int, char[], char[], float, int)
/// @brief
///
/// @param list
/// @param len
/// @param id
/// @param name
/// @param lastName
/// @param salary
/// @param sector
/// @return
int addEmployee(Employee* list, int len, int id, char name[], char lastName[], float salary, int sector);

int findEmployeeById(Employee *list, int len, int id, int *pBufferId);

int removeEmployee(Employee *list, int len, int id);

int sortEmployee(Employee *list, int len, int order);

int loadEmployee(Employee *list, int len, int *idCont);

int findEmpty(Employee *list, int len, int *pPosition);

int modifyEmployee(Employee *list, int len, int reintentos);

int printEmployees(Employee *list, int len);

int salary(Employee *list, int len);

int report(Employee *list, int len);

int existEmployee(Employee *list, int len);
