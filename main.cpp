#include <iostream>
#include <cstdlib>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::setw;

#define MAX_REN 20
#define MAX_COL 30

enum operaciones {SUMA =1, RESTA, PROD_ESCALAR, TRANSPUESTA, INVERSA, MULTIPLICACION};

void ImprimirMatriz(double matriz[][MAX_COL], int m, int n);
void CapturarMatriz(double matriz[][MAX_COL], int m, int n);
void SumaMatriz(const double matrizA[][MAX_COL], const double matrizB[][MAX_COL], double matrizR[][MAX_COL], int m, int n);
void RestaMatriz(const double matrizA[][MAX_COL], const double matrizB[][MAX_COL], double matrizR[][MAX_COL], int m, int n);

int main()
{
    double matrizA[MAX_REN][MAX_COL] = {};
    double matrizB[MAX_REN][MAX_COL] = {};
    double matrizR[MAX_REN][MAX_COL] = {};

    int mA, nA, mB,nB,opUser;
    opUser = 3;
    cout << "MATRIZ A" << endl;
    do {
        cout << "Numero de renglones: ";
        cin >> mA;
    } while (mA < 1 || mA > MAX_REN);


    do {
        cout << "Numero de columnas: ";
        cin >> nA;
    } while (nA < 1 || nA > MAX_COL);

    cout << "Capturar matriz A:\n";
    CapturarMatriz(matrizA, mA, nA);
    ImprimirMatriz(matrizA, mA, nA);
  
    cout << "MATRIZ B" << endl;
    do {
        cout << "Numero de renglones: ";
        cin >> mB;
    } while (mB < 1 || mB > MAX_REN);


    do {
        cout << "Numero de columnas: ";
        cin >> nB;
    } while (nB < 1 || nB > MAX_COL);

    cout << "Capturar matriz B:\n";
    CapturarMatriz(matrizB, mB, nB);
    ImprimirMatriz(matrizB, mB, nB);


    switch (opUser)
    {
      case SUMA:   
         
          cout << "\SUMA DE MATRICES\n" << endl;
          if (mA == mB && nA == nB)
          {
            ImprimirMatriz(matrizA, mA, nA);
            if (nA % 2 == 0) cout << setw((nA*5) - (nA + 1)) << "+" << endl;
            else cout << setw((nA * 5) - (nA + 1)-1) << "+" << endl;
            ImprimirMatriz(matrizB, mB, nB);
            SumaMatriz(matrizA, matrizB, matrizR, mA, nA);
            if (nA % 2 == 0) cout << setw((nA * 5) - (nA + 1)) << "=" << endl;
            else cout << setw((nA * 5) - (nA + 1) - 1) << "=" << endl;
            ImprimirMatriz(matrizR, mA, nA);
          }    
          else
          {
              cout << "Los dos arreglos no se pueden sumar.";
          }

      case RESTA:
          cout << "\RESTA DE MATRICES\n" << endl;
          if (mA == mB && nA == nB)
          {
              ImprimirMatriz(matrizA, mA, nA);
              if (nA % 2 == 0) cout << setw((nA * 5) - (nA + 1)) << "-" << endl;
              else cout << setw((nA * 5) - (nA + 1) - 1) << "-" << endl;
              ImprimirMatriz(matrizB, mB, nB);
              RestaMatriz(matrizA, matrizB, matrizR, mA, nA);
              if (nA % 2 == 0) cout << setw((nA * 5) - (nA + 1)) << "=" << endl;
              else cout << setw((nA * 5) - (nA + 1) - 1) << "=" << endl;
              ImprimirMatriz(matrizR, mA, nA);
          }
          else
          {
              cout << "Los dos arreglos no se pueden restar.";
          }

    }

    cout << "\n\n";
    system("pause");
    return 0;
}

void ImprimirMatriz(double matriz[][MAX_COL], int m, int n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << setw(5) << matriz[i][j];
        }
        cout << endl;
    }
}

void CapturarMatriz(double matriz[][MAX_COL], int m, int n)
{
    for (int i = 0; i < m; ++i)
    {
        cout << "Renglon " << i + 1 << endl;
        for (int j = 0; j < n; ++j)
        {
            cout << "Elemento [" << i + 1 << "][" << j + 1 << "]:";
            cin >> matriz[i][j];
        }
    }
}

void SumaMatriz(const double matrizA[][MAX_COL], const double matrizB[][MAX_COL], double matrizR[][MAX_COL],int m, int n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matrizR[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
}

void RestaMatriz(const double matrizA[][MAX_COL], const double matrizB[][MAX_COL], double matrizR[][MAX_COL], int m, int n)
{
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            matrizR[i][j] = matrizA[i][j] - matrizB[i][j];
        }
    }
}

