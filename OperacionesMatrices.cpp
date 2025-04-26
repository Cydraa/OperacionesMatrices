#include "FuncionesAuxiliares.hpp"

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
            salida << fixed << setprecision(4) << matriz[i][j] << "\t";
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

bool InvertirMatriz(double** m1, int a, double** Inversa) {
    // Crear matriz aumentada [original|identidad]
    double** MatrizAumentrada = CrearArreglo2D(a, 2 * a);
    InicializarMatrizCero(MatrizAumentrada, a, 2*a);
    DuplicarMatriz(m1, MatrizAumentrada, a);

    // Inicializar la parte de la identidad
    for (int i = 0; i < a; i++) {
        MatrizAumentrada[i][a + i] = 1.0;
    }

    // Aplicar eliminación de Gauss-Jordan
    for (int pivot = 0; pivot < a; pivot++) {
        TempPivote(MatrizAumentrada, a, pivot);

        // Si el pivote es cero después del pivoteo, la matriz no es invertible
        if (MatrizAumentrada[pivot][pivot] == 0) {
            return false;
        }

        Identizar(MatrizAumentrada, a, pivot);
        hacerCero(MatrizAumentrada, a, pivot);
    }

    // Extraer la matriz inversa (parte derecha de la matriz aumentada)

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            Inversa[i][j] = MatrizAumentrada[i][a + j];
        }
    }

    DestruirArreglo2D(MatrizAumentrada, a);
    return true;
}

double* copiar_renglon(double** m1, int a, int renglon) {
    double* renglon_auxilar = new double[a];

    for (int i = 0; i < a; i++) {
        renglon_auxilar[i] = m1[renglon][i];
    }

    return renglon_auxilar;
}

void CambioRenglon(double** m1, int a, int renglon_1, int renglon_2) {

    for (int j = 0; j < 2 * a; j++) {
        double temp = m1[renglon_1][j];
        m1[renglon_1][j] = m1[renglon_2][j];
        m1[renglon_2][j] = temp;
    }

}

void DuplicarMatriz(double** m1, double** m2, int a) {
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            m2[i][j] = m1[i][j];
        }
    }
}

void TempPivote(double** m1, int a, int pivote) {
    int maxRenglon = pivote;
    double maxValor = ValorAbsoluto(m1[pivote][pivote]);

    for (int i = pivote + 1; i < a; i++) {
        if (ValorAbsoluto(m1[i][pivote]) > maxValor) {
            maxValor = abs(m1[i][pivote]);
            maxRenglon = i;
        }
    }

    if (maxRenglon != pivote) {
        CambioRenglon(m1, a, pivote, maxRenglon);
    }
}

void Identizar(double** m1, int a, int pivote) {
    double tempPivote = m1[pivote][pivote];

    for (int i = pivote; i < 2 * a; i++) {
        m1[pivote][i] /= tempPivote;
    }
}

void hacerCero(double** m1, int a, int pivote) {
    for (int i = 0; i < a; i++) {
        if (i != pivote && m1[i][pivote] != 0) {
            double valor = m1[i][pivote];
            for (int j = pivote; j < 2 * a; j++) {
                m1[i][j] -= valor * m1[pivote][j];
            }
        }
    }
}