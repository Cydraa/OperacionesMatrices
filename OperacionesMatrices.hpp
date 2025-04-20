#pragma once

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <cmath>
#include "CapturaSegura.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::setprecision;
using std::fixed;

enum operaciones { SUMA = 1, RESTA, PROD_ESCALAR, MULTIPLICACION, TRANSPUESTA, INVERSA,  };

#define MAX_REN 5
#define MAX_COL 5

void ImprimirMatriz(double**& matriz, int m, int n);
void CapturarMatriz(double**& matriz, int m, int n);
void SumaMatriz(double**& matrizA, double**& matrizB, double**& matrizR, int m, int n);
void RestaMatriz(double**& matrizA, double**& matrizB, double**& matrizR, int m, int n);
void ProductoEscalar(double**& matriz, double escalar, int m, int n);
void MultiplicacionMatrices(double** m1, double** m2, double** matriz, int a, int b, int a2, int b2);
void TranspuestaMatriz(double** matriz, double** matrizT, int m, int n);
