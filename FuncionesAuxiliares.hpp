#pragma once

/** \file
*/

#include <iostream>
#include "OperacionesMatrices.hpp"

/**
* \brief Crea un arreglo din&aacute;mico de dos dimensiones usando un puntero a puntero entero (tipo del arreglo) que apunta al arreglo blanco.
*
* \param m Renglones del arreglo 2D (tama&ntilde;o de arreglo de punteros).
* \param n Columnas del arreglo 2D (tama&ntilde;o de los arreglos blanco).
* \return Un puntero a puntero entero.
*/
double** CrearArreglo2D(int m, int n);

/**
* \brief Destruye un arreglo din&aacute;mico de dos dimensiones de la estructura usando un puntero a puntero entero (tipo del arreglo) que apunta al arreglo blanco.
*
* \param arreglo El arreglo de dos dimensiones.
* \param m Columnas del arreglo 2D.
*/
void DestruirArreglo2D(double**& arreglo, int m);

/**
* \brief Detecta si el archivo ya contiene la extensi&oacute;n .txt.
*
* \param cadena Nombre del archivo.
* \return Un booleano, TRUE = contiene .txt, FALSE = no contiene .txt.
*/
bool DetectarExtension(char cadena[]);

/**
* \brief Captura las dimensiones m (rengl&oacute;n) y n (columna) de la matriz.
*
* \param m Rengl&oacute;n
* \param n Columna.
*/
void CapturarDimensiones(int& m, int& n);

/**
* \brief Nombra un archivo .txt .
* \return Un string del nombre del archivo .txt.
*
*/
string NombrarArchivo();

/** \brief Calcula el valor absoluto de un n&uacute;mero real.
* \param valor Un n&uacute;mero real.
* \return El valor absoluto de un n&uacute;mero real.
*/
double ValorAbsoluto(double valor);