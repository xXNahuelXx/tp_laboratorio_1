/*
 * Menu.c
 *
 *  Created on: 29 sep. 2020
 *      Author: Nahuel
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Menu.h"
#include "Gets.h"
#include "ArrayEmployees.h"
#define ELEMENTS 1000

void Menu()
{
	sEmployee arrayEmployees[ELEMENTS];
	int option;
	int subOption;
	int i=0;
	int flagAlta=0;
	char bufferChar;
	char leave;
	int rM;
	int rR;
	int bufferId;

	if(InitEmployees(arrayEmployees,ELEMENTS)==0)
	{
		//In order to make use of this Hardcodeo, you must uncomment the following lines (31,32,33).
		/*HardcodeEmployees(arrayEmployees,ELEMENTS);
		flagAlta=1; // This variable its necesary if you want to try out option 2,3 and 4 with the function Hardcode.
		i=1;*/       //This variable its necesary if you want to try out option 2,3 and 4 with the function Hardcode.
		do
		{
			printf("**********************\n");
			printf(">       MENU         <\n");
			printf("**********************\n\n");
			printf("1).Alta de empleado\n");
			printf("2).Modificar empleado\n");
			printf("3).Baja de empleado\n");
			printf("4).Informar\n");
			printf("5).Salir\n\n");
			GetOption("Ingrese una opcion: ","Ingrese un dato valido!\n",&option,2,1,5);

			switch(option)
			{
				case 1:
					system("cls");
					printf("**********************\n");
					printf(">  ALTA DE EMPLEADO  <\n");
					printf("**********************\n");
					if (AddEmployeeData(arrayEmployees, ELEMENTS)!=0)
					{
						printf("\n>>> NO HAY MAS ESPACIO! <<<\n\n");
					}
					else
					{
						printf("\n>>> CARGADO CON EXITO! <<<\n\n");
						flagAlta=1;
						i++;
					}
					break;
				case 2:
					if(flagAlta!=1 || i==0)
					{
						printf("\nPrimero debe dar de alta un empleado\n\n");
					}
					else
					{
						system("cls");
					    printf("************************\n");
					    printf(">  MODIFICAR EMPLEADO  <\n");
					    printf("************************\n");
					    rM=Modify(arrayEmployees,ELEMENTS);
					    switch(rM)
					    {
					    	case 0:
					    		system("cls");
					    		printf("\n>>> MODIFICADO CON EXITO! <<<\n\n");
					    		break;
					        case -1:
					            system("cls");
					            printf("\n>>> NO SE PUDO MODIFICAR! <<<\n\n");
					            break;
					        case 1:
					            system("cls");
					            printf("\n>>> NO SE HAN REALIZADO CAMBIOS! <<<\n\n");
					            break;
					    }
					}
					break;
				case 3:
					if (flagAlta != 1 || i == 0)
					{
						printf("\nPrimero debe dar de alta un empleado\n\n");
					}
					else
					{
						system("cls");
						printf("************************\n");
						printf(">   ELIMINAR EMPLEADO  <\n");
						printf("************************\n");
						PrintEmployees(arrayEmployees, ELEMENTS);
						GetInt("\nIngrese el ID del empleado que desea eliminar: ","Ingrese un dato valido!\n",&bufferId,2);
						rR =RemoveEmployee(arrayEmployees,ELEMENTS,bufferId);
						switch (rR)
						{
							case 0:
								system("cls");
								printf("\n>>> ELIMINADO CON EXITO! <<<\n\n");
								i--;
								break;
							case -1:
								system("cls");
								printf("\n>>> NO SE PUDO ELIMINAR <<<\n\n");
								break;
							case 1:
								system("cls");
								printf("\n>>> NO SE HAN REALIZADO CAMBIOS! <<<\n\n");
								break;
						}
					}
					break;
				case 4:
					system("cls");
					printf("************************\n");
					printf(">   LISTAR EMPLEADOS   <\n");
					printf("************************\n");

					if (flagAlta != 1 || i == 0)
					{
						printf("\nPrimero debe dar de alta un empleado\n\n");
					}
					else
					{
						do
						{
							printf("\n1).Listar empleados ordenados alfabeticamente por Apellido y Sector");
							printf("\n2).Total y promedio de los salarios, y empleados que superan el salario promedio");
							printf("\n3).Volver al menu principal\n");
							GetOption("Ingrese una opcion: ","Ingrese un dato valido!\n",&subOption,2,1,3);
							switch (subOption)
							{
								case 1:
									system("cls");
									PrintEmployees(arrayEmployees, ELEMENTS);
									break;
								case 2:
									system("cls");
									PrintAverageData(arrayEmployees, ELEMENTS);
									break;
							}
						} while (subOption!=3);
					}
					break;
				case 5:
					if(GetChar("Seguro desea salir? (s/n): ", "Ingrese un dato valido!\n",&bufferChar,2)==0)
					{
						leave=tolower(bufferChar);
						if(leave=='s')
						{
							printf("\n>>> SALIDA CON EXITO <<<\n\n\n");
							option=5;
						}
						else if(leave=='n')
						{
							option=0;
						}
					}
					break;
			}
				system("pause");
				system("cls");
		}while(option!=5);
	}
	else
	{
		printf(">> NO PUDOD INICIARSE EL PROGRAMA CORRECTAMENTE! <<\n\n");
	}
}

