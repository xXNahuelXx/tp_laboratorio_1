/*
 * Validate.h
 *
 *  Created on: 20 sep. 2020
 *      Author: Nahuel
 */

#ifndef VALIDATE_H_
#define VALIDATE_H_

/**
 * @brief Validate if user enter a correct number.
 *
 * @param Receives a pointer string of the number entered to validate.
 * @param Receives the length of the string.
 * @return Return 1 if everything 0k or 0 if something go wrong (ERROR).
 */
int ValidNumber(char*,int);

/**
 * @brief Validate if user enter a correct float number.
 *
 * @param Receives a pointer string of the number entered to validate.
 * @param Receives the length of the string.
 * @return Return 1 if everything 0k or 0 if something go wrong (ERROR).
 */
int ValidFloat(char*,int);

/**
 * @brief Validate string in case user enter space, Enter-key or anything other than letters.
 *
 * @param Receives the string.
 * @param Receives the length of the string.
 * @return Return 1 if everything 0k or 0 if something go wrong (ERROR).
 */
int ValidString (char*,int);

#endif /* VALIDATE_H_ */
