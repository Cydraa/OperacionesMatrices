#include "OperacionesMatrices.hpp"

void ImprimirMatriz(double** matriz, int m, int n)
{
    cout << char(218);
    for (int i = 0; i < n; ++i) cout << setw(6) << "";
    cout << setw(n*2+4) << char(191) << endl;

    for (int i = 0; i < m; ++i)
    {
        cout << char(179);
        for (int j = 0; j < n; ++j)
        {
            cout << setw(8) << fixed << setprecision(3) << matriz[i][j];
        }
        cout << setw(3) << "" << char(179) << endl;
    }

    cout << char(192);
    for (int i = 0; i < n; ++i) cout << setw(6) << "";
    cout << setw(n*2+4) << char(217) << endl;

}

void CapturarMatriz(double** matriz, int m, int n)
{
    char solicitud[50];
    for (int i = 0; i < m; ++i)
    {
        cout << "Rengl\242n " << i + 1 << endl;

        for (int j = 0; j < n; ++j)
        {
            sprintf_s(solicitud, "Elemento [ %d ][ %d ]:", i + 1, j + 1);
            CapturaSegura(matriz[i][j], solicitud);
        }

        cout << endl;
    }
}

void ImprimirMatrizArchivo(double** matriz, int m, int n, string nombreArchivo)
{
    ofstream salida;
    salida.open(nombreArchivo);

    salida << m << "\t" << n << endl;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            salida << fixed << setprecision(3) << matriz[i][j] << "\t";
        }

        salida << endl;
    }
    salida.close();
    cout << "\nLa matriz se imprimi\242 exitosamente en el archivo: " << nombreArchivo << "\n" << endl;
}

void CapturarMatrizArchivo(double**& matriz, int &m, int &n, string nombreArchivo)
{
    ifstream entrada;
    entrada.open(nombreArchivo);
    entrada >> m >> n;

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            entrada >> matriz[i][j];
        }
    }

    entrada.close();
}

void InicializarMatrizCero(double** matriz, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = 0;
        }
    }
}

void SumaMatriz(double** matrizA, double** matrizB, double** matrizR, int m, int n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matrizR[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
}

void RestaMatriz(double** matrizA, double** matrizB, double** matrizR, int m, int n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matrizR[i][j] = matrizA[i][j] - matrizB[i][j];
        }
    }
}

void ProductoEscalar(double** matriz, double escalar, int m, int n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matriz[i][j] *= escalar;
        }
    }
}

void MultiplicacionMatrices(double** matrizA, double** matrizB, double** matrizR, int mA, int mB, int nB) 
{
    for (int i = 0; i < mA; ++i)
    {
        for (int j = 0; j < nB; ++j)
        {
            for (int k = 0; k < mB; ++k)
            {
                matrizR[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

void TranspuestaMatriz(double** matriz, double** matrizT, int m, int n) 
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrizT[j][i] = matriz[i][j];
        }
    }
}