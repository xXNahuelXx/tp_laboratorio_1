/*
 * Menu.c
 *
 *  Created on: 12 sep. 2020
 *      Author: Ivan Nahuel Ghigliotti
 */

#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include <ctype.h>
#include "Gets.h"
#include "Operations.h"
#include "Informes.h"

void Menu ()
{
	int option;
	float num1=0;
	float num2=0;
	float resultSuma;
	float resultResta;
	float resultDivision;
	float resultMultiplicacion;
	int resultFact1;
	int resultFact2;
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;
	int auxInt;
	char aux;
	char salir;

	do
	{
		printf("===================================\n");
		printf("*         MENU DE OPCIONES        *\n");
		printf("===================================\n");
		printf("\n(1). Ingresar 1er operando (A=%.2f)\n", num1);
		printf("(2). Ingresar 2do operando (B=%.2f)\n", num2);
		printf("(3). Calcular todas las operaciones\n");
		printf("(4). Informar resultados\n");
		printf("(5). Salir\n");
		GetOption("Ingrese una opcion: ","\nError, ingrese una opcion correcta!", &option, 2, 1, 5);

		switch (option)
		{
			case 1:
				system("cls");
				if (GetNumber("Eligio opcion (1)\nIngrese un numero: ","\nError, ingrese un numero valido!", &num1, 3) == 0)
				{
					printf("\nIngresado correctamente!\n\n");
					flag1 = 1;
				}
				break;
			case 2:
				system("cls");
				if (GetNumber("Eligio opcion (2)\nIngrese un numero: ","\nError, ingrese un numero valido!", &num2, 3) == 0)
				{
					printf("\nIngresado correctamente!\n\n");
					flag2 = 1;
				}
				break;
			case 3:
				if (flag1 == 0 || flag2 == 0)
				{
					printf("\nError! Primero debe ingresar dos numeros\n\n!");
				}
				else
				{
					system("cls");
					printf("\nEligio opcion (3)\n");
					printf("a)Calcular la suma (%.2f+%.2f)", num1, num2);
					Sumar(num1, num2, &resultSuma);
					printf("\nb)Calcular la resta (%.2f-%.2f)", num1, num2);
					Restar(num1, num2, &resultResta);
					printf("\nc)Calcular la division (%.2f/%.2f)", num1, num2);
					Dividir(num1, num2, &resultDivision);
					printf("\nd)Calcular la multiplicacion (%.2f*%.2f)", num1,num2);
					Multiplicar(num1, num2, &resultMultiplicacion);
					printf("\ne)Calcular el factorial de (%d!) y (%d!)\n\n",(int) num1, (int) num2);
					resultFact1 = Factorial((int) num1);
					resultFact2 = Factorial((int) num2);
					flag3 = 1;
				}
				break;
			case 4:
				system("cls");
				if (flag1 == 0 || flag2 == 0 || flag3 == 0)
				{
				printf("\nError! Primero debe ingresar dos numeros y luego calcular sus operaciones\n\n");
				}
				else
				{
					Informes(num1, num2, resultSuma, resultResta, resultDivision,resultMultiplicacion, resultFact1, resultFact2,"Eligio opcion (4)");
				}
				break;
			case 5:
				printf("\nSeguro desea salir? (s/n): ");
				fflush(stdin);
				scanf("%c", &aux);
				salir = tolower(aux);

				if (salir == 's')
				{
					printf("\nSalida con exito\n\n\n");
					option=5;
				}
				else
				{
					option=0;
				}
				break;
			default:
				fflush(stdin);
				if (isdigit(option) == 0)
				{
					auxInt = isdigit(option);
					printf("%d", auxInt);
					printf("\nIngrese una opcion correcta!\n\n");
				}
				break;
		}
		system("pause");
		system("cls");
	} while (option != 5);
}
