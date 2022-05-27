/*
 ======================================================================================================================================================
 Name        : Primer parcial: laboratorio y programacion
 Author      : Mauro Racioppi
 DIV	     : D
 Description : Se necesita gestionar el Censo Nacional 2022 y para eso se deberá desarrollar lo siguiente:
 ======================================================================================================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "censistas.h"
#include "validaciones.h"
#include "vivienda.h"

#define CANTIDAD 500
#define CENSISTAS 3

int main(void)
{
	setbuf(stdout, NULL);

	int validacion;
	int respuesta;
	int id;
	Vivienda casas[CANTIDAD];
	Censista sensadores[CENSISTAS];

	id=20000;

	initViviendas(casas,CANTIDAD);
	initcensista(sensadores);

//MENU
	do
	{
		getValidacionMaximoMinimo(&respuesta,"\nIngrese un numero \n"
				" 1. ALTAS\n"
				" 2. MODIFICAR VIVIENDA\n"
				" 3. BAJA VIVIENDA\n"
				" 4. LISTAR VIVENDAS\n"
				" 5. LISTAR CENSISTAS CON VIVIENDAS\n"
				" 6. CENSISTA CON MAS CENSOS REALIZADOS\n"
				" 7. SALIR ", "\nERROR, Reingrese un numero valido(1-7)\n"
					" 1. ALTAS\n"
					" 2. MODIFICAR VIVIENDA\n"
					" 3. BAJA VIVIENDA\n"
					" 4. LISTAR VIVENDAS\n"
					" 5. LISTAR CENSISTAS CON VIVIENDAS\n"
					" 6. CENSISTA CON MAS CENSOS REALIZADOS\n"
					" 7. SALIR ", 1, 7);

		validacion=contadorViviendasRegistradas(casas,CANTIDAD);

//OPCIONES
		switch(respuesta)
			{
				case 1:
					//INGRESO DE VIVIENDA
					id++;
					alta(casas,id,CANTIDAD);
					printf("\nEl ID de esta vivienda es: %d\n", id);
				break;

				case 2:
					//MODIFICA UN PASAJERO
					if(validacion!=0)
					{
						modificacion(casas,CANTIDAD);
					}
					else
					{
						printf("\nNo hay viviendas ingresadas, por favor ingrese una vivienda antes.\n");
					}
				break;

				case 3:
					//ELIMINA UN PASAJERO

					if(validacion!=0)
					{
						baja(casas,CANTIDAD);
					}
					else
					{
						printf("\nNo hay viviendas ingresadas, por favor ingrese una vivienda antes.\n");
					}
				break;

				case 4:
					//LISTADO  DE VIVIENDAS
					if(validacion!=0)
					{
						ordenamientoViviendas(casas,CANTIDAD);
						listadoVivienda(casas,CANTIDAD);
					}
					else
					{
						printf("\nNo hay viviendas ingresadas, por favor ingrese una vivienda antes.\n");
					}
				break;

				case 5:
					//LISTADO  DE CENSISTAS
					if(validacion!=0)
					{
						censistaPorVivienda(casas,CANTIDAD,sensadores, CENSISTAS);
					}
					else
					{
						printf("\nNo hay viviendas ingresadas, por favor ingrese una vivienda antes.\n");
					}
				break;

				case 6:
					//LISTADO  DE CENSISTAS
					if(validacion!=0)
					{
						censistaConMasViviendas(casas,CANTIDAD);
					}
					else
					{
						printf("\nNo hay viviendas ingresadas, por favor ingrese una vivienda antes.\n");
					}
				break;
			}

	}while(respuesta!=7);

	return 0;
}


