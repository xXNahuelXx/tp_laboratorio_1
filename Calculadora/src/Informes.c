/*
 * Informes.c
 *
 *  Created on: 11 sep. 2020
 *      Author: Ivan Nahuel Ghigliotti
 */
#include <stdio.h>
#include <stdlib.h>
#include "Informes.h"

void Informes(float num1,float num2,float resultSuma,float resultResta,float resultDivision,float resultMultiplicacion,int resultFact1,int resultFact2, char* msj)
{
    printf("\n%s",msj);
    printf("\na) El resultado de %.2f+%.2f es: %.2f",num1,num2,resultSuma);
    printf("\nb) El resultado de %.2f-%.2f es: %.2f",num1,num2,resultResta);
    printf("\nc) El resultado de %.2f*%.2f es: %.2f",num1,num2,resultMultiplicacion);
    if(num2==0)
    {
    	printf("\nd)Error! No se puede dividir por 0. Vuelva al menu e ingrese otro numero distinto de cero en la opcion (2)...");
    }
    else
    {
    	printf("\nd) El resultado de %.2f/%.2f es: %.2f",num1,num2,resultDivision);
    }
	if (num1<0)
	{
		printf("\ne) ERROR!...(%d!)-No es posible calcular el factorial de un numero negativo.\nIngrese otro numero en el menu principal.",(int) num1);
	}
	else
	{
		printf("\ne) El factorial de %d! es: %d", (int) num1, resultFact1);
	}
	if (num2<0)
	{
		printf("\n ERROR!...(%d!)-No es posible calcular el factorial de un numero negativo.\nIngrese otro numero en el menu principal.\n\n\n",(int) num2);
	}
	else
	{
		printf("\n El factorial de %d! es: %d\n\n", (int) num2, resultFact2);
	}

}
