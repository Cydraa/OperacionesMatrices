#include "FuncionesAuxiliares.hpp"

double** CrearArreglo2D(int m, int n) // m = renglones, n = columnas
{
    //Construccion de un arreglo dinamico 2D tipo** CrearArreglo(int m, int n)
    double** arreglo = new double* [m];
    for (int i = 0; i < m; ++i)
    {
        arreglo[i] = new double[n];
    }

    return arreglo;
}

void DestruirArreglo2D(double**& arreglo, int m)
{
    //Liberar arreglo dinamico void DestruirArreglo(tipo** &arreglo, int m)
    for (int i = 0; i < m; ++i)
    {
        delete[] arreglo[i];
    }
    delete[] arreglo;

    arreglo = NULL;  // Si ya no se va a usar
}