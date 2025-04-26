#pragma once

/** \file
*/

#include "FuncionesAuxiliares.hpp"

/** OPCIONES DE CAPTURA */
enum opcionesCaptura {
	CONSOLA = 1,  /**< Capturar desde la consola */
	ARCHIVO  /**< Capturar desde un archivo .txt */
};

/** \brief Gestiona la captura a archivo de la matriz.
*
*/
void GestionarCapturaArchivo();

/** \brief Gestiona la operaci&oacute;n suma de matrices.
*
*/
void GestionarSuma();

/** \brief Gestiona la operaci&oacute;n resta de matrices.
*
*/
void GestionarResta();

/** \brief Gestiona la operaci&oacute;n del producto por un escalar de una matriz.
*
*/
void GestionarProdEscalar();

/** \brief Gestiona la operaci&oacute;n multiplicac&oacute;n de matrices.
*
*/
void GestionarMultiplicacion();

/** \brief Gestiona la operaci&oacute;n de calcular la transpuesta de una matriz.
*
*/
void GestionarTranspuesta();

/** \brief Gestiona la operaci&oacute;n de calcular la inversa de una matriz.
*
*/
void GestionarInversa();