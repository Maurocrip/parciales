/*
 * vivienda.c
 *
 *  Created on: 21 may. 2022
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vivienda.h"
#include "validaciones.h"
#include <ctype.h>


int initViviendas(Vivienda* list, int tam)
{
	int i;
	int devuelve;

	devuelve=-1;

	if(list != NULL && tam>0)
	{
		for(i=0;i<tam;i++)
		{
			(*(list+i)).idVivienda =1;
		}
		devuelve=0;
	}
	return devuelve;
}

void alta(Vivienda* persona, int id, int tam)
{
	int validacion;
	if(persona != NULL && tam>0)
	{
		validacion=buscarVivienda(persona, tam, 1);
		if(validacion!=-1)
		{
			(persona+validacion)->idVivienda=id;
			UTN_GetValor((*(persona+validacion)).calle, NOMBRE, "\ningrese la calle: ", "ERROR, la calle tiene mas de 50 digitos o contiene algun numero.\n"
					"Por favor ingrese la calle nuevamente: ",0);
			convertirPalabraAMinusculas((*(persona+validacion)).calle,NOMBRE);
			getValidacionMaximoMinimo(&(persona+validacion)->legajoCensista.legajoCensista, "ingrese el legajo del censista(100-Ana, 101-Juan o 102-Sol): ", "ERROR, no ah ingresado el legajo correcto.\n"
									"Por favor ingrese el legajo del sencista nuevamente (100-Ana, 101-Juan o 102-Sol): ",100,102);
			UTN_getValidacionMayorInt(&(persona+validacion)->cantidadPersonas,"ingrese la cantidad de personas que viven en la casa: ",
					"ERROR, reingrese  la cantidad de personas que viven en la casa(numero mayor a 0): ", 1);
			UTN_getValidacionMayorInt(&(persona+validacion)->cantidadHabitaciones, "ingrese la cantidad de habitaciones que hay en la casa: ",
					"ERROR, reingrese  la cantidad de habitaciones que hay en la casa:(numero mayor a 0):",1);
			getValidacionMaximoMinimo(&(persona+validacion)->tipoVivienda, "ingrese el tipo de vivienda(1.CASA – 2.DEPARTAMENTO – 3.CASILLA - 4.RANCHO): ",
					"ERROR, el tipo de vivienda ingresa es incorrecto.\nPor favor ingrese solo el numero correspondiente al tipo de vivienda (1.CASA – 2.DEPARTAMENTO – 3.CASILLA - 4.RANCHO): ",1,4);
		}
		else
		{
			printf("\nNo se ah encontrado un espacio disponible\n");
		}
	}
}

int buscarVivienda(Vivienda* list, int tam,int id)
{
	int i;
	int devuelve;

	devuelve=-1;

	if(list != NULL && tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if(list[i].idVivienda == id)
			{
				devuelve=i;
				break;
			}
		}
	}
	return devuelve;
}

void modificacion(Vivienda* lista, int tam)
{
	int idBuscar;
	int validar;
	int opcion;

	UTN_getValidacionMayorInt(&idBuscar, "ingrese el ID de la vivienda que desea modificar: ", "ERROR, ingrese un ID valido(numero mayor a 20000): ",20000);
	validar=buscarVivienda(lista,tam,idBuscar);
	if(validar!=-1)
	{
		do
		{
			getValidacionMaximoMinimo(&opcion,"\nIngrese un numero \n"
					" 1. Modifica calle\n"
					" 2. Modifica cantidad de personas\n"
					" 3. Modifica cantidad de habitaciones\n"
					" 4. Modifica tipo de vivienda\n"
					" 5. SALIR ", "\nERROR, Reingrese un numero valido(1-5)\n"
						" 1. Modifica calle\n"
						" 2. Modifica cantidad de personas\n"
						" 3. Modifica cantidad de habitaciones\n"
						" 4. Modifica tipo de vivienda\n"
						" 5. SALIR ", 1, 5);
			switch(opcion)
			{
				case 1:
					modificarCalle(lista,validar);
				break;

				case 2:
					modificarCantidadPersonas(lista,validar);
				break;

				case 3:
					modificarCantidadHabitaciones(lista,validar);
				break;

				case 4:
					modificarTipoVivienda(lista,validar);
				break;
			}
		}while(opcion!=5);
	}
	else
	{
		printf("\nERROR, el ID %d no se encuentra en la lista\n", idBuscar);
	}
}

void modificarCalle(Vivienda* guardar, int indice)
{
	int validarChar;
	validarChar=UTN_GetValor((*(guardar+indice)).calle, NOMBRE, "Ingrese el nombre de la calle: ", "ERROR, el nombre de la calle tiene mas de 50 digitos o contiene algun numero.\n"
				"Por favor ingrese el nombre de la calle nuevamente: ",0);
	if(validarChar==0)
	{
		printf("\nel nombre de la calle se ah cambiado por %s\n", (guardar+indice)->calle);
	}
	else
	{
		printf("\nERROR, no se ah podido cambiar el nombre de la calle\n");
	}
}

void modificarTipoVivienda(Vivienda* guardar, int indice)
{
	getValidacionMaximoMinimo(&(guardar+indice)->tipoVivienda, "ingrese el tipo de vivienda(1.CASA – 2.DEPARTAMENTO – 3.CASILLA - 4.RANCHO): ",
						"ERROR, el tipo de vivienda ingresado es incorrecto.\nPor favor ingrese solo el numero correspondiente al tipo de vivienda (1.CASA – 2.DEPARTAMENTO – 3.CASILLA - 4.RANCHO): ",1,4);
	printf("\nel tipo de vivienda se ah cambiado\n");
}

void modificarCantidadPersonas(Vivienda* guardar, int indice)
{
	UTN_getValidacionMayorInt(&(guardar+indice)->cantidadPersonas,"ingrese la cantidad de personas que viven en la casa: ",
						"ERROR, reingrese  la cantidad de personas que viven en la casa(numero mayor a 0): ", 1);
	printf("\nLa cantidad de personas se ah cambiado a: %d\n", (guardar+indice)->cantidadPersonas);
}

void modificarCantidadHabitaciones(Vivienda* guardar, int indice)
{
	UTN_getValidacionMayorInt(&(guardar+indice)->cantidadHabitaciones,"ingrese la cantidad de habitaciones que hay en la casa: ",
						"ERROR, reingrese la cantidad de habitaciones que hay en la casa:(numero mayor a 0):",1);
		printf("\nLa cantidad de habitaciones que hay en la casa se ah cambiado a: %d\n", (guardar+indice)->cantidadHabitaciones);
}

void baja(Vivienda* lista, int tam)
{
	int idBuscar;
	int validar;

	UTN_getValidacionMayorInt(&idBuscar, "ingrese el ID del pasajero que desea dar de baja: ", "ERROR, ingrese un ID valido(numero mayor a 20000): ",20000);
	validar=buscarVivienda(lista,tam,idBuscar);
	if(validar!=-1)
	{
		(lista+validar)->idVivienda=1;
		printf("\nEl ID %d se ah eliminado correctamente\n", idBuscar);
	}
	else
	{
		printf("\nERROR, el ID %d no se encuentra en la lista\n", idBuscar);
	}
}

int ordenamientoViviendas(Vivienda* list, int tam)
{
	int i;
	int j;
	int devuelve;
	Vivienda guardado;

	devuelve=-1;

	if(list != NULL && tam>0)
	{
		devuelve=0;
		for(i=0;i<tam;i++)
		{
			for(j=i+1;j<tam-1;j++)
			{
				if((list+i)->idVivienda>20000 && (list+j)->idVivienda>20000)
				{
					if(strcmp((list+i)->calle,(list+j)->calle)!=-1)
					{
						guardado=list[j];
						list[j]=list[i];
						list[i]=guardado;
					}
					else
					{
						if(strcmp((list+i)->calle,(list+j)->calle)!=0 && (list+i)->cantidadPersonas>(list+j)->cantidadPersonas)
						{
							guardado=list[j];
							list[j]=list[i];
							list[i]=guardado;
						}
					}
				}
			}
		 }
	}

	return devuelve;
}

int listadoVivienda(Vivienda* list, int tam)
{
	int i;
	int respuesta;

	respuesta=-1;

	if(list != NULL && tam>0)
	{
		for(i=0;i<tam;i++)
		{
			if((list+i)->idVivienda>20000)
			{
				printf("\ncalle: %s\nCantidad Personas: %d\nCantidad de Habitaciones: %d\nID: %d\nTipo de Vivienda: %d\nlegajo sencista: %d\n",
						(list+i)->calle, (list+i)->cantidadPersonas, (list+i)->cantidadHabitaciones, (list+i)->idVivienda, (list+i)->tipoVivienda, (list+i)->legajoCensista.legajoCensista);
				respuesta=0;
			}

		}
	}
	return respuesta;
}

int contadorViviendasRegistradas(Vivienda* list, int tam)
{
	int i;
	int respuesta;

	respuesta=-1;

	if(list != NULL && tam>0)
	{
		respuesta=0;
		for(i=0;i<tam;i++)
		{
			if((list+i)->idVivienda>20000)
			{
				respuesta++;
			}

		}
	}
	return respuesta;
}

void convertirPalabraAMinusculas(char* comprobar, int tam)
{
	int i;

	if(comprobar != NULL)
	{
		for(i=0;i<tam;i++)
		{
			*(comprobar+i)=tolower(*(comprobar+i));
		}
	}
}
