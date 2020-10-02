/*
 * ArrayEmployees.h
 *
 *  Created on: 29 sep. 2020
 *      Author: Nahuel
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}sEmployee;

/**
 * @brief Initialize all Employee's state of the array with 1, thats means they are free to be loaded.
 *
 * @param Receives an Employee's array of type sEmployee and then work with the state(isEmpty) field.
 * @param Receives the length of the array.
 * @return Returns -1 if something go wrong (Error) or 0 if everything 0k.
 */
int InitEmployees(sEmployee*,int);

/**
 * @brief  Load five Employees to make a fast test of the program.
 *
 * @param Receives an Employee's array of type sEmployee.
 * @param Receives the length of the array.
 */
void HardcodeEmployees(sEmployee*,int);

/**
 * @brief Search on the Employee's array if someone free, with field isEmpty in FREE (1).
 *
 * @param Receives an Employee's array of type sEmployee.
 * @param Receives the length of the array.
 * @param Receives a pointer where be loaded with the index found.
 * @return Return -1 if something go wrong (Error) or Employee's free index.
 */
int SearchIndexFree(sEmployee*,int,int*);

/**
 * @brief Generate a new Employee's self-increase id.
 *
 * @return Return the new id for the user.
 */
int GenerateNextId();

/**
 * @brief Search on the Employee's array if id entered by the user it's the same that was loaded previously.
 *
 * @param Receives an Employee's array of type sEmployee.
 * @param Receives the length of the array.
 * @param Receives id previously loaded by the user.
 * @param Receives a pointer where be loaded with the index found.
 * @return Returns -1 if something go wrong (Error) or 0 if everything 0k.
 */
int FindEmployeeById(sEmployee*,int,int,int*);

/**
 * @brief Load the Employee's data and pass the information to another function that load the information on the Employee's array where it's free.
 *
 * @param Receives an Employee's array of type sEmployee.
 * @param Receives the length of the array.
 * @return Returns -1 if something go wrong (Error) or 0 if everything 0k.
 */
int AddEmployeeData(sEmployee*,int);

/**
 * @brief Load the information received by the function AddEmployeeData on the Employee's array where it's free.
 *
 * @param Receives an Employee's array of type sEmployee.
 * @param Receives the length of the array.
 * @param Receives the id previously loaded.
 * @param Receives the name previously loaded.
 * @param Receives the last name previously loaded.
 * @param Receives the salary previously loaded.
 * @param Receives the sector previously loaded.
 * @param Receives the free index where it will load all the information.
 * @return Returns -1 if something go wrong (Error) or 0 if everything 0k.
 */
int AddEmployees(sEmployee*,int,int,char*,char*,float,int,int);

/**
 * @brief Print Employee's information.
 *
 * @param Receives an Employee's array of type sEmployee.
 * @param Receives the length of the array.
 * @return Return -1 if something go wrong or 0 if everything 0k.
 */
int PrintEmployees(sEmployee*,int);

/**
 * @brief Modify Employee's information.
 *
 * @param Receives an Employee's array of type sEmployee.
 * @param Receives the length of the array.
 * @return Return -1 if something go wrong (Error), 0 if everything 0k and 1 if no changes.
 */
int Modify(sEmployee*,int);

/**
 * @brief  Change Employee's state (isEmpty) in 1 (FREE).
 *
 * @param Receives an Employee's array of type sEmployee.
 * @param Receives the length of the array.
 * @param Receives the id to search and compare the id currently loaded with the id previously loaded to know which employee we are going to remove.
 * @return Return -1 if something go wrong (Error), 0 everything 0k and 1 if no changes.
 */
int RemoveEmployee(sEmployee*,int,int);

/**
 * @brief Sort Employee's array by last name and sector in UP[1] or 0[DOWN].
 *
 * @param Receives an Employee's array of type sEmployee.
 * @param Receives the length of the array.
 * @param Receives 1 or 0 to make the sort UP or DOWN.
 * @return Return -1 if something go wrong (Error) or 0 if everything 0k.
 */
int SortEmployees(sEmployee*,int,int);

/**
 * @brief Accumulate total of salary from the Employees.
 *
 * @param Receives an Employee's array of type sEmployee.
 * @param Receives the length of the array.
 * @return Return total salary.
 */
float TotalSalary(sEmployee*,int);

/**
 * @brief Calculate average of salary.
 *
 * @param Receives an Employee's array of type sEmployee.
 * @param Receives the length of the array.
 * @return Return average salary.
 */
float AverageSalary(sEmployee*,int);

/**
 * @brief Calculate how many Employees exceed average salary.
 *
 * @param Receives an Employee's array of type sEmployee.
 * @param Receives the length of the array.
 * @param Receives average to make the function.
 * @return Return the amount of Employees that exceed the average salary.
 */
int ExceededSalary(sEmployee*,int, float);

/**
 * @brief Print Employee's information related to salary.
 *
 * @param Receives an Employee's array of type sEmployee.
 * @param Receives the length of the array.
 * @return Return -1 if something go wrong or 0 if everythin 0k.
 */
int PrintAverageData(sEmployee*,int);

#endif /* ARRAYEMPLOYEES_H_ */
