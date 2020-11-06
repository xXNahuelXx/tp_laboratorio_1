/*
 * parser.h
 *
 *  Created on: 2 nov. 2020
 *      Author: Nahuel
 */

#ifndef PARSER_H_
#define PARSER_H_

/**
 * @brief Se encarga de traer a memoria los datos de texto del archivo y guardar cada dato.
 *
 * @param pFile Recibe el puntero al archivo.
 * @param pArrayListEmployee Recibe la lista enlazada de empleados.
 * @return Retorna 0 si salió todo bien o -1 si algo salió mal.
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/**
 * @brief Se encarga de traer a memoria los datos de manera binaria del archivo y guardar cada dato.
 *
 * @param pFile Recibe el puntero al archivo.
 * @param pArrayListEmployee Recibe la lista enlazada de empleados.
 * @return Retorna 0 si salió todo bien o -1 si salió mal.
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
