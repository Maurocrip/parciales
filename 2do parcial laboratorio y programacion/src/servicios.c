/*
 * servicios.c
 *
 *  Created on: 21 jun. 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "LinkedList.h"
#include "servicios.h"
#include "UTN.h"

eServicios* Servicios_new()
{
	eServicios* pAux= (eServicios*) malloc(sizeof(eServicios));
	if(pAux==NULL)
	{
		printf("\nNo se pudo crear un nuevo servicio\n");
		exit(1);
	}
	return pAux;
}

eServicios* Servicios_newParametros(char* idStr,char* descripcionStr,char* tipoServicioStr,char* precioUnitarioStr,char* cantidadStr, char* servicioTotalStr)
{
	eServicios* pAux=Servicios_new();

	Servicios_setId(pAux,atoi(idStr));
	Servicios_setDescripcion(pAux,descripcionStr);
	Servicios_setPrecioUnitario(pAux,atof(precioUnitarioStr));
	Servicios_setTipo(pAux,atoi(tipoServicioStr));
	Servicios_setCantidad(pAux,atoi(cantidadStr));
	Servicios_setServicioTotal(pAux,atof(servicioTotalStr));
	return pAux;
}

//---------------------------------------------------------FUNCIONES GET AND SET-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


int Servicios_setId(eServicios* this,int id)
{
	int devuelve=0;
	if(this!=NULL)
	{
		devuelve=1;
		this->id_servicio=id;
	}
	return devuelve;
}

int Servicios_getId(eServicios* this,int* id)
{
	int devuelve=0;
	if(this!=NULL && id!=NULL)
	{
		devuelve=1;
		*id=this->id_servicio;
	}
	return devuelve;
}

int Servicios_setDescripcion(eServicios* this,char* descripcion)
{
	int devuelve=0;
	if(this!=NULL)
	{
		devuelve=1;
		strcpy(this->descripcion,descripcion);
	}
	return devuelve;
}

int Servicios_getDescripcion(eServicios* this,char* descripcion)
{
	int devuelve=0;
	if(this!=NULL && descripcion!=NULL)
	{
		devuelve=1;
		strcpy(descripcion,this->descripcion);
	}
	return devuelve;
}


int Servicios_setTipo(eServicios* this,int tipoServicio)
{
	int devuelve=0;
	if(this!=NULL)
	{
		devuelve=1;
		this->tipo=tipoServicio;
	}
	return devuelve;
}

int Servicios_getTipo(eServicios* this,int* tipoServicio)
{
	int devuelve=0;
	if(this!=NULL && tipoServicio!=NULL)
	{
		devuelve=1;
		*tipoServicio=this->tipo;
	}
	return devuelve;
}

int Servicios_setPrecioUnitario(eServicios* this,float precio)
{
	int devuelve=0;
	if(this!=NULL)
	{
		devuelve=1;
		this->precioUnitario=precio;
	}
	return devuelve;
}

int Servicios_getPrecioUnitario(eServicios* this,float* precio)
{
	int devuelve=0;
	if(this!=NULL && precio!=NULL)
	{
		devuelve=1;
		*precio=this->precioUnitario;
	}
	return devuelve;
}

int Servicios_setCantidad(eServicios* this,int cantidad)
{
	int devuelve=0;
	if(this!=NULL)
	{
		devuelve=1;
		this->cantidad=cantidad;
	}
	return devuelve;
}

int Servicios_getCantidad(eServicios* this,int* cantidad)
{
	int devuelve=0;
	if(this!=NULL && cantidad!=NULL)
	{
		devuelve=1;
		*cantidad=this->cantidad;
	}
	return devuelve;
}

int Servicios_setServicioTotal(eServicios* this,float servicioTotal)
{
	int devuelve=0;
	if(this!=NULL)
	{
		devuelve=1;
		this->totalServicio=servicioTotal;
	}
	return devuelve;
}

int Servicios_getServicioTotal(eServicios* this,float* servicioTotal)
{
	int devuelve=0;
	if(this!=NULL && servicioTotal!=NULL)
	{
		devuelve=1;
		*servicioTotal=this->totalServicio;
	}
	return devuelve;
}

//--------------------------------------------------------------------FIN FUNCIONES GET AND SET--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//---------------------------------------------------------FUNCIONES PARA FILTRAR----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int filtrarPorMinorista(void* elemento)
{
	int devuelve;

	devuelve=0;
	if(elemento != NULL)
	{
		eServicios* p;
		p=(eServicios*) elemento;
		if(p->tipo==1)
		{
			devuelve=1;
		}
	}
	 return devuelve;
}

int filtrarPorMayoristas(void* elemento)
{
	int devuelve;

	devuelve=0;
	if(elemento != NULL)
	{
		eServicios* p;
		p=(eServicios*) elemento;
		if(p->tipo==2)
		{
			devuelve=1;
		}
	}
	 return devuelve;
}

int filtrarPorExportar(void* elemento)
{
	int devuelve;

	devuelve=0;
	if(elemento != NULL)
	{
		eServicios* p;
		p=(eServicios*) elemento;
		if(p->tipo==3)
		{
			devuelve=1;
		}
	}
	 return devuelve;
}


//-----------------------------------------------------------FIN FUNCIONES PARA FILTRAR----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//---------------------------------------------------------FUNCIONES PARA MOSTRAR----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int mostrarServicio(eServicios* servicio)
{
	int devuelve;
	devuelve=0;
	if(servicio!=NULL)
	{
		devuelve=1;
		printf("|%*d|%*s|%*.2f|%*d|%*d|%*.2f|\n"
			,-CANTIDAD_ESPACIOS_ID,servicio->id_servicio,-CANTIDAD_ESPACIOS_DESCRIPCION,servicio->descripcion,-CANTIDAD_ESPACIOS_PRECIO_UNITARIO,servicio->precioUnitario,-CANTIDAD_ESPACIOS_CANTIDAD,servicio->cantidad,-CANTIDAD_ESPACIOS_TIPO,servicio->tipo,-CANTIDAD_ESPACIOS_TOTAL_DEL_SERVICIO,servicio->totalServicio);
	}
	return devuelve;
}

int mostrarTodosLosServicio(LinkedList* this)
{

	int devuelve;
	devuelve=0;
	if(this!=NULL)
	{
		int tam;
		int i;
		devuelve=1;
		eServicios* pServicio=Servicios_new();

		tam=ll_len(this);

		printf("\n----------------------------------------------------------------------------------------------------------------\n");
		printf("|%*s|%*s|%*s|%*s|%*s|%*s|\n",-CANTIDAD_ESPACIOS_ID,"ID",-CANTIDAD_ESPACIOS_DESCRIPCION,"DESCRIPCION",-CANTIDAD_ESPACIOS_PRECIO_UNITARIO,"PRECIO UNITARIO",-CANTIDAD_ESPACIOS_CANTIDAD,"CANTIDAD",-CANTIDAD_ESPACIOS_TIPO,"TIPO",-CANTIDAD_ESPACIOS_TOTAL_DEL_SERVICIO,"PRECIO TOTAL DEL SERVICIO");
		printf("----------------------------------------------------------------------------------------------------------------\n");
		for(i=0;i<tam;i++)
		{
			pServicio=ll_get(this,i);
			mostrarServicio(pServicio);
		}
		free(pServicio);
	}
	return devuelve;
}

//---------------------------------------------------------FIN FUNCIONES PARA MOSTRAR------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



void calcularPrecioFinal(void* elemento)
{
	eServicios* p;
    if(elemento != NULL)
    {
    	p=(eServicios*) elemento;
        p->totalServicio = p->precioUnitario*p->cantidad;
    }

}

int compararDescripcionServicios(void* primerElemento, void* segundoElemento)
{
	int devuelve;
	devuelve=0;

	if(primerElemento!=NULL&& segundoElemento!=NULL)
	{
		eServicios* primerServicio=Servicios_new();
		eServicios* segundoServicio=Servicios_new();
		primerServicio=(eServicios*) primerElemento;
		segundoServicio=(eServicios*) segundoElemento;

		devuelve=strcmp(primerServicio->descripcion,segundoServicio->descripcion);
	}

	return devuelve;
}



//---------------------------------------------------------FUNCIONES PARA GUARDAR EN ARCHIVO-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int saveServicioFiltradoArchivo(FILE* pFile, LinkedList* this)
{
	int devuelve;

	devuelve=0;

	if(this!=NULL&& pFile!=NULL)
	{
		int tam;
		eServicios* servicioGuardar=Servicios_new();
		devuelve=1;
		tam=ll_len(this);
		fprintf(pFile,"id_servicio,descripcion,tipo,precioUnitario,cantidad,totalServicio\n");
		for(int i=0;i<tam;i++)
		{
			servicioGuardar=ll_get(this,i);
			fprintf(pFile,"%d,%s,%f,%d,%d,%f\n",
					servicioGuardar->id_servicio,servicioGuardar->descripcion,servicioGuardar->precioUnitario,servicioGuardar->cantidad,servicioGuardar->tipo,servicioGuardar->totalServicio);
		}
		free(servicioGuardar);
	}
	return devuelve;
}

//---------------------------------------------------------FIN FUNCIONES PARA GUARDAR EN ARCHIVO-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

