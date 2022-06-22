#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "servicios.h"


int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	eServicios* pServicio;
	int r;
	int devuelve;
	char id[50],descripcion[50],tipo[50],precioUnitario[50],cantidad[50],servicioTotal[50];

	devuelve=0;

	if(pArrayListPassenger!=NULL)
	{
		r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",id,descripcion,tipo,precioUnitario,cantidad,servicioTotal);

		while(!feof(pFile))
		{
			r=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]",id,descripcion,tipo,precioUnitario,cantidad,servicioTotal);
			if(r!=6)
			{
				break;
			}

			pServicio=Servicios_newParametros(id,descripcion,tipo,precioUnitario,cantidad,servicioTotal);
			devuelve++;

			ll_add(pArrayListPassenger,pServicio);
		}
	}

	return devuelve;
}
