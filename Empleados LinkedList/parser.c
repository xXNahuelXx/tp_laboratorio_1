#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	char cabecera[100];
	char id[100];
	char nombre[100];
	char horasTrabajadas[100];
	char sueldo[100];
	Employee* pEmployee;

	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		fscanf(pFile,"%[^\n]\n",cabecera);
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo)==4)
			{
				pEmployee=employee_newParametros(id,nombre,horasTrabajadas,sueldo);
				if(pEmployee!=NULL)
				{
					ll_add(pArrayListEmployee,pEmployee);
					retorno=0;
				}
			}
		}while(!feof(pFile));
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	Employee* pEmployee;
	int cargado;
	if(pFile!=NULL && pArrayListEmployee!=NULL)
	{
		do
		{
			pEmployee=employee_new();
			if(pEmployee!=NULL)
			{
				cargado=fread(pEmployee,sizeof(Employee),1,pFile);
				if(cargado==1)
				{
					ll_add(pArrayListEmployee,pEmployee);
					retorno=0;
				}
			}
			else
			{
				employee_delete(pEmployee);
			}
		}while(!feof(pFile));
	}
	return retorno;
}
