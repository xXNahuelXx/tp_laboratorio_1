/*
 * Gets.h
 *
 *  Created on: 20 sep. 2020
 *      Author: Nahuel
 */

#ifndef GETS_H_
#define GETS_H_

/**
 * @brief Ask the user to enter an option.
 *
 * @param Receives the input message.
 * @param Receives the error message.
 * @param Receives a pointer where the number will be loaded.
 * @param Receives the mount of retries that the user will have if enter an invalid information.
 * @param Receives the min number that the user will be able to enter.
 * @param Receives the max number that the user will be able to enter.
 * @return Return -1 if something go wrong (ERROR) or 0 if everything 0k.
 */
int GetOption(char*,char*,int*,int,int,int);

/**
 * @brief Ask the user to enter a number.
 *
 * @param Receives the input message.
 * @param Receives the error message.
 * @param Receives a pointer where the number will be loaded.
 * @param  Receives the mount of retries that the user will have if enter an invalid information.
 * @return  Return -1 if something go wrong (ERROR) or 0 if everything 0k.
 */
int GetInt(char*,char*,int*,int);

/**
 * @brief Ask the user to enter an option 'Yes'or 'No' (s/n).
 *
 * @param Receives the input message.
 * @param Receives the error message.
 * @param Receives a pointer where the character will be loaded.
 * @param Receives the mount of retries that the user will have if enter an invalid information.
 * @return Return -1 if something go wrong (ERROR) or 0 if everything 0k.
 */
int GetChar(char*,char*,char*,int);

/**
 * @brief Ask the user to enter a float number.
 *
 * @param Receives the input message.
 * @param Receives the error message.
 * @param Receives a pointer where the float number will be loaded.
 * @param Receives the mount of retries that the user will have if enter an invalid information.
 * @return Return -1 if something go wrong (ERROR) or 0 if everything 0k.
 */
float GetFloat(char*,char*,float*,int);

/**
 * @brief Ask the user to enter string information.
 *
 * @param Receives the input message.
 * @param  Receives the error message.
 * @param Receives a pointer where the string will be loaded.
 * @param Receives the length of the string.
 * @param Receives the mount of retries that the user will have if enter an invalid information.
 * @return Return -1 if something go wrong (ERROR) or 0 if everything 0k.
 */
int GetString(char*,char*,char*,int,int);
#endif /* GETS_H_ */
