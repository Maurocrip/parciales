
/**
 * @fn int parser_PassengerFromText(FILE*, LinkedList*)
 * @brief lee los datos de un archivo y luego los guarda en una linkedlist.
 *
 * @param pFile: un puntero al archivo.
 * @param pArrayListPassenger: puntero a la linkedlist.
 * @return devuelve 0 si el puntero a la linkedlist viene en NULL, sino devuelve la cantidad servicios guardados en la linkedist.
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListServicios);

