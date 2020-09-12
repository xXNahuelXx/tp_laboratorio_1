/*
 * Operations.c
 *
 *  Created on: 11 sep. 2020
 *      Author: Ivan Nahuel Ghigliotti
 */
#include <stdio.h>
#include <stdlib.h>
#include "Operations.h"

int Sumar(float num1,float num2,float* pResult)
{
	int retorno=-1;
	if(pResult!=NULL)
	{
		*pResult=num1+num2;
		retorno=0;
	}
	return retorno;
}

int Restar(float num1,float num2,float* pResult)
{
	int retorno=-1;
	if(pResult!=NULL)
	{
		*pResult=num1-num2;
		retorno=0;
	}
	return retorno;
}

int Dividir(float num1,float num2,float* pResult)
{
	int retorno=-1;
	if(pResult!=NULL && num2!=0)
	{
		*pResult=num1/num2;
		retorno=0;
	}
	return retorno;
}

int Multiplicar(float num1,float num2,float* pResult)
{
	int retorno=-1;
	if(pResult!=NULL)
	{
		*pResult=num1*num2;
		retorno=0;
	}
	return retorno;
}

unsigned long long int Factorial(int numero1)
{
    long unsigned int resultado=1;
    int i;

    if(numero1==0)
    {
        resultado=1;
    }
    else
    {
        for(i=1; i<=numero1; i++)
        {
            resultado=resultado*i;
        }
    }
    return resultado;
}
