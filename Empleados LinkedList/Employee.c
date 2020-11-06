#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "Validate.h"

//implementar set y gets

Employee* employee_new()
{
	return (Employee*)malloc(sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* pEmployee=NULL;
	pEmployee=employee_new();
	if(pEmployee!=NULL && idStr!=NULL && nombreStr!=NULL && horasTrabajadasStr!=NULL && sueldoStr!=NULL)
	{
		employee_setIdChar(pEmployee,idStr);
		employee_setNombre(pEmployee,nombreStr);
		employee_setHorasTrabajadasChar(pEmployee,horasTrabajadasStr);
		employee_setSueldoChar(pEmployee,sueldoStr);
	}
	return pEmployee;
}

void employee_delete(Employee* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}

int employee_setId(Employee* this,int* id)
{
	int retorno=-1;
	if(this!=NULL && id!=NULL)
	{
		this->id=*id;
		retorno = 0;
	}
	 return retorno;
}

int employee_setIdChar(Employee* this,char* id)
{
	int retorno=-1;
	if(this!=NULL && id!=NULL && ValidNumber(id,sizeof(id))==1)
	{
		this->id=atoi(id);
		retorno = 0;
	}
	 return retorno;
}

int employee_getId(Employee* this,int* id)
{
	int result=-1;
	if (this != NULL && id != NULL)
	{
		*id = this->id;
		result=0;
	}
	return result;
}


int employee_setNombre(Employee* this,char* nombre)
{
	int retorno=-1;
	if(this!=NULL && nombre!=NULL && ValidString(nombre,sizeof(nombre))==1)
	{
		strncpy(this->nombre,nombre,(int)sizeof(this->nombre));
		retorno = 0;
	}
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int retorno=-1;
	if (this != NULL && nombre != NULL)
	{
		strncpy(nombre, this->nombre,NAME);
		retorno=0;
	}
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas>0)
	{
		this->horasTrabajadas=*horasTrabajadas;
		retorno = 0;
	}
	 return retorno;
}

int employee_setHorasTrabajadasChar(Employee* this,char* horasTrabajadas)
{
	int retorno = -1;
	if(this != NULL && horasTrabajadas>0 && ValidNumber(horasTrabajadas,sizeof(horasTrabajadas))==1)
	{
		this->horasTrabajadas=atoi(horasTrabajadas);
		retorno = 0;
	}
	 return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno=-1;
	if (this!=NULL && horasTrabajadas!=NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		retorno=0;
	}
	return retorno;
}

int employee_setSueldo(Employee* this,float* sueldo)
{
	int retorno = -1;
	if(this!=NULL && sueldo!=NULL)
	{
		this->sueldo=*sueldo;
		retorno = 0;
	}
	 return retorno;
}

int employee_setSueldoChar(Employee* this,char* sueldo)
{
	int retorno = -1;
	if(this!=NULL && sueldo>0 && ValidFloat(sueldo,sizeof(sueldo))==1)
	{
		this->sueldo =atof(sueldo);
		retorno = 0;
	}
	 return retorno;
}

int employee_getSueldo(Employee* this,float* sueldo)
{
	  int retorno=-1;
	if (this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		retorno = 0;
	}
	return retorno;
}

int employee_GenerarIdEmployee(void)
{
	static int id=1000;
	id++;
	return id;
}

int employee_CompararPorSueldo(void* employee1,void* employee2)
{
	int retorno=0;
	float bufferEmployee1;
	float bufferEmployee2;

	if(employee1!=NULL && employee2!=NULL)
	{
		employee_getSueldo((Employee*)employee1,&bufferEmployee1);
		employee_getSueldo((Employee*)employee2,&bufferEmployee2);
		if(bufferEmployee1>bufferEmployee2)
		{
			retorno=1;
		}
		else if(bufferEmployee1<bufferEmployee2)
		{
			retorno=-1;
		}
		else
		{
			retorno=0;
		}
	}
	return retorno;
}

