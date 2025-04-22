#pragma once

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include "CapturaSegura.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::ofstream;

enum operaciones { 
	CAPTURAR_ARCHIVO = 1, 
	SUMA, 
	RESTA, 
	PROD_ESCALAR, 
	MULTIPLICACION, 
	TRANSPUESTA, 
	INVERSA,  };

#define MAX_REN 5
#define MAX_COL 5

void ImprimirMatriz(double**& matriz, int m, int n);
void CapturarMatriz(double**& matriz, int m, int n);
void CapturarMatrizArchivo(double** matriz, int m, int n, char nombreArchivo[]);
void InicializarMatrizCero(double**& matriz, int m, int n);
void SumaMatriz(double**& matrizA, double**& matrizB, double**& matrizR, int m, int n);
void RestaMatriz(double**& matrizA, double**& matrizB, double**& matrizR, int m, int n);
void ProductoEscalar(double**& matriz, double escalar, int m, int n);
void MultiplicacionMatrices(double** matrizA, double** matrizB, double** matrizR, int mA, int mB, int nB);
void TranspuestaMatriz(double** matriz, double** matrizT, int m, int n);

