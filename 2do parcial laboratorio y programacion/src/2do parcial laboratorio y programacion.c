#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "servicios.h"
#include "UTN.h"

/*--------------------------------------------------------------------------------------------------------------------------------------------
 Se dispone de un archivo con datos acerca de los servicios de un taller de costura, que tiene el siguiente formato:
 id_servicio, descripción (del servicio), tipo (1-MINORISTA, 2-MAYORISTA, 3-EXPORTAR), precioUnitario, cantidad, totalServicio.

 por ejemplo: 50,ruedo pantalon,1,250,2,0
 	 	 	  51,ensamble vestido,2,860,25,0
			  52,costura correa mochila,3,450.25,60,0

 Se deberá realizar un programa que permita el análisis de dicho archivo y sea capaz de generar nuevos archivos de salida de formato
 similar filtrados por varios criterios:
 El programa contará con el siguiente menú:

 1) Cargar archivo: Se pedirá el nombre del archivo y se cargará en un linkedlist los elementos del mismo.
 2) Imprimir lista: Se imprimirá por pantalla la tabla con los datos de los servicios.
 3) Asignar totales: Se deberá hacer uso de la función map la cual recibirá el linkedlist y una función que asignará a cada servicio
 el total calculado de la siguiente forma: cantidad x totalServicio.
 4) Filtrar por tipo: Se deberá generar un archivo igual al original, pero donde solo aparezcan servicios del tipo seleccionado.
 5) Mostrar servicios: Se deberá mostrar por pantalla un listado de los servicios ordenados por descripción de manera ascendente.
 6) Guardar servicios: Se deberá guardar el listado del punto anterior en un archivo de texto.
 7) Salir.
---------------------------------------------------------------------------------------------------------------------------------------------*/

int main()
{
	setbuf(stdout, NULL);
    int option = 0;
    int chequeo;
    int archivoFlag = 0;

    LinkedList* listaServicios = ll_newLinkedList();
    do{
    	UTN_getValidacionMaximoMinimo(&option,"\nIngrese un numero \n"
					" 1. Cargar archivo\n"
					" 2. Imprimir lista\n"
					" 3. Asignar totales\n"
					" 4. Filtrar por tipo\n"
					" 5. Mostrar servicios\n"
					" 6. Guardar servicios\n"
					" 7. Salir ", "\nERROR, Reingrese un numero valido(1-7)\n"
									" 1. Cargar archivo\n"
									" 2. Imprimir lista\n"
									" 3. Asignar totales\n"
									" 4. Filtrar por tipo\n"
									" 5. Mostrar servicios\n"
									" 6. Guardar servicios\n"
									" 7. Salir ", 1, 7);
        switch(option)
        {
            case 1:
            	if(archivoFlag==0)
            	{
            		controller_loadFromText("data.csv",listaServicios);
            		archivoFlag=1;
            	}
            	else
            	{
            		printf("\nYa has cargado el archivo anteriormente\n");
            	}
            break;

           case 2:
            	if(archivoFlag==1)
				{
            		controller_ListServicios(listaServicios);
				}
				else
				{
					printf("\nDebes de cargar el archivo antes\n");
				}
            break;

            case 3:
            	if(archivoFlag==1)
            	{
            		chequeo=controller_AsignacionTotalServicio(listaServicios);
            		if(chequeo==0)
            		{
            			printf("\nNo se pudo asignar los valores totales\n");
            		}
            		else
					{
            			printf("\nLos valores totales han sido asignados\n");
					}
            	}
            	else
            	{
            		printf("\nDebes de cargar el archivo antes\n");
            	}
            break;

           case 4:
            	if(archivoFlag==1)
				{
            		controller_FiltrarServicios(listaServicios);
				}
				else
				{
					printf("\nDebes de cargar el archivo antes\n");
				}
		    break;

		    case 5:
		    	if(archivoFlag==1)
				{
		    		controller_sortServicios(listaServicios);
				}
				else
				{
					printf("\nDebes de cargar el archivo antes\n");
				}
		    break;

		    case 6:
		    	if(archivoFlag==1)
				{
		    		controller_saveAsText("data.csv",listaServicios);
				}
				else
				{
					printf("\nDebes de cargar el archivo antes\n");
				}
			break;
        }
    }while(option != 7);
    ll_deleteLinkedList(listaServicios);
    return 0;
}

