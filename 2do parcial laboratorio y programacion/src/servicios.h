/*
 * servicios.h
 *
 *  Created on: 21 jun. 2022
 *      Author: Usuario
 */

#ifndef SERVICIOS_H_
#define SERVICIOS_H_


#define CARACTERES 100
#define CANTIDAD_ESPACIOS_ID 10
#define CANTIDAD_ESPACIOS_DESCRIPCION 30
#define CANTIDAD_ESPACIOS_PRECIO_UNITARIO 20
#define CANTIDAD_ESPACIOS_TIPO 5
#define CANTIDAD_ESPACIOS_TOTAL_DEL_SERVICIO 30
#define CANTIDAD_ESPACIOS_CANTIDAD 10

typedef struct
{
	int id_servicio;
	char descripcion[CARACTERES];
	float precioUnitario;
	int tipo;
	float totalServicio;
	int cantidad;

}eServicios;

/**
 * @fn eServicios Servicios_new*()
 * @brief crea una estructura de tipo eServicios en memoria dinamica.
 *
 * @return retorna un puntero a la estructura de tipo eServicios creada en memoria dinamica.
 */
eServicios* Servicios_new();

/**
 * @fn eServicios Servicios_newParametros*(char*, char*, char*, char*, char*, char*)
 * @brief crea una estructura de tipo eServicios en memoria dinamica, dandole un valor acada campo.
 *
 * @param idStr: array de char donde esta ubicado el valor del capo id_servicio del servicio.
 * @param descripcionStr: array de char donde esta ubicado el valor del campo descripcion del servicio.
 * @param precioUnitarioStr: array de char donde esta ubicado el valor del campo precioUnitario del servicio.
 * @param tipoServicioStr: array de char donde esta ubicado el valor del campo tipo del servicio.
 * @param cantidadStr: array de char donde esta ubicado el valor del campo cantidad del servicio.
 * @param servicioTotalStr: array de char donde esta ubicado el valor del campo totalServicio del servicio.
 * @return retorna un puntero a la estructura de tipo eServicios creada en memoria dinamica.
 */
eServicios* Servicios_newParametros(char* idStr,char* descripcionStr,char* precioUnitarioStr,char* tipoServicioStr,char* cantidadStr, char* servicioTotalStr);

//---------------------------------------------------------FUNCIONES GET AND SET------------------------------------------------------------------------------

/**
 * @fn int Servicios_setId(eServicios*, int)
 * @brief guarda el valor del campo ID de un servicio.
 *
 * @param this: puntero a tipo eServicios del servicio que se desea guardar el id.
 * @param id: ID a guardar.
 * @return: devuelve 0 si el puntero viene en NULL, sino devuelve 1.
 */
int Servicios_setId(eServicios* this,int id);

/**
 * @fn int Servicios_getId(eServicios*, int*)
 * @brief busca cual es el ID de un servicio.
 *
 * @param this: puntero a tipo eServicios del servicio que se desea saber su ID.
 * @param id: puntero de tipo int donde se guardara el ID del servicio anteriormente buscado.
 * @return devuelve 0 si cualquiera de los 2 punteros vienen en NULL, sino devuelve 1-
 */
int Servicios_getId(eServicios* this,int* id);


/**
 * @fn int Servicios_setDescripcion(eServicios*, char*)
 * @brief guarda el valor del campo descripcion de un servicio.
 *
 * @param this: puntero a tipo eServicios del servicio donde se desea guardar la descripcion.
 * @param descripcion: descripcion a guardar.
 * @return: devuelve 0 si cualquiera de los 2 punteros vienen en NULL, sino devuelve 1.
 */
int Servicios_setDescripcion(eServicios* this,char* descripcion);

/**
 * @fn int Servicios_getDescripcion(eServicios*, char*)
 * @brief busca cual es el descripcion de un servicio.
 *
 * @param this: puntero a tipo eServicios del servicio que se desea saber su descripcion.
 * @param descripcion: array de char donde se guardara la descripcion del servicio anteriormente buscado.
 * @return devuelve 0 si cualquiera de los 2 punteros vienen en NULL, sino devuelve 1.
 */
int Servicios_getDescripcion(eServicios* this,char* descripcion);


/**
 * @fn int Servicios_setTipo(eServicios*, int)
 * @brief guarda el valor del campo tipo de un servicio.
 *
 * @param this: puntero a tipo eServicios del servicio que se desea guardar el tipo.
 * @param tipoServicio: tipo a guardar.
 * @return: devuelve 0 si el puntero viene en NULL, sino devuelve 1.
 */
int Servicios_setTipo(eServicios* this,int tipoServicio);

/**
 * @fn int Servicios_getTipo(eServicios*, int*)
 * @brief busca cual es el tipo de un servicio.
 *
 * @param this: puntero a tipo eServicios del servicio que se desea saber su tipo.
 * @param tipoServicio: puntero de tipo int donde se guardara el tipo del servicio anteriormente buscado.
 * @return devuelve 0 si cualquiera de los 2 punteros vienen en NULL, sino devuelve 1.
 */
int Servicios_getTipo(eServicios* this,int* tipoServicio);


/**
 * @fn int Servicios_setPrecioUnitario(eServicios*, float)
 * @brief guarda el valor del campo precioUnitario de un servicio.
 *
 * @param this: puntero a tipo eServicios del servicio que se desea guardar el precio unitario.
 * @param precio: precio unitario a guardar.
 * @return: devuelve 0 si el puntero viene con NULL, sino devuelve 1.
 */
int Servicios_setPrecioUnitario(eServicios* this,float precio);

/**
 * @fn int Servicios_getPrecioUnitario(eServicios*, float*)
 * @brief busca cual es el precio unitario de un servicio.
 *
 * @param this: puntero a tipo eServicios del servicio que se desea saber su precio unitario.
 * @param precio: puntero a float donde se guardara el precio unitario del servicio anteriormente buscado.
 * @return devuelve 0 si cualquiera de los 2 punteros vienen en NULL, sino devuelve 1.
 */
int Servicios_getPrecioUnitario(eServicios* this,float* precio);


/**
 * @fn int Servicios_setCantidad(eServicios*, int)
 * @brief guarda el valor del campo cantidad de un servicio.
 *
 * @param this: puntero a tipo eServicios del servicio que se desea guardar el tipo.
 * @param cantidad: cantidad a guardar.
 * @return: devuelve 0 si el puntero viene en NULL, sino devuelve 1.
 */
int Servicios_setCantidad(eServicios* this,int cantidad);

/**
 * @fn int Servicios_getCantidad(eServicios*, int*)
 * @brief busca cual es el cantidad de un servicio.
 *
 * @param this: puntero a tipo eServicios del servicio que se desea saber su cantidad.
 * @param cantidad: puntero de tipo int donde se guardara el cantidad del servicio anteriormente buscado.
 * @return devuelve 0 si cualquiera de los 2 punteros vienen en NULL, sino devuelve 1.
 */
int Servicios_getCantidad(eServicios* this,int* cantidad);


/**
 * @fn int Servicios_setServicioTotal(eServicios*, float)
 * @brief guarda el valor del campo servicioTotal de un servicio.
 *
 * @param this: puntero a tipo eServicios del servicio que se desea guardar el precio del servicio total.
 * @param servicioTotal: precio del servicio total a guardar.
 * @return: devuelve 0 si el puntero viene con NULL, sino devuelve 1.
 */
int Servicios_setServicioTotal(eServicios* this,float servicioTotal);

/**
 * @fn int Servicios_getServicioTotal(eServicios*, float*)
 * @brief busca cual es el precio del servicio total de un servicio.
 *
 * @param this: puntero a tipo eServicios del servicio que se desea saber su precio del servicio total.
 * @param servicioTotal: puntero a float donde se guardara el precio del servicio total del servicio anteriormente buscado.
 * @return devuelve 0 si cualquiera de los 2 punteros vienen en NULL, sino devuelve 1.
 */
int Servicios_getServicioTotal(eServicios* this,float* servicioTotal);

//---------------------------------------------------------FUNCIONES PARA FILTRAR-----------------------------------------------------------------------------

/**
 * @fn int filtrarPorMinorista(void*)
 * @brief cachea si el valor del campo tipo de un servicio es minorista(1).
 *
 * @param elemento: elemento proveniente de una linkedlist.
 * @return devuelve 0 si el elemnto es null o si el valor del campo tipo es diferente a 1, sino devuelve 1.
 */
int filtrarPorMinorista(void* elemento);

/**
 * @fn int filtrarPorMayoristas(void*)
 * @brief cachea si el valor del campo tipo de un servicio es mayorista(2).
 *
 * @param elemento: elemento proveniente de una linkedlist.
 * @return devuelve 0 si el elemnto es null o si el valor del campo tipo es diferente a 2, sino devuelve 1.
 */
int filtrarPorMayoristas(void* elemento);

/**
 * @fn int filtrarPorExportar(void*)
 * @brief cachea si el valor del campo tipo de un servicio es exportar(3).
 *
 * @param elemento: elemento proveniente de una linkedlist.
 * @return devuelve 0 si el elemnto es null o si el valor del campo tipo es diferente a 3, sino devuelve 1.
 */
int filtrarPorExportar(void* elemento);

//---------------------------------------------------------FIN FUNCIONES PARA FILTRAR-------------------------------------------------------------------------


//---------------------------------------------------------FUNCIONES PARA MOSTRAR-----------------------------------------------------------------------------

/**
 * @fn int mostrarServicio(eServicios*)
 * @brief muestra en la consola el valor de los campo de una estructura eServicios.
 *
 * @param servicio: puntero a estructura de tipo eServicios cuales sus campos se mostrara por consola.
 * @return devuelve 0 si el punteros vienen en NULL, sino devuelve 1.
 */
int mostrarServicio(eServicios* servicio);

/**
 * @fn int mostrarServicio(LinkedList*)
 * @brief realiza una lista mostrando todos los valores de los campos de las estructura eServicios que estan en una linkedlist.
 *
 * @param this: puntero a estructura de tipo LinkedLis.
 * @return devuelve 0 si el puntero viene en NULL, sino devuelve 1.
 */
int mostrarTodosLosServicio(LinkedList* this);

//---------------------------------------------------------FIN FUNCIONES PARA MOSTRAR-------------------------------------------------------------------------


/**
 * @fn void calcularPrecioFinal(void*)
 * @brief calcula el valor del campo totalServicio multiplicando los valores de los campo cantidad por precioUnitario del mismo servicio.
 *
 * @param elemento: elemento proveniente de una linkedlist.
 */
void calcularPrecioFinal(void* elemento);


/**
 * @fn int compararDescripcionServicios(void*, void*)
 * @brief compara 2 strings
 *
 * @param primerElemento: primer elemento proveniente de una linkedlist para comparar.
 * @param segundoElemento: segundo elemento proveniente de la misma linkedlist a comparar.
 * @return devuelve 0 si ambos  punteros vienen en NULL, >0 si el primero es mayor que el segundo o <0 si el primero es menor que el segundo.
 */
int compararDescripcionServicios(void* primerElemento, void* segundoElemento);


//---------------------------------------------------------FUNCIONES PARA GUARDAR EN ARCHIVO------------------------------------------------------------------

/**
 * @fn int saveServicioFiltradoArchivo(FILE*, LinkedList*)
 * @brief guarda los elementos de una linkedlist dentro de un archivo.
 *
 * @param pFile: puntero al archivo donde se queire guardar los elementos de la linkedlist.
 * @param this: puntero a la linkedlist cuyos elemtos se guardaran en el archivo.
 * @return devuelve 0 si ambos punteros vienen en NULL, sino devuelve 1.
 */
int saveServicioFiltradoArchivo(FILE* pFile, LinkedList* this);

//---------------------------------------------------------FIN FUNCIONES GUARDAR EN ARCHIVO-------------------------------------------------------------------

#endif /* SERVICIOS_H_ */
