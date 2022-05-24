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


int listadoCensistas(Censista* list, int length);


#endif /* CENSISTAS_H_ */
