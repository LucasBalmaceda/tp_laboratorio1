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


int initEmployees(Employee *list, int len);
int addEmployee(Employee *list, int idCounter, int len, int id, char name[], char lastName[], float salary, int sector);
int removeEmployee(Employee *list, int len, int id);
int modifyEmployee(Employee *list, int len);
int findEmployeeById(Employee *list, int *pResult, int len, int id);
int findEmptyPosition(Employee *list, int *position, int len);
int sortEmployees(Employee *list, int len);
int printEmployees(Employee *list, int len);
int salaryReport(Employee* list,int len);
int existingEmployee(Employee *list, int len);
