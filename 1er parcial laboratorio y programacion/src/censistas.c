/*
 * censistas.c
 *
 *  Created on: 21 may. 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "censistas.h"

int initcensista(Censista* list)
{
	int devuelve;

	devuelve=-1;

	if(list != NULL)
	{
		(*(list+0)).edad =34;
		(*(list+0)).legajoCensista=100;
		strcpy((*(list+0)).nombre,"Ana");
		strcpy((*(list+0)).telefono,"1203-2345");

		(*(list+1)).edad =24;
		(*(list+1)).legajoCensista=101;
		strcpy((*(list+1)).nombre,"Juan");
		strcpy((*(list+1)).telefono,"4301-54678");

		(*(list+2)).edad =47;
		(*(list+2)).legajoCensista=102;
		strcpy((*(list+2)).nombre,"Sol");
		strcpy((*(list+2)).telefono,"5902-37487");
		devuelve=0;
	}
	return devuelve;
}

int listadoCensistas(Censista* list, int tam)
{
	int i;
	int respuesta;

	respuesta=-1;

	if(list != NULL)
	{
		for(i=0;i<tam;i++)
		{
			printf("\nlegajoCensista: %d\nNombre: %s\nTelefono: %s\nEdad: %d\n",
				list[i].legajoCensista, list[i].nombre, list[i].telefono, list[i].edad);
			respuesta=0;
		}
	}
	return respuesta;
}
