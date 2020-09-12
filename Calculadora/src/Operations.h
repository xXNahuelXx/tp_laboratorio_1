/*
 * Operations.h
 *
 *  Created on: 11 sep. 2020
 *      Author: Ivan Nahuel Ghigliotti
 */

#ifndef OPERATIONS_H_
#define OPERATIONS_H_

/** \brief Realiza la suma de dos numeros que recibe por valor y los guarda en otra que recibe por referencia.
 *
 * \param float Recibe el primer numero.
 * \param float Recibe el segundo numero.
 * \param float* Recibe el puntero donde se guardara el resultado.
 * \return  int Devuelve -1 si algo salio mal o 0 si todo esta ok.
 *
 */
int Sumar(float,float,float*);

/** \brief Realiza la resta de dos numeros que recibe por valor y los guarda en otra que recibe por referencia.
 *
 * \param float Recibe el primer numero.
 * \param float Recibe el segundo numero.
 * \param float* Recibe el puntero donde se guardara el resultado.
 * \return  int Devuelve -1 si algo salio mal o 0 si todo esta ok.
 *
 */
int Restar(float,float,float*);

/** \brief Realiza la division de dos numeros que recibe por valor y los guarda en otra que recibe por referencia.
 *
 * \param float Recibe el primer numero.
 * \param float Recibe el segundo numero.
 * \param float* Recibe el puntero donde se guardara el resultado.
 * \return  int Devuelve -1 si algo salio mal o 0 si todo esta ok.
 *
 */
int Dividir(float,float,float*);

/** \brief Realiza la multiplicacion de dos numeros que recibe por valor y los guarda en otra que recibe por referencia.
 *
 * \param float Recibe el primer numero.
 * \param float Recibe el segundo numero.
 * \param float* Recibe el puntero donde se guardara el resultado.
 * \return  int Devuelve -1 si algo salio mal o 0 si todo esta ok.
 *
 */
int Multiplicar(float,float,float*);

/** \brief Realiza el factorial de un numero. Tiene ese tipo de dato para que pueda realizar el factorial de un numero alto (llega hasta el factorial de 12).
 *
 * \param int Recibe el numero
 * \return unsigned long long int Devuelve el resultado del factorial.
 *
 */
unsigned long long int Factorial(int);

#endif /* OPERATIONS_H_ */
