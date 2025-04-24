#pragma once

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <string>
#include "CapturaSegura.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;
using std::ofstream;
using std::ifstream;
using std::string;

enum operaciones { 
	CAPTURAR_ARCHIVO = 1, 
	SUMA, 
	RESTA, 
	PROD_ESCALAR, 
	MULTIPLICACION, 
	TRANSPUESTA, 
	INVERSA  };

#define MAX_REN 5
#define MAX_COL 5
#define MAX_NOMBRE 52

void ImprimirMatriz(double** matriz, int m, int n);
void CapturarMatriz(double** matriz, int m, int n);
void ImprimirMatrizArchivo(double** matriz, int m, int n, string nombreArchivo);
void CapturarMatrizArchivo(double**& matriz, int &m, int &n, string nombreArchivo);
void InicializarMatrizCero(double** matriz, int m, int n);
void SumaMatriz(double** matrizA, double** matrizB, double** matrizR, int m, int n);
void RestaMatriz(double** matrizA, double** matrizB, double** matrizR, int m, int n);
void ProductoEscalar(double** matriz, double escalar, int m, int n);
void MultiplicacionMatrices(double** matrizA, double** matrizB, double** matrizR, int mA, int mB, int nB);
void TranspuestaMatriz(double** matriz, double** matrizT, int m, int n);

