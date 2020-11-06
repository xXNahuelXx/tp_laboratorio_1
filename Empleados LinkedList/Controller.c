#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Gets.h"
#include "Controller.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	int retorno=-1;
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pArchivo=fopen(path,"r");
		if(pArchivo!=NULL)
		{
			if(parser_EmployeeFromText(pArchivo, pArrayListEmployee)==0)
			{
				retorno=0;
			}
			fclose(pArchivo);
		}
	}

	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pArchivo;
	int retorno=-1;
	if(path!=NULL && pArrayListEmployee!=NULL)
	{
		pArchivo=fopen(path,"rb");
		if(pArchivo!=NULL)
		{
			if(parser_EmployeeFromBinary(pArchivo, pArrayListEmployee)==0)
			{
				retorno=0;
			}
			fclose(pArchivo);
		}
	}
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	Employee buffer;
	Employee* pEmployee;
	if(pArrayListEmployee!=NULL)
	{
		pEmployee=employee_new();
		if(pEmployee!=NULL
		   && GetString("Ingrese su nombre: ","Ingrese un dato valido!\n",buffer.nombre,NAME,2)==0
	       && GetInt("Ingrese las horas trabajadas: ","Ingrese un dato valido!\n",&buffer.horasTrabajadas,2)==0
		   && GetFloat("Ingrese su sueldo: ","Ingrese un dato valido!\n",&buffer.sueldo,2)==0)
		{
			buffer.id=employee_GenerarIdEmployee();
			employee_setId(pEmployee,&buffer.id);
			employee_setNombre(pEmployee,buffer.nombre);
			employee_setHorasTrabajadas(pEmployee,&buffer.horasTrabajadas);
			employee_setSueldo(pEmployee,&buffer.sueldo);
			ll_add(pArrayListEmployee,pEmployee);
			printf("#Su id es: %d\n",buffer.id);
			retorno=0;
		}
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int flag = 0;
	int option;
	int index;
	int goBack = 0;
	Employee bufferEmployee;
	Employee* otroBufferEmployee;
	if (pArrayListEmployee!= NULL
			&& GetInt("\nIngrese el ID del empleado a modificar: ",
					"No se encontro ese ID, ingrese un dato valido\n",
					&bufferEmployee.id, 2) == 0
			&& controller_BuscarPorIdEmployee(pArrayListEmployee,bufferEmployee.id,&index) == 0)
	{
		do
		{
			otroBufferEmployee=(Employee*)ll_get(pArrayListEmployee,index);
			if(otroBufferEmployee!=NULL)
			{
			employee_getId(otroBufferEmployee,&bufferEmployee.id);
			employee_getNombre(otroBufferEmployee,bufferEmployee.nombre);
			employee_getHorasTrabajadas(otroBufferEmployee,&bufferEmployee.horasTrabajadas);
			employee_getSueldo(otroBufferEmployee,&bufferEmployee.sueldo);
			printf("*********************************\n");
			printf("Id: %d\nNombre: %s\nHoras Trabajadas: %d\nSueldo: %.2f\n",bufferEmployee.id,
					bufferEmployee.nombre,bufferEmployee.horasTrabajadas,bufferEmployee.sueldo);
			printf("*********************************\n");
			if (GetOption("(1).Nombre\n(2).Horas trabajadas\n(3).Sueldo\n(4).Volver al menu principal\nQue desea modificar?: ","Ingrese un dato valido!\n",&option,2,1,4)==0)
			{
				switch (option)
				{
				case 1:
					if (GetString("Ingrese nuevo nombre: ", "Ingrese un dato valido!\n", bufferEmployee.nombre,NAME,2)==0)
					{
						employee_setNombre(otroBufferEmployee,bufferEmployee.nombre);
						flag = 1;
					}
					break;
				case 2:
					if (GetInt("Ingrese nuevas horas trabajadas: ","Ingrese un dato valido!\n",&bufferEmployee.horasTrabajadas,2)==0)
					{
						employee_setHorasTrabajadas(otroBufferEmployee,&bufferEmployee.horasTrabajadas);
						flag = 1;
					}
					break;
				case 3:
					if (GetFloat("Ingrese nuevo sueldo: ","Ingrese un dato valido!\n",&bufferEmployee.sueldo,2)==0)
					{
						employee_setSueldo(otroBufferEmployee,&bufferEmployee.sueldo);
						flag = 1;
					}
					break;
				case 4:
					if (flag == 1) {
						retorno = 0;
					} else {
						retorno = 1;
					}
					goBack = 1;
					break;
				}
			}
		}
			system("pause");
			system("cls");
		} while (goBack != 1);
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	char bufferChar;
	char confirm;
	int leave = 0;
	int bufferId;
	int indexEmployee;
	Employee* pEmployee;


	if (pArrayListEmployee!=NULL
			&& GetInt("\nIngrese el ID del empleado que desea eliminar: ", "No se encontro ese ID, ingrese un dato valido\n",&bufferId,2)==0
			&& controller_BuscarPorIdEmployee(pArrayListEmployee,bufferId,&indexEmployee)==0)
		{
		if (indexEmployee!=-1)
		{
			pEmployee=(Employee*)ll_get(pArrayListEmployee,indexEmployee);
			if(pEmployee!=NULL)
			{
				do
				{
					if(GetChar("Seguro desea eliminar? (s/n): ","Ingrese un dato valido!\n", &bufferChar, 2)==0)
					{
						confirm=tolower(bufferChar);
						if (confirm=='n')
						{
							retorno=1;
							break;
						}
						else
						{
							if (confirm=='s')
							{
								employee_delete(pEmployee);
								ll_remove(pArrayListEmployee,indexEmployee);
								retorno = 0;
								leave = 1;
							}
						}
					}
					system("pause");
					system("cls");
				} while (leave != 1);
			}
		}
	}
	return retorno;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int retorno=-1;
    int len;
    Employee* auxEmployee;
    Employee otroAuxEmployee;
	if(pArrayListEmployee!=NULL)
    {
    	len=ll_len(pArrayListEmployee);
    	printf("%5s %15s %15s %15s","ID","NOMBRE","HsTrab","SUELDO\n");
		printf("_____________________________________________________\n");
		for(i=0;i<len;i++)
		{
			auxEmployee=(Employee*)ll_get(pArrayListEmployee,i);
			if(auxEmployee!=NULL)
			{
				employee_getId(auxEmployee,&otroAuxEmployee.id);
				employee_getNombre(auxEmployee,otroAuxEmployee.nombre);
				employee_getHorasTrabajadas(auxEmployee,&otroAuxEmployee.horasTrabajadas);
				employee_getSueldo(auxEmployee,&otroAuxEmployee.sueldo);
				printf("%5d %15s %15d %15.2f\n",otroAuxEmployee.id,otroAuxEmployee.nombre,otroAuxEmployee.horasTrabajadas,otroAuxEmployee.sueldo);
				retorno=0;
			}
			else
			{
				printf("ERROR\n");
			}

		}
    }
	return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int order;
	if(pArrayListEmployee!=NULL && GetOption("1 - Ascendente\n0 - Descentende\nIngrese el criterio de ordenamiento: ", "Ingrese un dato valido!\n",&order,2,0,1)==0)
	{
		printf("Espere mientras otrdena...\n");
		ll_sort(pArrayListEmployee,employee_CompararPorSueldo,order);
		retorno=0;
	}
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    int len;
    int i;
	FILE* pArchivo;
	Employee* pEmpleado;
	Employee bufferEmployee;
	if(path!=NULL && pArrayListEmployee!=NULL)
    {
		pArchivo=fopen(path,"w");
		if(pArchivo!=NULL)
		{
			len=ll_len(pArrayListEmployee);
			fprintf(pArchivo,"%s,%s,%s,%s\n","ID","NOMBRE","HSTRABAJADAS","SUELDO");
			for(i=0;i<len;i++)
			{
				pEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
				if(pEmpleado!=NULL)
				{
					employee_getId(pEmpleado,&bufferEmployee.id);
					employee_getNombre(pEmpleado,bufferEmployee.nombre);
					employee_getHorasTrabajadas(pEmpleado,&bufferEmployee.horasTrabajadas);
					employee_getSueldo(pEmpleado,&bufferEmployee.sueldo);
					fprintf(pArchivo,"%d,%s,%d,%f\n",bufferEmployee.id,bufferEmployee.nombre,bufferEmployee.horasTrabajadas,bufferEmployee.sueldo);
				}
			}
			retorno=0;
		}
    }
	return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	   int retorno=-1;
		FILE* pArchivo;
		int len;
		int i;
		Employee* pEmpleado;
		if(path!=NULL && pArrayListEmployee!=NULL)
	    {
			pArchivo=fopen(path,"wb");
			if(pArchivo!=NULL)
			{
				len=ll_len(pArrayListEmployee);
				for(i=0;i<len;i++)
				{
					pEmpleado=(Employee*)ll_get(pArrayListEmployee,i);
					if(pEmpleado!=NULL)
					{
						fwrite(pEmpleado,sizeof(Employee),1,pArchivo);
					}
				}
				retorno=0;
			}
	    }
		return retorno;
}

int controller_BuscarPorIdEmployee(LinkedList* pArrayListEmployee,int id,int* pIndex)
{
	int retorno=-1;
	int i;
	int bufferId;
	int len;
	Employee* pEmployee;
	if(pArrayListEmployee!=NULL && id>0 && pIndex!=NULL)
	{
		len=ll_len(pArrayListEmployee);
		for(i=0;i<len;i++)
		{
			pEmployee=(Employee*)ll_get(pArrayListEmployee,i);
			employee_getId(pEmployee,&bufferId);
			if(pEmployee!=NULL && bufferId==id)
			{
				*pIndex=i;
				retorno=0;
				break;
			}
		}
	}
	return retorno;
}
