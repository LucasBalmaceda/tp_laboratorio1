#include "utn.h"

#include "arrayEmployee.h"
#include "reports.h"


int initEmployees(Employee *list, int len)
{
	int ret=-1;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			list[i-1].isEmpty=1;
		}
		ret = 0;
	}

	return ret;
}


//-----------------------------------------------------------------------------------------------------------------------------------------//


int addEmployee(Employee *list, int len, int id, char name[], char lastName[], float salary, int sector)
{
	int ret=-1;

	if(list!=NULL && name!=NULL && lastName!=NULL && len>0 && id>0 && salary>0 && sector>0)
	{
		strcpy(list[id].name,name);
		strcpy(list[id].lastName,lastName);
		list[id].id=id;
		list[id].salary=salary;
		list[id].sector=sector;
		list[id].isEmpty=0;

		ret=0;
	}

	return ret;
}

int highEmployee(Employee *list, int *idCont, int len)
{
	int ret=-1;
	int position;
	int auxId;
	char auxName[55];
	char auxLastName[55];
	float auxSalary;
	int auxSector;

	if(list!=NULL && len>0)
	{
		if(findEmptyPosition(list,&position,len)==0)
		{
			(*idCont)++;
			auxId=*idCont;
			utn_getText(auxName,"\nName: ","\nError, this name is not valid.",1,55,3);
			utn_getText(auxLastName,"\nLast Name: ","\nError, this last name is not valid.",1,55,3);
			utn_getFloat(&auxSalary,"\nSalary: ","\nError, this salary is not valid.",1,150000,1,120000,3);
			utn_getUnsignedInt(&auxSector,"\nSector: ","\nError, this sector is not valid",1,sizeof(int),1,10,3);

			addEmployee(list,len,auxId,auxName,auxLastName,auxSalary,auxSector);
			ret=0;
		}
		else
		{
			printf("\nThere are no more places to register.");
		}
	}

	return ret;
}

int removeEmployee(Employee *list, int len, int id)
{
	int ret=-1;
	int position;

	if(list!=NULL && len>0 && id>0)
	{
		if(findEmployeeById(list,&position,len,id))
		{
			list[id].isEmpty=1;
			ret=0;
		}
		else
		{
			printf("\nError, id %d not found in employee log",position);
		}
	}

	return ret;
}

int modifyEmployee(Employee *list, int len)
{
	int ret=-1;
	int id;
	int position;
	int option;

	if(list!=NULL && len>0)
	{
		utn_getUnsignedInt(&id,"\nEnter the id of the employee you want to modify.","\nError, ID not found in the program",1,sizeof(int),1,len,3);

		if(findEmployeeById(list,&position,len,id)==0)
		{
			do
			{
				utn_getUnsignedInt(&option,"\n\nChoose an option to modify.\n\n1)Name:\n2)Last Name:\n3)Salary:\n4)Sector:\n5)Exit.","\n\nError, that option is not available. Please choose another.",1,sizeof(int),1,5,3);

				switch(option)
				{
				case 1:
					utn_getText(list[position].name,"\n\nEnter the new name: ","\nError, this name is not appropriate.",1,55,3);
					break;
				case 2:
					utn_getText(list[position].lastName,"\nEnter the new last name: ","\n\nError, this last name is not appropriate.",1,55,3);
					break;
				case 3:
					utn_getFloat(&list[position].salary,"\nEnter the new salary: ","\n\nError, this salary is not correct.",1,150000,1,120000,3);
					break;
				case 4:
					utn_getUnsignedInt(&list[position].sector,"\nEnter new sector: ","\n\nError, this sector is not available.",1,sizeof(int),1,10,3);
					break;
				}
			}while(option!=5);
		}
		else
		{
			printf("\nThat ID was not found, please enter another.");
		}
	}

	return ret;
}


//-----------------------------------------------------------------------------------------------------------------------------------------//


int findEmployeeById(Employee *list, int *pResult, int len, int id)
{
	int ret=-1;
	int i;

	if(list!=NULL && len>0 && id>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==1)
			{
				continue;
			}
			else if(list[i].id==id)
			{
				*pResult = id;
				ret=0;
				break;
			}
		}
	}

	return ret;
}

int findEmptyPosition(Employee *list, int *position, int len)
{
	int ret=-1;
	int i;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==1)
			{
				*position=i;
				ret=0;
				break;
			}
		}
	}

	return ret;
}


//-----------------------------------------------------------------------------------------------------------------------------------------//


int sortEmployees(Employee *list, int len)
{
	int ret=-1;
	int i,j;
	Employee auxEmployee;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			for(j=i+1;j<len;j++)
			{
				if(strcmp(list[j].lastName,list[i].lastName) < 0)
				{
					auxEmployee = list[i];
					list[i]=list[j];
					list[j]=auxEmployee;
				}
				else if(strcmp(list[j].lastName,list[i].lastName)==0 && list[j].sector < list[i].sector)
				{
					auxEmployee = list[i];
					list[i]=list[j];
					list[j]=auxEmployee;
				}
			}
		}
	}

	return ret;
}

int printEmployees(Employee *list, int len)
{
	int ret=-1;
	int i;
	if(list!=NULL && len>=0)
	{
		printf("\nID\tLast Name\t\t\tName\t\tSalary\t\tSector\n");
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==1)
			{
				continue;
			}
			else
			{
				printf("\n%d\t%s\t\t\t%s\t\t%.2f\t\t%d",list[i].id,list[i].lastName,list[i].name,list[i].salary,list[i].sector);
			}
		}
		ret=0;
	}

	return ret;
}

int salaryReport(Employee *list,int len)
{
	int ret=-1;
	int i;
	float accumulator=0;
	float total=0;
	int accountant=0;
	int highPaidEmployees=0;

	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==0)
			{
				accountant++;
				accumulator=accumulator+list[i].salary;
			}
		}
		total=accumulator/accountant;

		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==0 && list[i].salary>total)
			{
				highPaidEmployees++;
			}
		}
		printf("\n\nTotal salary: %.2f ", accumulator);
		printf("\nAverage wages: %.2f ", total);
		printf("\nNumber of employees that exceed the average salary: %d \n", highPaidEmployees);

		ret = 0;
	}

	return ret;
}

int existingEmployee(Employee *list, int len)
{
	int ret = -1;
	int i;

	for( i = 0; i < len; i++)
	{
		if(list[i].isEmpty == 0)
		{
			ret = 0;
		}
	}
	return ret;
}
