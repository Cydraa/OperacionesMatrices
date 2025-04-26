#pragma once

/** \file
*/

#include <iostream> // cout, cin, endl
#include <iomanip> // setw, setprecision, fixed
#include <stdio.h> // sprintf_s
#include <fstream> // ofstream,ifstream
#include <cstdlib> // system
#include <string> // string
#include "CapturaSegura.hpp" // CapturaSegura

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::ofstream;
using std::ifstream;
using std::string;

/** OPERACIONES DISPONIBLES */
enum operaciones { 
	CAPTURAR_ARCHIVO = 1,  /**< Capturar una matriz e imprimir a archivo */
	SUMA, /**< Suma de matrices */
	RESTA, /**< Resta de matrices */
	PROD_ESCALAR, /**< Producto de matriz por un escalar */
	MULTIPLICACION, /**< Multiplicaci&oacute;n de matrices */
	TRANSPUESTA, /**< Transpuesta de la matriz */
	INVERSA  /**< Inversa de la matriz */
};

#define MAX_REN 8 /**< Renglones m&aacute;ximos de la matriz */
#define MAX_COL 8 /**< Columnas m&aacute;ximas de la matriz */
#define MAX_NOMBRE 52 /**< Caracteres m&aacute;ximos del nombre del archivo */

//*********************************************************************************************************************//
// Operaciones de matrices//

/** \brief Imprime una matriz a consola.
* \param matriz Arreglo 2D de una matriz.
* \param m Rengl&oacute;n de una matriz.
* \param n Columna de una matriz.
*/
void ImprimirMatriz(double** matriz, int m, int n);

/** \brief Captura una matriz desde la consola.
* \param matriz Arreglo 2D de una matriz.
* \param m Rengl&oacute;n de una matriz.
* \param n Columna de una matriz.
*/
void CapturarMatriz(double** matriz, int m, int n);

/** \brief Imprime una matriz de la consola a un archivo .txt.
* \param matriz Arreglo 2D de una matriz.
* \param m Rengl&oacute;n de una matriz.
* \param n Columna de una matriz.
* \param nombreArchivo Nombre del archivo (incluyendo su extensi&oacute;n).
*/
void ImprimirMatrizArchivo(double** matriz, int m, int n, string nombreArchivo);

/** \brief Captura una matriz a consola desde un archivo .txt.
* \param matriz Arreglo 2D de una matriz.
* \param m Rengl&oacute;n de una matriz.
* \param n Columna de una matriz.
* \param nombreArchivo Nombre del archivo (incluyendo su extensi&oacute;n).
*/
void CapturarMatrizArchivo(double**& matriz, int &m, int &n, string nombreArchivo);

/** \brief Llena la matriz con 0.
* \param matriz Arreglo 2D de una matriz.
* \param m Rengl&oacute;n de una matriz.
* \param n Columna de una matriz.
*/
void InicializarMatrizCero(double** matriz, int m, int n);

/** \brief Suma dos matrices.
* \param matrizA Arreglo 2D de una matriz A.
* \param matrizB Arreglo 2D de una matriz B.
* \param matrizR Arreglo 2D de una matriz resultante.
* \param m Rengl&oacute;n de una matriz.
* \param n Columna de una matriz.
* \pre Los renglones y las columnas deben ser iguales: m = n
*/
void SumaMatriz(double** matrizA, double** matrizB, double** matrizR, int m, int n);

/** \brief Resta dos matrices.
* \param matrizA Arreglo 2D de una matriz A.
* \param matrizB Arreglo 2D de una matriz B.
* \param matrizR Arreglo 2D de una matriz resultante.
* \param m Rengl&oacute;n de una matriz.
* \param n Columna de una matriz.
* \pre Los renglones y las columnas deben ser iguales: m = n
*/
void RestaMatriz(double** matrizA, double** matrizB, double** matrizR, int m, int n);

/** \brief Multiplica una matriz por un escalar.
* \param matriz Arreglo 2D de una matriz.
* \param escalar Arreglo 2D de una matriz.
* \param m Rengl&oacute;n de una matriz.
* \param n Columna de una matriz.
*/
void ProductoEscalar(double** matriz, double escalar, int m, int n);

/** \brief Multiplica una matriz por una matriz.
* \param matrizA Arreglo 2D de una matriz A.
* \param matrizB Arreglo 2D de una matriz B.
* \param matrizR Arreglo 2D de una matriz resultante.
* \param mA Rengl&oacute;n de la matriz A.
* \param mB Rengl&oacute;n de la matriz B.
* \param nB Columna de una matriz B.
* \pre Las columnas de la matriz A deben ser iguales a los renglones de la matriz B : nA = mB
*/
void MultiplicacionMatrices(double** matrizA, double** matrizB, double** matrizR, int mA, int mB, int nB);

/** \brief Calcula la transpuesta de una matriz.
* \param matriz Arreglo 2D de una matriz.
* \param matrizT Arreglo 2D de una matriz transpuesta resultante.
* \param m Rengl&oacute;n de la matriz.
* \param n Rengl&oacute;n de la matriz.
*/
void TranspuestaMatriz(double** matriz, double** matrizT, int m, int n);

/** \brief Calcula la inversa de una matriz y regresa si es invertible o no.
* \param m1 Arreglo 2D de una matriz.
* \param a Rengl&oacute;n de la matriz.
* \param Inversa Arreglo 2D resultante de la matriz inversa.
* \return Booleano. TRUE = es invertible, FALSE = no es invertible.
*/
bool InvertirMatriz(double** m1, int a, double** Inversa);

//*********************************************************************************************************************//
// Operaciones de renglon//

/** \brief Copia el rengl&oacute;n de una matriz.
* \param m1 Arreglo 2D de una matriz.
* \param a Rengl&oacute;n de la matriz.
* \param renglon &Iacute;ndice del rengl&oacute;n.
* \return Regresa un puntero del rengl&oacute;n auxiliar (copia).
*/
double* copiar_renglon(double** m1, int a, int renglon);

/** \brief Intercambia los renglones de una matriz.
* \param m1 Arreglo 2D de una matriz.
* \param a Rengl&oacute;n de la matriz.
* \param renglon_1 &Iacute;ndice del rengl&oacute;n 1.
* \param renglon_2 &Iacute;ndice del rengl&oacute;n 2.
*/
void CambioRenglon(double** m1, int a, int renglon_1, int renglon_2);

/** \brief Realiza una copia de la matriz.
* \param m1 Arreglo 2D de una matriz fuente.
* \param m2 Arreglo 2D de una matriz destino.
* \param a  Rengl&oacute;n de la matriz.
*/
void DuplicarMatriz(double** m1, double** m2, int a);

/** \brief Encuentra el pivote de un rengl&oacute;n.
* \param m1 Arreglo 2D de una matriz fuente.
* \param a  Rengl&oacute;n de la matriz.
* \param pivote Pivote del rengl&oacute;n.
*/
void TempPivote(double** m1, int a, int pivote);

/** \brief Identiza el pivote de un rengl&oacute;n.
* \param m1 Arreglo 2D de una matriz fuente.
* \param a  Rengl&oacute;n de la matriz.
* \param pivote Pivote del rengl&oacute;n.
*/
void Identizar(double** m1, int a, int pivote);

/** \brief Determina los elementos que se deben de operar para llevar  a 0 elementos de otro rengl&oacute;n.
* \param m1 Arreglo 2D de una matriz fuente.
* \param a  Rengl&oacute;n de la matriz.
* \param pivote Pivote del rengl&oacute;n.
*/
void hacerCero(double** m1, int a, int pivote);

