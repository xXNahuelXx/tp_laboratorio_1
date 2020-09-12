/*
 * Gets.c
 *
 *  Created on: 11 sep. 2020
 *      Author: Ivan Nahuel Ghigliotti
 */

#include <stdio.h>
#include <stdlib.h>
#include "Gets.h"

int GetOption(char* msj,char* msjError,int* pDato,int retries,int min,int max)
{
	int retorno=-1;
	int bufferInt;
	int resultScanf;
	if(msj!=NULL && msjError!=NULL && pDato!=NULL && retries>=0 && max>=min)
	{
		do
		{
			printf("%s",msj);
			fflush(stdin);
			resultScanf=scanf("%d",&bufferInt);
			if(resultScanf==1 && bufferInt>=min && bufferInt<=max)
			{
				*pDato=bufferInt;
				retorno=0;
				break;
			}
			else
			{
				printf("%s Le quedan %d intentos\n",msjError,retries);
				retries--;
			}

		}while(retries>=0);
	}
	return retorno;
}

int GetNumber(char* msj,char* msjError,float* pNum,int retries)
{
    int retorno=-1;
    float bufferFloat;
    int resultScanf;
    if(msj!=NULL && msjError!=NULL && pNum!=NULL && retries>=0)
    {
		do {
			printf("%s", msj);
			fflush(stdin);
			resultScanf = scanf("%f", &bufferFloat);
			if (resultScanf == 1)
			{
				*pNum = bufferFloat;
				retorno = 0;
				break;
			} else
			{
				printf("%s Le quedan %d intentos\n", msjError, retries);
				retries--;
			}
		} while (retries >= 0);
    }

    return retorno;
}
