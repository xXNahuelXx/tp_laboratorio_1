/*
 * Informes.h
 *
 *  Created on: 11 sep. 2020
 *      Author: Ivan Nahuel Ghigliotti
 */

#ifndef INFORMES_H_
#define INFORMES_H_

/** \brief Muestra los resultado de todos los calculos. Tambien valida antes de mostrar que no se puede dividir por 0 y no se puede realizar el factorial de un numero negativo.
 *
 * \param float Recibe el primer numero.
 * \param float Recibe el segundo numero.
 * \param float Recibe el resultado de la suma para mostrar.
 * \param float Recibe el resultado de la resta para mostrar.
 * \param float Recibe el resultado de la multiplicacion para mostrar.
 * \param float Recibe el resultado de la division para mostrar.
 * \param int Reibe el resultado del factorial del primer numero.
 * \param int Recibe el resultado del factorial del segundo nunmero.
 * \param char* Mensaje que muestra al usuario que eligio la opcion 4 del menu.
 * \return void No retorna nada solo muestra los resultados de todas las operaciones.
 *
 */
void Informes(float,float,float,float,float,float,int,int,char*);

#endif /* INFORMES_H_ */
