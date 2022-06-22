/*
 * vivienda.h
 *
 *  Created on: 21 may. 2022
 *      Author: Usuario
 */

#include "censistas.h"

#ifndef VIVIENDA_H_
#define VIVIENDA_H_

struct
{
	int idVivienda;
	char calle[NOMBRE];
	Censista legajoCensista;
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;
}typedef Vivienda;


//FUNCIONES
/**
* @fn int initViviendas(Vivienda*, int);
* @brief Inicializa el ID de las viviendas en 1.
*
* @param list Vivienda*: Puntero del array de la estructura de vivienda.
* @param tam int: tamaño del array.
* @return int retorna (-1) si es error [tamaño incorrecto o puntero NULL] - (0) si salio todo bien.
*/
int initViviendas(Vivienda* list, int tam);

/**
 * @fn void alta(Vivienda*, int, int)
 * @brief permite el ingreso de los datos de una nueva vivienda y la registra.
 *
 * @param persona: array donde se guardaran los datos de la vivienda ingresada.
 * @param id: id de la vivienda.
 * @param tam: el tamaño del array.
 */
void alta(Vivienda* persona, int id, int tam);

/**
 * @fn int buscarVivienda(Vivienda*, int, int)
 * @brief busca una vivienda segun su id.
 *
 * @param list: array de tipo vivienda donde se va a buscar.
 * @param tam: tamaño del array.
 * @param id: ID de la vivienda que se desea buscar.
 * @return devuelve el indice donde esta ubicada la vivienda.
 */
int buscarVivienda(Vivienda* list, int tam,int id);

/**
 * @fn void modificacion(Vivienda*, int)
 * @brief Busca una vivinda por su ID y si este esta guardado en el array, le permite luego al usuario modificar:
 * la calle, la cantidad de personas, la cantidad de habitaciones y el tipo de vivienda.
 *
 * @param list: array de tipo vivienda donde se va a buscar.
 * @param tam: tamaño del array.
 */
void modificacion(Vivienda* lista, int tam);

/**
 * @fn void modificarCalle(Vivienda*, int)
 * @brief le permite al usuario modificar la calle de una vivienda.
 *
 * @param guardar: array de tipo vivienda donde se encuentra la vivienda que se valla a modificar.
 * @param indice: el indice donde se encuentra la vivienda en el array.
 */
void modificarCalle(Vivienda* guardar, int indice);

/**
 * @fn void modificarTipoVivienda(Vivienda*, int)
 * @brief le permite al usuario modificar el tipo de vivienda de una vivienda.
 *
 * @param guardar: array de tipo vivienda donde se encuentra la vivienda que se valla a modificar.
 * @param indice: el indice donde se encuentra la vivienda en el array.
 */
void modificarTipoVivienda(Vivienda* guardar, int indice);

/**
 * @fn void modificarCantidadPersonas(Vivienda*, int)
 * @brief le permite al usuario modificar la cantidad de personas de una vivienda.
 *
 * @param guardar: array de tipo vivienda donde se encuentra la vivienda que se valla a modificar.
 * @param indice: el indice donde se encuentra la vivienda en el array.
 */
void modificarCantidadPersonas(Vivienda* guardar, int indice);

/**
 * @fn void modificarCantidadHabitaciones(Vivienda*, int)
 * @brief le permite al usuario modificar la cantidad de habitaciones de una vivienda.
 *
 * @param guardar: array de tipo vivienda donde se encuentra la vivienda que se valla a modificar.
 * @param indice: el indice donde se encuentra la vivienda en el array.
 */
void modificarCantidadHabitaciones(Vivienda* guardar, int indice);

/**
 * @fn void baja(Vivienda*, int)
 * @brief le permite al usuario der de baja/eliminar una vivienda ya ingresada a traves de su ID.
 *
 * @param list: array de tipo vivienda donde se va a buscar.
 * @param tam: tamaño del array.
 */
void baja(Vivienda* lista, int tam);

/**
 * @fn int ordenamientoViviendas(Vivienda*, int)
 * @brief ordena un aray de tipo vivienda de manera alfabetica segun el nombre de la calle.
 * En casa de que el nombre sea el msimo, se ordena por la cantidad de personas de manera acendente.
 *
 * @param list: array de tipo vivienda que se valla a ordenar.
 * @param tam: tamaño del array.
 * @return retorna (-1) si es error [tamaño incorrecto o puntero NULL] - (0) si salio todo bien.
 */
int ordenamientoViviendas(Vivienda* list, int tam);

/**
 * @fn int listadoVivienda(Vivienda*, int)
 * @brief muestra todos los elementos de un array de tipo vivienda, cullas ID sean mayorers a 20000.
 *
 * @param list: array de tipo vivienda que se valla a listar.
 * @param tam: tamaño del array.
 * @return retorna (-1) si es error [tamaño incorrecto o puntero NULL] - (0) si salio todo bien.
 */
int listadoVivienda(Vivienda* list, int tam);

/**
 * @fn int contadorViviendasRegistradas(Vivienda*, int)
 * @brief cualcula la cantidad de viviendas que se ingresaron verificando si su ID es mayor a 20000.
 *
 * @param list: array de tipo vivienda donde se cuente la cantidad de viviendas registradas que hay.
 * @param tam: tamaño del array.
 * @return retorna (-1) si es error [tamaño incorrecto o puntero NULL] - la cantidad de viviendas registradas.
 */
int contadorViviendasRegistradas(Vivienda* list, int tam);

/**
 * @fn int ordenamientoPorCensista(Vivienda*, int)
 * @brief ordena un array de tipo vivienda segun el legajo del censista.
 *
 * @param list: array de tipo vivienda que se valla a ordenar.
 * @param tam: tamaño del array.
 * @return retorna (-1) si es error [tamaño incorrecto o puntero NULL] - 0 si salio todo bien.
 */
int ordenamientoPorCensista(Vivienda* list, int tam);

/**
 * @fn int censistaPorVivienda(Vivienda*, int, Censista*, int)
 * @brief Muestra los datos de cada censista juntos con los datos de las vivienda que censo.
 *
 * @param list: array de tipo vivienda.
 * @param tam: tamaño del array.
 * @param censista: array de tipo censista.
 * @param tamCensista: tamaño del array de tipo censista.
 * @return retorna (-1) si es error [tamaño incorrecto o puntero NULL] - 0 si salio todo bien.
 */
int censistaPorVivienda(Vivienda* list, int tam,Censista* censista, int tamCensista);

/**
 * @fn int censistaConMasViviendas(Vivienda*, int)
 * @brief calcula cual es el censista con mas viviendas censadas.
 *
 * @param list: array de tipo Censista.
 * @param tam: tamaño del array.
 * @return retorna (-1) si es error [tamaño incorrecto o puntero NULL] - 0 si salio todo bien.
 */
int censistaConMasViviendas(Vivienda* list, int tam);


//FUNCIONES AUXILIARES
/**
 * @fn void convertirPalabraAMinusculas(char*, int)
 * @brief convierte todos los caracterers de un array de tipo char a minuscula.
 *
 * @param comprobar: array de tipo char.
 * @param tam: tamño del array.
 */
void convertirPalabraAMinusculas(char* comprobar, int tam);



#endif /* VIVIENDA_H_ */
