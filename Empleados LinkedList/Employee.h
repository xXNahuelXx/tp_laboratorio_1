#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#define NAME 128

typedef struct
{
    int id;
    char nombre[NAME];
    int horasTrabajadas;
    float sueldo;
}Employee;

/**
 * @brief Busca espacio en memoria dinámica para un empleado.
 *
 * @return Retorna NULL si no encontró espacio o la direccion de memoria del espacio que encontró.
 */
Employee* employee_new();

/**
 * @brief Busca espacio en memoria dinámica para un empleado con datos previamente cargados para asignarlo en el nuevo empleado.
 *
 * @param idStr Recibe el id de tipo string.
 * @param nombreStr Recibe el nombre.
 * @param horasTrabajadasStr Recibe las horas trabajadas de tipo string.
 * @param sueldoStr Recibe el sueldo de tipo string.
 * @return Retorna el empleado cargado si salió bien o NULL si no encontró espacio en memoria.
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);

/**
 * @brief Elimina a un empleado de memoria.
 *
 * @param Recibe el empleado a eliminar.
 */
void employee_delete(Employee*);

/**
 * @brief Guarda el id ingresado en el campo id del empleado.
 *
 * @param this Recibe el empleado.
 * @param id Recibe un puntero al id.
 * @return Retorna -1 si algo salió mal o 0 si todo salió bien.
 */
int employee_setId(Employee* this,int* id);

/**
 * @brief Guarda el id ingresado en el campo id del empleado como string.
 *
 * @param this Recibe el empleado.
 * @param id Recibe un puntero de tipo char al id.
 * @return Retorna -1 si algo salió mal o 0 si todo salió bien.
 */
int employee_setIdChar(Employee* this,char* id);

/**
 * @brief Obtiene el id del empleado.
 *
 * @param this Recibe el empleado.
 * @param id Recibe un puntero al id donde se devolvera por referencia.
 * @return Retorna -1 si algo salió mal o 0 si todo salió bien.
 */
int employee_getId(Employee* this,int* id);

/**
 * @brief Guarda el nombre ingresado en el campo nombre del empleado.
 *
 * @param this Recibe el empleado.
 * @param nombre Recibe el nombre para luego guardarlo en el campo nombre del empleado.
 * @return Retorna -1 si algo salió mal o 0 si todo salió bien.
 */
int employee_setNombre(Employee* this,char* nombre);

/**
 * @brief Obtiene el nombre el nombre del empleado.
 *
 * @param this Recibe el empleado.
 * @param nombre Recibe la variable donde se guardará el nombre del empleado buscado.
 * @return Retorna -1 si algo salió mal o 0 si todo salió bien.
 */
int employee_getNombre(Employee* this,char* nombre);

/**
 * @brief Guarda las horas trabajadas ingresadas en el campo horasTrabajadas del empleado.
 *
 * @param this Recibe el empleado.
 * @param horasTrabajadas Recibe las horas trabajadas que se guardara en el campo horasTrabajadas del empleado.
 * @return Retorna -1 si algo salió mal o 0 si todo salió bien.
 */
int employee_setHorasTrabajadas(Employee* this,int* horasTrabajadas);

/**
 * @brief Guarda las horas trabajadas ingresadas en el campo horasTrabajadas del empleado.
 *
 * @param this Recibe el empleado.
 * @param horasTrabajadas Recibe las horas trabajadas como char y luego lo convierte en flotante.
 * @return Retorna -1 si algo salió mal o 0 si todo salió bien.
 */
int employee_setHorasTrabajadasChar(Employee* this,char* horasTrabajadas);

/**
 * @brief Obtiene las horas trabajadas del empleado.
 *
 * @param this Recibe el empleado.
 * @param horasTrabajadas Recibe el puntero a la variable donde se guardará las horas trabajadas de dicho empleado.
 * @return Retorna -1 si algo salió mal o 0 si todo salió bien.
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/**
 * @brief Guarda el sueldo ingresado en el campo sueldo del empleado.
 *
 * @param this Recibe el empleado.
 * @param sueldo Recibe el sueldo para luego guardarlo en el campo sueldo de dicho empleado.
 * @return Retorna -1 si algo salió mal o 0 si todo salió bien.
 */
int employee_setSueldo(Employee* this,float* sueldo);

/**
 * @brief Guarda el sueldo ingresado en el campo sueldo del empleado.
 *
 * @param this Recibe el empleado.
 * @param sueldo Recibe el sueldo de manera char y luego lo convierte en flotante.
 * @return Retorna -1 si algo salió mal o 0 si todo salió bien.
 */
int employee_setSueldoChar(Employee* this,char* sueldo);

/**
 * @brief Obtiene el sueldo del empleado.
 *
 * @param this Recibe el empleado.
 * @param sueldo Recibe el puntero de la variable donde se va a guardar el sueldo del empleado buscado.
 * @return Retorna -1 si algo salió mal o 0 si todo salió bien.
 */
int employee_getSueldo(Employee* this,float* sueldo);

/**
 * @brief Genera un Id para un empleado.
 *
 * @return Retorna el id.
 */
int employee_GenerarIdEmployee(void);

/**
 * @brief Compara los sueldos de los empleados.
 *
 * @param Recibe un puntero a void para  comparar sueldo de cualquier entidad, en este caso de un empleado1.
 * @param Recibe un puntero a void para  comparar sueldo de cualquier entidad, en este caso de un empleado2.
 * @return Retorna 1 si el sueldo del emplado1 es mayor al empleado2, -1 si es menor y 0 si son iguales.
 */
int employee_CompararPorSueldo(void*,void*);

#endif // employee_H_INCLUDED
