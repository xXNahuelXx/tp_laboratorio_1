/**
 * @brief Abre el archivo y se encarga de llamar a la funcion parser from text.
 *
 * @param path Recibe la ruta del archivo.
 * @param pArrayListEmployee Recibe la lista de empleados.
 * @return Retorna -1 si hubo algun error o 0 si todo está bien.
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/**
 * @brief Abre el archivo y se encarga de llamar a la funcion parser from binary.
 *
 * @param path Recibe la ruta del archivo.
 * @param pArrayListEmployee Recibe la lista de empleados.
 * @return Retorna -1 si hubo algun error o 0 si todo está bien.
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/**
 * @brief Se encarga de agregar un empleado a la lista.
 *
 * @param pArrayListEmployee Recibe la lista de empleados.
 * @return Retorna -1 si hubo error o 0 si salió todo bien.
 */
int controller_addEmployee(LinkedList* pArrayListEmployee);

/**
 * @brief Se encarga de editar los datos de un empleado.
 *
 * @param pArrayListEmployee Recibe la lista de empleados.
 * @return Retorna -1 si hubo error, 1 si no se hicieron cambios y 0 si se modificó correctamente.
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/**
 * @brief Se encarga de eliminar un empleado.
 *
 * @param pArrayListEmployee Recibe la lista de empleados.
 * @return Retorna -1 si hubo error o 0 si salió todo bien.
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/**
 * @brief Se encarga de listar todos los empleados que contiene la lista.
 *
 * @param pArrayListEmployee Recibe la lista de empleados.
 * @return Retorna -1 si hubo error o 0 si salió todo bien.
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/**
 * @brief Se encarga de llamar al ll_sort que ordena los empleados.
 *
 * @param pArrayListEmployee Recibe la lista de empleados.
 * @return Retorna -1 si hubo error o 0 si salió todo bien.
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/**
 * @brief Se engarga de guardar lo que hicimos en modo texto.
 *
 * @param path Recibe la ruta del archivo que va a guardar.
 * @param pArrayListEmployee Recibe la lista de empleados.
 * @return Retorna -1 si hubo error o 0 si salió todo bien.
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/**
 * @brief Se engarga de guardar lo que hicimos en modo binario.
 *
 * @param path Recibe la ruta del archivo que va a guardar.
 * @param pArrayListEmployee Recibe la lista de empleados.
 * @return Retorna -1 si hubo error o 0 si salió todo bien.
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

/**
 * @brief Se encarga de buscar un empleado por Id.
 *
 * @param pArrayListEmployee Recibe la lista de empleados.
 * @param id Recibe el id ingresado a buscar.
 * @param pIndex Recibe el puntero de la variable donde se va a guardar el indice del empleado encontrado.
 * @return Retorna -1 si hubo error o 0 si salió todo bien.
 */
int controller_BuscarPorIdEmployee(LinkedList* pArrayListEmployee,int id,int* pIndex);


