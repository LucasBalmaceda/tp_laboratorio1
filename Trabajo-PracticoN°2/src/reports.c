#include "utn.h"

#include "reports.h"
#include "arrayEmployee.h"


int menu()
{
	Employee aEmployee[EMPLOYEE];
	int option;
	int findId;
	int countId=0;

	initEmployees(aEmployee,EMPLOYEE);

	do
	{
		utn_getUnsignedInt(&option,"\nWhat operation do you want to carry out?\n\n1)Discharge an employee.\n2)Modify employee.\n3)Terminating an employee.\n4)Inform employees.\n5)Exit the program.","Error, this is not a valid option. Please enter a valid option.\n\n1)Discharge an employee.\n2)Modify employee.\n3)Terminating an employee.\n4)Inform employees.\n5)Exit the program.",1,sizeof(int),0,5,3);
		switch(option)
		{
		case 1:
			highEmployee(aEmployee,&countId,EMPLOYEE);
			break;
		case 2:
			if(existingEmployee(aEmployee, EMPLOYEE)==0)
			{
				printEmployees(aEmployee,EMPLOYEE);
				modifyEmployee(aEmployee,EMPLOYEE);
			}
			else
			{
				printf("\nTo modify an employee you must first enter one.");
			}
			break;

		case 3:
			if(existingEmployee(aEmployee, EMPLOYEE)==0)
			{
				utn_getUnsignedInt(&findId,"\nEnter the id of the employee you want to unsubscribe: ","\nError, this id is not found in system",1,sizeof(int),1,EMPLOYEE,3);
				removeEmployee(aEmployee,EMPLOYEE,findId);
			}
			else
			{
				printf("To terminate an employee you must first enter one.");
			}
			break;

		case 4:
			if(existingEmployee(aEmployee,EMPLOYEE)==0)
			{
				sortEmployees(aEmployee,EMPLOYEE);
				printEmployees(aEmployee,EMPLOYEE);
				salaryReport(aEmployee,EMPLOYEE);
			}
			else
			{
				printf("\nYou must load at least one employee before entering this option!\n");
			}
			break;
		}

	}while(option!=5);

	return 0;
}

