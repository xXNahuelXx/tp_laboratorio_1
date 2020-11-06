#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Gets.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    setbuf(stdout,NULL);
	int option;
	char bufferChar;
	char salir;
	int flagLtxt=0;
	int flagSaveBin=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{

    	GetOption("MENU\n\n"
    			"1).Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n"
    			"2).Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n"
    			"3).Alta de empleado.\n"
    			"4).Modificar datos de empleado.\n"
    			"5).Baja de empleado.\n"
    			"6).Listar empleados.\n"
    			"7).Ordenar empleados.\n"
    			"8).Guardar los datos de los empleados en el archivo data.csv (modo texto).\n"
    			"9).Guardar los datos de los empleados en el archivo data.csv (modo binario).\n"
    			"10).Salir.\nIngrese una opcion: ", "Ingrese un dato valido!\n",&option,2,1,10);
    	switch(option)
        {
            case 1:
                if(!controller_loadFromText("data.csv",listaEmpleados))
                {
                	printf(">>> CARGADO CON EXITO <<<\n");
                	flagLtxt=1;
                }
                break;
            case 2:
            	if(flagSaveBin==1)
            	{
            		if(!controller_loadFromBinary("auxDataBin.bin", listaEmpleados))
					{
						printf(">>> CARGADO CON EXITO <<<\n");
					}
            	}
            	else
            	{
            		printf("Primero debe guardar el arhivo de texto en forma binaria!\n");
            	}
            	break;
            case 3:
            	if(!controller_addEmployee(listaEmpleados))
            	{
            		printf(">>> ALTA EXITOSA <<<\n");
            	}
            	else
            	{
            		printf(">>> NO SE PUDO REALIZAR EL ALTA <<<\n");
            	}
            	break;
            case 4:
            	if(flagLtxt==1)
            	{
					controller_ListEmployee(listaEmpleados);
					switch(controller_editEmployee(listaEmpleados))
					{
						case 0:
							printf(">>> MODIFICADO CON EXITO! <<<\n");
							break;
						case -1:
							printf(">>> NO PUDO SER MODIFICADO! <<<\n");
							break;
						case 1:
							printf(">>> NO SE REALIZARON CAMBIOS! <<<\n");
							break;
					}
            	}
            	else
            	{
            		printf("Primero debe cargar el archivo en la opcion (1)!\n");
            	}
            	break;
            case 5:
            	if(flagLtxt==1)
            	{
					controller_ListEmployee(listaEmpleados);
					switch(controller_removeEmployee(listaEmpleados))
					{
						case 0:
							printf(">>>ELIINADO CON EXITO! <<<\n");
							break;
						case 1:
							printf(">>> NO SE HAN REALIZADO CAMBIOS! <<<\n");
							break;
						case -1:
							printf(">>> NO SE PUDO ELIMINAR! <<<\n");
							break;
					}
            	}
            	else
            	{
            		printf("Primero debe cargar el archivo en la opcion (1)!\n");
            	}
            	break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
            	break;
            case 7:
            	if(flagLtxt==1 && !controller_sortEmployee(listaEmpleados))
            	{
            		printf(">>> ORDENADO CON EXITO! <<<\n");
            	}
            	else
            	{
            		printf("Primero debe cargar el archivo en la opcion (1)!\n");
            	}
            	break;
            case 8:
            	if(flagLtxt==1)
            	{
            		controller_saveAsText("data.csv",listaEmpleados);
            		printf(">>> GUARDADO CON EXITO <<<\n");
            	}
            	else
            	{
            		printf("Primero debe cargar el archivo de texto en la opcion (1)!\n");
            	}
            	break;
            case 9:
            	if(flagLtxt==1)
            	{
            		controller_saveAsBinary("auxDataBin.bin",listaEmpleados);
            		printf(">>> GUARDADO CON EXITO <<<\n");
            		flagSaveBin=1;
            	}
            	else
            	{
            		printf("Primero debe cargar el archivo de texto en la opcion (1)!\n");
            	}
            	break;
            case 10:
            	if(GetChar("Asegurese de guardar los cambios antes. Seguro desea salir? (s/n): ","Ingrese un dato valido!\n",&bufferChar,2)==0)
				{
					salir=tolower(bufferChar);
					if(salir=='s')
					{
						ll_deleteLinkedList(listaEmpleados);
						printf("\n>>> SALIDA CON EXITO <<<\n\n\n");
						option=10;
					}
					else if(salir=='n')
					{
						option=0;
					}
				}
            	break;
        }
    	system("pause");
		system("cls");
    }while(option != 10);
    return 0;
}

