#include "FuncionesAuxiliares.hpp"

double** CrearArreglo2D(int m, int n) // m = renglones, n = columnas
{
    //Construccion de un arreglo dinamico 2D tipo** CrearArreglo(int m, int n)
    double** arreglo = new double* [m];
    for (int i = 0; i < m; ++i)
    {
        arreglo[i] = new double[n] ;
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

bool DetectarExtension(char cadena[]) {
    int longitud = strlen(cadena);

    if (cadena[longitud - 4] != '.') return false;
    if (cadena[longitud - 4] == '.' && cadena[longitud - 3] == 't' && cadena[longitud - 2] == 'x' && cadena[longitud - 1] == 't') return true;

    return false;
}

void CapturarDimensiones(int& m, int& n)
{
    char solicitud[50];

    sprintf_s(solicitud, "N\243mero de renglones (enteros positivos <= %d) : ", MAX_REN);
    do {
        CapturaSegura(m, solicitud);
    } while (m < 1 || m > MAX_REN);

    sprintf_s(solicitud, "N\243mero de columnas (enteros positivos <= %d) : ", MAX_COL);
    do {
        CapturaSegura(n, solicitud);
    } while (n < 1 || n > MAX_COL);
}

string NombrarArchivo()
{
    char nombreArchivo[MAX_NOMBRE];

    do
    {
        cout << "\nIntroduzca el nombre del archivo (m\240ximo " << MAX_NOMBRE - 2 << " caracteres): ";
        cin >> nombreArchivo;
    } while (strlen(nombreArchivo) > 20);

    if (!(DetectarExtension(nombreArchivo)) || strlen(nombreArchivo) <= 4)
    {
        char extension[5] = { ".txt" };
        strcat_s(nombreArchivo, extension);
    }

    return nombreArchivo;
}

double ValorAbsoluto(double valor) {
    if (valor < 0) return -valor;
    else return valor;
}