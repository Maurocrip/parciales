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

void modificacion(Vivienda* lista, int tam);

void modificarCalle(Vivienda* guardar, int tam, int indice);
void modificarTipoVivienda(Vivienda* guardar, int tam, int indice);
void modificarCantidadPersonas(Vivienda* guardar, int tam, int indice);
void modificarCantidadHabitaciones(Vivienda* guardar, int tam, int indice);
void baja(Vivienda* lista, int tam);
int ordenamientoViviendas(Vivienda* list, int len);
int listadoVivienda(Vivienda* list, int tam);
int contadorViviendasRegistradas(Vivienda* list, int tam);

void convertirPalabraAMinusculas(char* comprobar, int tam);



#endif /* VIVIENDA_H_ */
