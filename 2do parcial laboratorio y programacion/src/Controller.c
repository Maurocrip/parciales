#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "servicios.h"
#include "UTN.h"

//-------------------------------------------FUNCIONES PARA CARGAR DATOS DEL ARCHIVO DATA.CSV------------------------------------------------------------------------------------------------------

int controller_loadFromText(char* path,LinkedList* pArrayListServicios)
{
	int devuelve;
	devuelve=0;

	if(pArrayListServicios!=NULL && path!=NULL)
	{
		FILE* pArchivo;
		int chequeo;
		int flag;
		char archivo[50];

		flag=0;

		do
		{
			if(flag==1)
			{
				printf("\nERROR, no existe archivo con ese nombre\n");
			}
			flag=1;
			UTN_GetValor(archivo, 50,"\nIngrese el nombre del archivo( data.csv ): ",
				"\nERROR, el nombre no puede contener numeros o excederse de los 50 caracteres\nIngrese el nombre del archivo( data.csv ): ",0);
		}while(strcmp(archivo,path)!=0);

		pArchivo=fopen(path,"r");
		if(pArchivo==NULL)
		{
			printf("\nEl archivo no se pudo abrir\n");
			exit (1);
		}

		chequeo=parser_PassengerFromText(pArchivo,pArrayListServicios);
		if(chequeo == ll_len(pArrayListServicios))
		{
			printf("\nEl archivo se ah cargado correctamente\n");
		}
		else
		{
			printf("\nHubo un problema al cargar el archivo\n");
			exit(1);
		}
		fclose(pArchivo);
		devuelve=1;
	}

    return devuelve;
}

//--------------------------------------------------------------------FIN FUNCIONES PARA CARGAR DATOS DEL ARCHIVO DATA.CSV------------------------------------------------------------------------

int controller_ListServicios(LinkedList* pArrayListServicios)
{
	int devuelve;
	devuelve=0;
	if(pArrayListServicios!=NULL)
	{
		devuelve=1;
		mostrarTodosLosServicio(pArrayListServicios);
	}
    return devuelve;
}

int controller_AsignacionTotalServicio(LinkedList* pArrayListServicios)
{
	int devuelve;
	devuelve=0;
	if(pArrayListServicios!=NULL)
	{
		void (*pF)(void*);

		pF=calcularPrecioFinal;

		ll_map(pArrayListServicios,pF);

		devuelve=1;
	}
    return devuelve;
}

int controller_FiltrarServicios(LinkedList* pArrayListServicios)
{
	int devuelve;
	devuelve=0;
	if(pArrayListServicios!=NULL)
	{
		int opcionTipo;
		LinkedList* listaServiciosFiltrados;
		FILE* pArchivo;
		int (*pFTipoServicio)(void* p);

		listaServiciosFiltrados=NULL;

		do
		{
			UTN_getValidacionMaximoMinimo(&opcionTipo,"\nPor que tipo desea filtrar la lista?\n"
					"\n1-MINORISTA\n2-MAYORISTA\n3-EXPORTAR\n4-SALIR ",
								"\nPor que tipo desea filtrar la lista?\n\n1-MINORISTA\n2-MAYORISTA\n3-EXPORTAR\n4-SALIR ", 1, 4);
			if(opcionTipo!=4)
			{
				switch(opcionTipo)
				{
					case 1:
						pFTipoServicio=filtrarPorMinorista;
					break;

					case 2:
						pFTipoServicio=filtrarPorMayoristas;
					break;

					case 3:
						pFTipoServicio=filtrarPorExportar;
					break;
				}
				listaServiciosFiltrados=ll_filter(pArrayListServicios,pFTipoServicio);
				mostrarTodosLosServicio(listaServiciosFiltrados);
			}
		}while(opcionTipo!=4);

		//GUARDADO AL ARCHIVO
		pArchivo=fopen("Lista_Filtrada.csv","w");
		if(pArchivo==NULL)
		{
			printf("\nEl archivo no se pudo abrir\n");
			exit (1);
		}

		devuelve=saveServicioFiltradoArchivo(pArchivo,listaServiciosFiltrados);
		fclose(pArchivo);
		ll_deleteLinkedList(listaServiciosFiltrados);
	}
	return devuelve;
}

int controller_sortServicios(LinkedList* pArrayListServicios)
{
	int devuelve;

	devuelve=0;
	if(pArrayListServicios!=NULL)
	{
		int chequeo;
		int (*pF)(void*, void*);
		pF=compararDescripcionServicios;

		chequeo=ll_sort(pArrayListServicios,pF,1);
		if(chequeo==0)
		{
			mostrarTodosLosServicio(pArrayListServicios);
		}
		else
		{
			printf("\nNo se ah podido ordenar la lista\n");
		}
		devuelve=1;
	}
	return devuelve;

}

//-------------------------------------------FUNCIONES PARA GUARDAR DATOS DEL ARCHIVO DATA.CSV-----------------------------------------------------------------------------------------------------


int controller_saveAsText(char* path , LinkedList* pArrayListServicios)
{
	int devuelve;
	devuelve=0;
	if(path!=NULL && pArrayListServicios!=NULL)
	{
		FILE* pArchivo;
		pArchivo=fopen(path,"w");
		if(pArchivo==NULL)
		{
			printf("\nEl archivo no se pudo abrir\n");
			exit (1);
		}

		devuelve=saveServicioFiltradoArchivo(pArchivo,pArrayListServicios);
		fclose(pArchivo);
	}

	return devuelve;
}

//--------------------------------------------------------------------FIN FUNCIONES PARA GUARDAR DATOS DEL ARCHIVO DATA.CSV------------------------------------------------------------------------
