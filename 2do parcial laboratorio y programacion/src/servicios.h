/*
 * servicios.h
 *
 *  Created on: 21 jun. 2022
 *      Author: Usuario
 */

#ifndef SERVICIOS_H_
#define SERVICIOS_H_


#define CARACTERES 100

typedef struct
{
	int id_servicio;
	char descripcion[CARACTERES];
	float precioUnitario;
	int tipo;
	float totalServicio;
	int cantidad;

}eServicios;

eServicios* Servicios_new();
eServicios* Servicios_newParametros(char* idStr,char* descripcionStr,char* precioUnitarioStr,char* tipoServicioStr,char* cantidadStr, char* servicioTotalStr);

int Servicios_setId(eServicios* this,int id);
int Servicios_getId(eServicios* this,int* id);

int Servicios_setDescripcion(eServicios* this,char* nombre);
int Servicios_getDescripcion(eServicios* this,char* nombre);

int Servicios_setTipo(eServicios* this,int tipoServicio);
int Servicios_getTipo(eServicios* this,int* tipoServicio);

int Servicios_setPrecioUnitario(eServicios* this,float precio);
int Servicios_getPrecioUnitario(eServicios* this,float* precio);

int Servicios_setCantidad(eServicios* this,int cantidad);
int Servicios_getCantidad(eServicios* this,int* cantidad);

int Servicios_setServicioTotal(eServicios* this,float servicioTotal);
int Servicios_getServicioTotal(eServicios* this,float* servicioTotal);


int mostrarServicio(eServicios* servicio);
void calcularPrecioFinal(void* elemento);
int filtrarPorMinorista(void* elemento);
int filtrarPorMayoristas(void* elemento);
int filtrarPorExportar(void* elemento);
int saveServicioFiltradoArchivo(FILE* pFile, LinkedList* this);
int compararDescripcionServicios(void* primerElemento, void* segundoElemento);
int mostrarTodosLosServicio(LinkedList* this);


#endif /* SERVICIOS_H_ */
