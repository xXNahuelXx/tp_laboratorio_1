/*
 * ArrayEmployees.c
 *
 *  Created on: 29 sep. 2020
 *      Author: Nahuel
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "Gets.h"
#define FREE 1
#define FULL 0

int InitEmployees(sEmployee* list,int len)
{
	int retorno=-1;
	int i;
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			list[i].isEmpty=FREE;
			retorno=0;
		}
	}
	return retorno;
}

void HardcodeEmployees(sEmployee* list,int len)
{
    int id[5]= {100,101,102,103,104};
    char name[5][51]= {"Ivan","Antonella","Eliana","Veronica","Kirk"};
    char lastName[5][51]= {"Ghigliotti","Tilbes","Barboza","Soria","Hammett"};
    float salary[5]= {100,200,3000.58,400,500};
    int sector[5]= {5,1,3,2,4};
    int isEmpty[5]= {FULL,FULL,FULL,FULL,FULL};
    int i;

    for(i=0; i<5; i++)
    {
        list[i].id=id[i];
        strcpy(list[i].name,name[i]);
        strcpy(list[i].lastName,lastName[i]);
        list[i].salary=salary[i];
        list[i].sector=sector[i];
        list[i].isEmpty=isEmpty[i];
    }
}

int SearchIndexFree(sEmployee* list,int len,int* pIndex)
{
	int retorno=-1;
	int i;
	if(list!=NULL && len>0 && pIndex!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty==FREE)
			{
				*pIndex=i;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int GenerateNextId()
{
	static int id=104;
	id++;
	return id;
}

int FindEmployeeById(sEmployee* list,int len,int id,int* pIndex)
{
	int retorno=-1;
	int i;
	if(list!=NULL &&  len>0 && pIndex!=NULL)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id==id)
			{
				*pIndex=i;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}

int AddEmployeeData(sEmployee* list,int len)
{
	int retorno=-1;
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int index;
	if(list!=NULL && len>0)
	{
		if(SearchIndexFree(list,len,&index)==0)
		{
			id=GenerateNextId();
			GetString("\n>Ingrese su nombre: ", "Ingrese un dato valido!\n",name,51,2);
			GetString(">Ingrese su apellido: ", "Ingrese un dato valido!\n",lastName,51,2);
			GetFloat(">Ingrese su salario: ","Ingrese un numero valido y/o un punto '.' en su cifra!\n",&salary,2);
			GetOption(">Ingrese su sector <1-2-3-4-5>: ", "Ingrese un dato valido!\n",&sector,2,1,5);
			if(AddEmployees(list,len,id,name,lastName,salary,sector,index)==0)
			{
				printf("#Su id es: %d\n\n",list[index].id);
				list[index].isEmpty=FULL;
				retorno=0;
			}
		}
		else
		{
			printf(">> No hay espacio suficiente para agregar otro empleado! <<\n");
		}
	}

	return retorno;
}

int AddEmployees(sEmployee* list,int len,int id,char* name,char* lastName,float salary,int sector,int index)
{
    int retorno=-1;
    if(list!=NULL && len>0 && id>0 && name!=NULL && lastName!=NULL && salary>0 && (sector>1 || sector<5) && index>=0)
    {
		list[index].id=id;
		strcpy(list[index].name,name);
		strcpy(list[index].lastName,lastName);
		list[index].salary=salary;
		list[index].sector=sector;
		retorno=0;
    }
    return retorno;
}

int PrintEmployees(sEmployee* list,int len)
{
    int i;
    int retorno=-1;
    char id[5]= {"ID"};
    char name[8]= {"NOMBRE"};
    char lastName[10]= {"APELLIDO"};
    char salary[10]= {"SALARIO"};
    char sector[8]= {"SECTOR"};
    int option;

	if(list!=NULL && len>0)
	{
    	GetOption("\nIngrese [1] para ordenar por apellido en forma ascendente\nIngrese [0] para ordenar por apellido en forma descendente\n","Ingrese un dato valido!\n",&option,2,0,1);
		SortEmployees(list, len, option);
    	printf("\n%s %20s %19s %15s %10s\n",id,name,lastName,salary,sector);
		printf("_______________________________________________________________________\n");
		for(i=0; i<len; i++)
		{
			if(list[i].isEmpty==FULL)
			{
				printf("%d %19s %19s %15.2f %8d\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
				retorno=0;
			}
		}
	}
    printf("\n\n");
    return retorno;
}

int Modify(sEmployee* list,int len)
{
    int retorno=-1;
    int flag=0;
    int bufferId;
    int option;
    int index;
    int goBack=0;
    char bufferName[51];
    char bufferLastName[51];
    float bufferSalary;
    int bufferSector;

    PrintEmployees(list,len);
    if(list!=NULL && len>0 && GetInt("\nIngrese el ID del empleado que desea modificar: ", "No se encontro ese ID, ingrese un dato valido\n",&bufferId,2)==0
    		&& FindEmployeeById(list,len,bufferId,&index)==0)
    {
    	do
    	{
    	            printf("*********************************\n");
    	            printf("Empleado: %s %s\nId: %d\nSalario: $%.2f\nSector: %d\n",list[index].name,
    	                   list[index].lastName,
    	                   list[index].id,
    	                   list[index].salary,
    	                   list[index].sector);
    	            printf("*********************************\n");
    	            printf("(1).Nombre\n");
    	            printf("(2).Apellido\n");
    	            printf("(3).Salario\n");
    	            printf("(4).Sector\n");
    	            printf("(5).Volver al menu principal\n");
    	            if(GetOption("Que desea modificar?: ", "Ingrese un dato valido!\n",&option,2,1,5)==0)
    	            {
						switch(option)
						{
						case 1:
							if(GetString("Ingrese nuevo nombre: ","Ingrese un dato valido!\n",bufferName,51,2)==0)
							{
								strncpy(list[index].name,bufferName,51);
								flag=1;
							}
							break;
						case 2:
							if(GetString("Ingrese nuevo apellido: ","Ingrese un dato valido!\n", bufferLastName,51,2)== 0)
							{
								strncpy(list[index].lastName, bufferLastName, 51);
								flag = 1;
							}
							break;
						case 3:
							if(GetFloat("Ingrese nuevo salario: ","Ingrese un numero valido y/o un punto '.' en su cifra!\n",&bufferSalary,2)==0)
							{
								list[index].salary=bufferSalary;
								flag=1;
							}
							break;
						case 4:
							if(GetOption("Ingrese nuevo sector","Ingrese un dato valido!\n",&bufferSector,2,1,5)==0)
							{
								list[index].sector=bufferSector;
								flag=1;
							}
							break;
						case 5:
							if(flag==1)
							{
								retorno=0;
							}
							else
							{
								retorno=1;
							}
							goBack=1;
							break;
						}
    	            }
    	            system("pause");
    	            system("cls");
    	        }
    	        while(goBack!=1);
    }
    return retorno;
}

int RemoveEmployee(sEmployee* list,int len,int id)
{
	int retorno=-1;
    char bufferChar;
    char confirm;
    int leave=0;
    int index;

    if(list!=NULL && len>0 && id>0 && FindEmployeeById(list,len,id,&index)==0)
    {
		if(index!=-1)
		{
			do
			{
				printf("******************************\n");
				printf("Empleado: %s %s\nId: %d\nSalario: $%.2f\nSector: %d\n",list[index].name,
					   list[index].lastName,
					   list[index].id,
					   list[index].salary,
					   list[index].sector);
				printf("******************************\n");
				if(GetChar("Seguro desea eliminar este emplado? (s/n): ", "Ingrese un dato valido!\n",&bufferChar,2)==0)
				{
					confirm=tolower(bufferChar);
					if(confirm == 'n')
					{
						retorno = 1;
						break;
					}
					else
					{
						if (confirm == 's')
						{
							list[index].isEmpty=FREE;
							retorno = 0;
							leave=1;
						}
					}
				}

				system("pause");
				system("cls");
			}while(leave!=1);
		}
    }
    return retorno;
}

int SortEmployees(sEmployee* list,int len,int order)
{
    int retorno=-1;
    int i;
    int ordered=0;
    sEmployee swap;

    if(list!=NULL && len>0 && (order==0 || order==1))
    {
		if(order==1)
    	{
    		while(ordered==0)
			{
				ordered=1;
				for(i=0;i<len-1;i++)
				{
					if((list[i].isEmpty==FULL && strncmp(list[i].lastName,list[i+1].lastName,51)>0) || (strncmp(list[i].lastName,list[i+1].lastName,51)==0 && list[i].sector>list[i+1].sector))
					{
						swap=list[i];
						list[i]=list[i+1];
						list[i+1]=swap;
						ordered=0;
					}
				}
				retorno=0;
			}
    	}
		if(order==0)
		{
			while(ordered==0)
			{
				ordered=1;
				for(i=0;i<len-1;i++)
				{
					if((list[i].isEmpty==FULL && strncmp(list[i].lastName,list[i+1].lastName,51)<0) || (strncmp(list[i].lastName,list[i+1].lastName,51)==0 && list[i].sector<list[i+1].sector))
					{
						swap=list[i];
						list[i]=list[i+1];
						list[i+1]=swap;
						ordered=0;
					}
				}
				retorno=0;
			}
		}
    }
    return retorno;
}

float TotalSalary(sEmployee* list,int len)
{
    int i;
    float totalAcumSalary=0;
    if(list!=NULL && len>0)
    {
    	for(i=0; i<len; i++)
    	{
    		if(list[i].isEmpty==FULL)
    		{
    			totalAcumSalary+=list[i].salary;
    		}
    	}
    }
    return totalAcumSalary;
}

float AverageSalary(sEmployee* list,int len)
{
    int i;
    int contEmployee=0;
    float acumSalary=TotalSalary(list,len);

    if(list!=NULL && len>0)
    {
    	for(i=0; i<len; i++)
    	{
    		if(list[i].isEmpty==FULL)
    		{
    			contEmployee++;
    		}
    	}
    }
    return acumSalary/contEmployee;
}

int ExceededSalary(sEmployee* list,int len, float average)
{
    int i;
    int contEmpwExSalary=0;

    if(list!=NULL && len>0)
    {
    	average=AverageSalary(list,len);
    	for(i=0; i<len; i++)
    	{
    		if(list[i].isEmpty==FULL && list[i].salary>average)
    		{
    			contEmpwExSalary++;
    		}
    	}
	}
    return contEmpwExSalary;
}

int PrintAverageData(sEmployee* list,int len)
{
    int i;
    int retorno=-1;
    char id[5]= {"ID"};
    char name[8]= {"NOMBRE"};
    char lastName[10]= {"APELLIDO"};
    char salary[10]= {"SALARIO"};
    float totalSalary=TotalSalary(list,len);
    float averageSalary=AverageSalary(list,len);
    int exceededSalary=ExceededSalary(list,len,averageSalary);

    if(list!=NULL && len>0)
    {
    	printf("\nEl total de los salarios es de: $%.2f\nEl promedio total de los salarios es de: $%.2f\nLa cantidad de empleados que superan el salario promedio es de: %d\n",totalSalary,averageSalary,exceededSalary);
    	if(exceededSalary==0)
    	{
    		printf("\n>>> NINGUN EMPLEADO SUPERA EL SALARIO PROMEDIO! <<<\n\n");
    	}
    	else
    	{
    		printf("\nEMPLEADOS QUE SUPERAN EL SALARIO PROMEDIO: \n\n");
    		printf("\n%s %20s %19s %15s\n",id,name,lastName,salary);
    		printf("______________________________________________________________\n");
    		for(i=0; i<len; i++)
    		{
    			if(list[i].isEmpty==FULL && list[i].salary>averageSalary)
    			{
    				printf("%d %19s %19s %15.2f\n",list[i].id,list[i].name,list[i].lastName,list[i].salary);
                	retorno=0;
    			}
    		}
    		printf("\n\n");
    	}
    }
    return retorno;
}
