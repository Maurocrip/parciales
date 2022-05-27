/*
 * censistas.h
 *
 *  Created on: 21 may. 2022
 *      Author: Usuario
 */

#ifndef CENSISTAS_H_
#define CENSISTAS_H_

#define NOMBRE 50
#define NUMERO 15

struct
{
	int legajoCensista;
	char nombre[NOMBRE];
	int edad;
	char telefono[NUMERO];
}typedef Censista;

//FUNCIONES

/**
 * @fn int initcensista(Censista*)
 * @brief harcodea los datos de los 3 censistas.
 *
 * @param list: array donde se guardaran a los 3 censistas.
 * @return devuelve -1 si el array es NULL o 0 esta todo ok.
 */
int initcensista(Censista* list);

/**
 * @fn int listadoCensistas(Censista*, int)
 * @brief muestra todos los datos de los censiatas dentro de un array de tipo Censista.
 *
 * @param list: array de tipo Censista.
 * @param tam: tamaño del array.
 * @return retorna (-1) si es error [tamaño incorrecto o puntero NULL] - (0) si salio todo bien.
 */
int listadoCensistas(Censista* list, int tam);

/**
 * @fn int listadoCensista(Censista*, int)
 * @brief muestra los datos de un solo censista.
 *
 * @param list: array de tipo Censista.
 * @param tam: tamaño del array.
 * @return retorna (-1) si es error [tamaño incorrecto o puntero NULL] - (0) si salio todo bien.
 */
int listadoCensista(Censista* list, int indices);

/**
 * @fn int buscarCensista(Censista*, int, int)
 * @brief busca la ubicacion de un censista dentro de un array por si legajo.
 *
 * @param list: array de tipo Censista.
 * @param tam: tamaño del array.
 * @param legajo: legajo del censista que se valla a buscar.
 * @return retorna (-1) si es error [tamaño incorrecto o puntero NULL] - (0) si salio todo bien.
 */
int buscarCensista(Censista* list, int tam,int legajo);


#endif /* CENSISTAS_H_ */
