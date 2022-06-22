/*
 * Controller.h
 *
 *  Created on: 21 jun. 2022
 *      Author: Usuario
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_


int controller_loadFromText(char* path , LinkedList* pArrayListServicios);
/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger);
int controller_editPassenger(LinkedList* pArrayListPassenger);
int controller_AsignacionTotalServicio(LinkedList* pArrayListServicios);
int controller_ListServicios(LinkedList* pArrayListServicios);
int controller_sortPassenger(LinkedList* pArrayListPassenger);
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger);
int controller_FiltrarServicios(LinkedList* pArrayListServicios);
int controller_sortServicios(LinkedList* pArrayListServicios);
int controller_saveAsText(char* path , LinkedList* pArrayListServicios);




#endif /* CONTROLLER_H_ */
