/*
 * Gets.h
 *
 *  Created on: 11 sep. 2020
 *      Author: Ivan Nahuel Ghigliotti
 */

#ifndef GETS_H_
#define GETS_H_

/** \brief Pide al usuario que ingrese una opcion del menu, esta validado que pueda ingresar entre 1 y 5 que son los valores comprendidos del menu y se le da -
 * - al usuarui unas posibilidades de reintentos en caso de que ingrese mal.
 *
 * \param char* Recibe el mensaje a mostrar.
 * \param char* Recibe el mensaje de error a mostrar.
 * \param int* Recibe un puntero que es donde se guardara la opcion ingresada.
 * \param int Recibe la cantidad de reintentos.
 * \param int Recibe el minimo de valores que se acepta.
 * \param int Recibe el maximo de valores que se acepta.
 * \return Retorna -1 si algo salio mal o 0 si todo esta ok.
 *
 */
int GetOption(char*,char*,int*,int,int,int);

/** \brief Pide al usuario que ingrese un numero y se le da reintentos en caso de ingresar erroneamente el dato pedido.
 *
 * \param char* Recibe el mensaje a mostrar.
 * \param char* Recibe el mensaje de error a mostrar.
 * \param float* Recibe un puntero que es donde se guardara el numero ingresado.
 * \param int Recibe la cantidad de reintentos.
 * \return Retorna -1 si algo salio mal o 0 si todo esta ok.
 *
 */
int GetNumber(char*,char*,float*,int);

#endif /* GETS_H_ */
