/*
 * validaciones.h
 *
 *  Created on: 21 may. 2022
 *      Author: Usuario
 */

/**
 * @fn int UTN_getValidacionMaximoMinimo(int*, char*, char*, int, int);
 * @brief le pide al usuario un numero de tipo int y lo valida entre un maximo y un minimo.
 *
 * @param resultado: variable donde se guardara el numero ingresado por el usuario.
 * @param mensaje: el mensaje que se mostrara antes de que el usuario ingrese un dato.
 * @param mensajeError: el mensaje que se mostrara cuando el usuario ingrese un dato invalido.
 * @param minimo: el numero minimo por el cual se validara el dato ingresado.
 * @param maximo: el numero maximo por el cual se validara el dato ingresado.
 * @return devuelve 0.
 */
int getValidacionMaximoMinimo(int* resultado, char* mensaje,char* mensajeError, int minimo, int maximo);

/**
 * @fn int chearLetraint(char*, int);
 * @brief chequea si un string tiene letras ingresadas.
 *
 * @param array: array donde se encuentra el string.
 * @param tam: tamaño del array.
 * @return devuelve -1 si el array es invalido o el tamño es mayor a 0, devuelve 0 si no contiene letras o simbolos,
   y devuelve un numero mayor a 0 si contine alguna letra o simbolo.
 */
int chearLetraint(char* array, int tam);


int UTN_GetValor(char array[], int tam, char* mensaje, char* mensajeError, int conNumero);

int chequearArrayNumero(int tam, char* array, char* mensajeError);


int UTN_getValidacionMayorInt(int* resultado, char* mensaje,char* mensajeError, int numero);



#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_



#endif /* VALIDACIONES_H_ */
