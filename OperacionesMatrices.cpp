#include "OperacionesMatrices.hpp"

void ImprimirMatriz(double**& matriz, int m, int n)
{
    cout << char(218);
    for (int i = 0; i < n; ++i) cout << setw(5) << "";
    cout << setw(3) << char(191) << endl;

    for (int i = 0; i < m; ++i)
    {
        cout << char(179);
        for (int j = 0; j < n; ++j)
        {
            cout << setw(5) << fixed << setprecision(1) << matriz[i][j];
        }
        cout << setw(2) << "" << char(179) << endl;
    }

    cout << char(192);
    for (int i = 0; i < n; ++i) cout << setw(5) << "";
    cout << setw(3) << char(217) << endl;

}

void CapturarMatriz(double**& matriz, int m, int n)
{
    char solicitud[50];
    for (int i = 0; i < m; ++i)
    {
        cout << "Renglon " << i + 1 << endl;

        for (int j = 0; j < n; ++j)
        {
            sprintf_s(solicitud, "Elemento [ %d ][ %d ]:", i + 1, j + 1);
            CapturaSegura(matriz[i][j], solicitud);
        }

        cout << endl;
    }
}

void SumaMatriz(double**& matrizA, double**& matrizB, double**& matrizR, int m, int n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matrizR[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
}

void RestaMatriz(double**& matrizA, double**& matrizB, double**& matrizR, int m, int n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matrizR[i][j] = matrizA[i][j] - matrizB[i][j];
        }
    }
}

void ProductoEscalar(double**& matriz, double escalar, int m, int n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matriz[i][j] *= escalar;
        }
    }
}

void MultiplicacionMatrices(double** m1, double** m2, double**matriz, int a, int b, int a2, int b2) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            for (int k = 0; k < b2; k++) {
                matriz[i][j] += m1[i][k] * m2[k][j];
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