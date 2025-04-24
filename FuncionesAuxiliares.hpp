#pragma once

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

bool DetectarExtension(char cadena[]);
void CapturarDimensiones(int& m, int& n);
string NombrarArchivo();