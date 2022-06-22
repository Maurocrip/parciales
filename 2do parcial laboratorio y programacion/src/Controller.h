/*
 * Controller.h
 *
 *  Created on: 21 jun. 2022
 *      Author: Usuario
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

//-------------------------------------------FUNCIONES PARA CARGAR DATOS DEL ARCHIVO DATA.CSV--------------------------------------------
/**
 * @fn int controller_loadFromText(char*, LinkedList*)
 * @brief controla la lectura del archivo data.csv y guarda su informacion en la linkedlist
 *
 * @param path: nombre del archivo.
 * @param pArrayListServicios: puntero a la linkedlist.
 * @return devuelve 0 si el array de char o el puntero a la linkedlist viene en NULL, sino devuelve 1.
 */
int controller_loadFromText(char* path , LinkedList* pArrayListServicios);

//------------------------------------------FIN FUNCIONES PARA CARGAR DATOS DEL ARCHIVO DATA.CSV-----------------------------------------


/**
 * @fn int controller_ListServicios(LinkedList*)
 * @brief controla el listado de todos los servicios que hay en un linkedlist.
 *
 * @param pArrayListServicios: puntero al linkedlist el cual se queira mostrar sus elementos.
 * @return devuelve 0 si el puntero a la linkedlist viene en NULL, sino devuelve 1.
 */
int controller_ListServicios(LinkedList* pArrayListServicios);

/**
 * @fn int controller_AsignacionTotalServicio(LinkedList*)
 * @brief controla que en el campo "totalServicio" de todos los elementos de tipo eServicios de una linkedlist sean calculados.
 *
 * @param pArrayListServicios: puntero a la linkedlist.
 * @return devuelve 0 si el puntero a la linkedlist viene en NULL, sino devuelve 1.
 */
int controller_AsignacionTotalServicio(LinkedList* pArrayListServicios);

/**
 * @fn int controller_FiltrarServicios(LinkedList*)
 * @brief crea una nueva linkedlist y controla que en esta se guarden solo los servicios filtrados segun el tipo de servicio.
 * Luego guarda la linkedlist en un archivo.
 *
 * @param pArrayListServicios: puntero a la linkedlist.
 * @return devuelve 0 si el puntero a la linkedlist viene en NULL o si no se pudo guardar el archivo, sino devuelve 1.
 */
int controller_FiltrarServicios(LinkedList* pArrayListServicios);

/**
 * @fn int controller_sortServicios(LinkedList*)
 * @brief controla que se realice el ordenamiento de manera acendente segun el campo descripcion en todos los tipo eServicios
 * de una linkedlist, luego muestra toda la lista completa.
 *
 * @param pArrayListServicios: puntero a la linkedlist.
 * @return devuelve 0 si el puntero a la linkedlist viene en NULL, sino devuelve 1.
 */
int controller_sortServicios(LinkedList* pArrayListServicios);


//-------------------------------------------FUNCIONES PARA GUARDAR DATOS DEL ARCHIVO DATA.CSV-------------------------------------------


/**
 * @fn int controller_saveAsText(char*, LinkedList*)
 * @brief controla que guarde en un archivo los datos de una linkedlist.
 *
 * @param path: nombre del archivo donde se guardaran los datos.
 * @param pArrayListServicios: puntero a la linkedlist.
 * @return devuelve 0 si el array de char o el puntero a la linkedlist viene en NULL, sino devuelve 1.
 */
int controller_saveAsText(char* path , LinkedList* pArrayListServicios);

//---------------------------------------FIN FUNCIONES PARA GUARDAR DATOS DEL ARCHIVO DATA.CSV-------------------------------------------



#endif /* CONTROLLER_H_ */
